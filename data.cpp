/**
  Sprite Editor Data Format
*/
/**
  File format.

  This is lettle endian.

  +---------------------+
  |"KNSP"               | 4byte
  +---------------------+
  | chunk size          | 4byte
  +---------------------+
  | Major version       | 1byte
  +---------------------+
  | Minor version       | 1byte
  +---------------------+
  | "PICT"              | 4byte
  +---------------------+
  | chunk size          | 4byte
  +---------------------+
  | texture name        | 0~texture name length byte(it has not zero termination)
  +---------------------+
  | "ANIM"              | 4byte
  +---------------------+
  | chunk size          | 4byte
  +---------------------+
  | Sheet count         | 4byte
  |+---------------------+
  || "SHEE"              |
  |+---------------------+
  || chunk size          | 4byte
  |+---------------------+
  || Chip count          | 4byte
  ||+---------------------+
  ||| Rect                | 16byte
  ||+---------------------+
  ||| Position            | 8byte
  ||+---------------------+
  ||| Center offset       | 8byte
  ||+---------------------+
  ||| Scale               | 8byte
  ||+---------------------+
  ||| Color               | 4byte
  ||+---------------------+
  ||| Angle               | 4byte
  ||+---------------------+
  ||| Flags               | 4byte
  ||+---------------------+
  ||| ...                 | x chip count
  |+---------------------+
  || Rect count          | 4byte
  ||+---------------------+
  ||| Rect                | 16byte
  ||+---------------------+
  ||| ...                 | x rect count
  |+---------------------+
  || ...                 | x chip count
  +---------------------+
  | ...                 | x sheet count
*/
#include "data.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <algorithm>

namespace SpriteEditor {

class Serializer {
public:
  explicit Serializer(const char* filename) : ofs_(filename, std::ios::out | std::ios::binary)
  {
  }

  template<typename T> void operator()(const T& x, size_t size) {
    ofs_.write(reinterpret_cast<const char*>(&x), std::min(sizeof(T), size));
  }
  void operator()(const char* str, size_t size) {
    ofs_.write(str, size);
  }

private:
  std::ofstream  ofs_;
};

class Deserializer {
public:
  explicit Deserializer(const char* filename) : ifs_(filename, std::ios::in | std::ios::binary)
  {
  }

  template<typename T> void operator()(T& x, size_t size) {
    char buf[32];
    ifs_.read(buf, size);
    uint64_t n = 0;
    for (size_t i = std::min(sizeof(T), size) - 1; i >= 0 ; --i) {
      n *= 0x100;
      n += buf[i];
    }
    x = *reinterpret_cast<const T*>(&n);
  }
  void operator()(char* str, size_t size) {
    ifs_.read(str, size);
  }

  bool IsEof() const { return ifs_.eof(); }

  size_t Current() { return ifs_.tellg(); }

