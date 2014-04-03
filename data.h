/**
  Sprite Editor Data Format.
*/
#ifndef SPRITEEDITOR_DATA_H_INCLUDED
#define SPRITEEDITOR_DATA_H_INCLUDED
#include <vector>

namespace SpriteEditor {

typedef int Int;
typedef float Float;
struct Rect;
struct Vector2;
struct Point2;
struct Chip;
struct Sheet;
struct SheetList;

/**
  2次元ベクトル.
*/
struct Vector2 {
  Float x, y;
  Vector2() : x(), y() {}
  Vector2(Float ax, Float ay) : x(ax), y(ay) {}
  explicit Vector2(const Point2&);
};

/**
  2次元座標.
*/
struct Point2 {
  Float x, y;
  Point2() : x(), y() {}
  Point2(Float ax, Float ay) : x(ax), y(ay) {}
  explicit Point2(const Vector2&);
};

/**
  矩形領域.
*/
struct Rect {
  Float left, top, right, bottom;
  Rect() : left(), top(), right(), bottom() {}
  explicit Rect(Float l, Float t, Float r, Float b) : left(l), top(t), right(r), bottom(b) {}
};

/**
  RGBAカラー.
*/
struct Color {
  Float r, g, b, a;
  Color() {}
  Color(Float ar, Float ag, Float ab, Float aa = 1) : r(ar), g(ag), b(ab), a(aa) {}
};

/**
  スプライト要素.
*/
struct Chip {
  Rect  rect;
  Point2 position;
  Vector2  center;
  Vector2  scale;
  Float  angle;
  Color  color;

  Chip() {}
  Chip(const Rect& r, const Point2& p, const Vector2& c, const Vector2& s, Float a = 0, const Color& col = Color(1, 1, 1, 1)) :
    rect(r),
    position(p),
    center(c),
    scale(s),
    angle(a),
    color(col)
  {}
};

/**
  スプライトシート.
  Chipを複数まとめたもの.
*/
struct Sheet {
  std::vector<Chip>  chipList;
  std::vector<Rect>  rectList; ///< 何らかの用途で用いることのできる矩形のリスト.
  Int  frames;
};

/**
  アニメーション.
  Sheetを複数まとめたもの.
*/
struct Animation {
  std::vector<Sheet>  sheetList;
};

inline Vector2::Vector2(const Point2& p) : x(p.x), y(p.y) {}
inline Point2::Point2(const Vector2& v) : x(v.x), y(v.y) {}

} // namespace SpriteEditor

#endif // SPRITEEDITOR_DATA_H_INCLUDED