  void Rewind(size_t size) {
    ifs_.seekg(-static_cast<std::streamoff>(size), std::ios_base::cur);
  }
  void Skip(size_t size) {
    ifs_.seekg(static_cast<std::streamoff>(size), std::ios_base::cur);
  }

private:
  std::ifstream  ifs_;
};

class SizeAccumulator {
public:
  SizeAccumulator() : size_(0) {}
  template<typename T> void operator()(const T&, size_t size) {
    size_ += size;
  }
  size_t Result() const { return size_; }
private:
  size_t  size_;
};

#define MakeId(a, b, c, d) ((a) + (b)*0x100 + (c)*0x10000 + (d)*0x1000000)

static const size_t chunkHeaderSize = 8;

struct ChunkHeader {
  uint32_t  id;
  size_t  size;
};

ChunkHeader ReadChunkHeader(Deserializer& ar)
{
  ChunkHeader  chunk;
  char id[4];
  ar(id, 4);
  chunk.id = MakeId(id[0], id[1], id[2], id[3]);
  ar(chunk.size, 4);
  return chunk;
}

template<typename Archive>
void Serialize(Archive& ar, Vector2& data, unsigned int) {
  ar(data.x, 4);
  ar(data.y, 4);
}

template<typename Archive>
void Serialize(Archive& ar, Point2& data, unsigned int) {
  ar(data.x, 4);
  ar(data.y, 4);
}

template<typename Archive>
void Serialize(Archive& ar, Rect& data, unsigned int) {
  ar(data.left, 4);
  ar(data.top, 4);
  ar(data.right, 4);
  ar(data.bottom, 4);
}

template<typename Archive>
void Serialize(Archive& ar, Color& data, unsigned int) {
  const uint8_t r = static_cast<uint8_t>(data.r * 255);
  ar(r, 1);
  const uint8_t g = static_cast<uint8_t>(data.g * 255);
  ar(g, 1);
  const uint8_t b = static_cast<uint8_t>(data.b * 255);
  ar(b, 1);
  const uint8_t a = static_cast<uint8_t>(data.a * 255);
  ar(a, 1);
}

template<>
void Serialize<Deserializer>(Deserializer& ar, Color& data, unsigned int) {
  uint8_t tmp;
  ar(tmp, 1);
  data.r = static_cast<Float>(tmp) / 255;
  ar(tmp, 1);
  data.g = static_cast<Float>(tmp) / 255;
  ar(tmp, 1);
  data.b = static_cast<Float>(tmp) / 255;
  ar(tmp, 1);
  data.a = static_cast<Float>(tmp) / 255;
}

template<typename Archive>
void Serialize(Archive& ar, Chip& data, unsigned int version) {
  Serialize(ar, data.rect, version);
  Serialize(ar, data.position, version);
  Serialize(ar, data.center, version);
  Serialize(ar, data.scale, version);
  Serialize(ar, data.color, version);
  ar(data.angle, 4);
  ar(data.flags, 4);
}

template<typename Archive>
void Serialize(Archive& ar, Sheet& data, unsigned int version) {
  ar("SHEE", 4);

  SizeAccumulator acc;
  for (auto i : data.chipList) {
    Serialize(acc, i, version);
  }
  for (auto i : data.rectList) {
    Serialize(acc, i, version);
  }
  ar(acc.Result() + 8, 4);

  ar(data.chipList.size(), 4);
  for (auto i : data.chipList) {
    Serialize(ar, i, version);
  }

  ar(data.rectList.size(), 4);
  for (auto i : data.rectList) {
    Serialize(ar, i, version);
  }
}

template<>
void Serialize<Deserializer>(Deserializer& ar, Sheet& data, unsigned int version) {
  const ChunkHeader chunk = ReadChunkHeader(ar);
  if (chunk.id != MakeId('S','H','E','E')) {
    ar.Rewind(chunkHeaderSize);
    return;
  }
  {
    size_t size;
    ar(size, 4);
    data.chipList.resize(size);
    for (auto i : data.chipList) {
      Serialize(ar, i, version);
    }
  }
  {
    size_t size;
    ar(size, 4);
    data.rectList.resize(size);
    for (auto i : data.rectList) {
      Serialize(ar, i, version);
    }
  }
}

template<typename Archive>
void Serialize(Archive& ar, Animation& data, unsigned int version) {
  ar("KNSP", 4);
  ar(2, 4);
  ar(version / 0x100, 1);
  ar(version & 0xff, 1);

  ar("PICT", 4);
  ar(data.textureName.size(), 4);
  ar(&data.textureName[0], data.textureName.size());

  ar("ANIM", 4);
  SizeAccumulator acc;
  for (auto i : data.sheetList) {
    Serialize(acc, i, version);
  }
  ar(acc.Result() + 4, 4);

  ar(data.sheetList.size(), 4);
  for (auto i : data.sheetList) {
    Serialize(ar, i, version);
  }
}

template<>
void Serialize<Deserializer>(Deserializer& ar, Animation& data, unsigned int version) {
  const ChunkHeader knspHeader = ReadChunkHeader(ar);
  if (knspHeader.id != MakeId('K','N','S','P')) {
    ar.Rewind(chunkHeaderSize);
    return;
  }
  int major;
  ar(major, 1);
  int minor;
  ar(minor, 1);
  data.version = major * 0x100 + minor;
  ar.Skip(knspHeader.size - 2);

  for (;!ar.IsEof();) {
    const ChunkHeader header = ReadChunkHeader(ar);
    switch(header.id) {
    case MakeId('P','I','C','T'):
      data.textureName.resize(header.size);
      ar(&data.textureName[0], header.size); 
      break;
    case MakeId('A','N','I','M'): {
      size_t count;
      ar(count, 4);
      data.sheetList.resize(count);
      for (auto i : data.sheetList) {
        Serialize(ar, i, version);
      }
      break;
    }
    default:
      ar.Skip(header.size);
      break;
    }
  }
}

bool LoadFromFile(const char* filename, Animation* animation)
{
  Serialize(Deserializer(filename), *animation, 0);
  return true;
}

bool SaveToFile(const char* filename, const Animation& animation)
{
  Serialize(Serializer(filename), const_cast<Animation&>(animation), 0);
  return true;
}

} // namespace SpriteEditor
