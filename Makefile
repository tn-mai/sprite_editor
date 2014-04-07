#############################################################################
# Makefile for building: sprite_editor
# Generated by qmake (3.0) (Qt 5.3.0)
# Project:  sprite_editor.pro
# Template: app
# Command: C:\usr\local\qt5\qtbase\bin\qmake.exe -o Makefile sprite_editor.pro
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = C:\usr\local\qt5\qtbase\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = copy /y
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: sprite_editor.pro ..\..\qt5\qtbase\mkspecs\win32-msvc2013\qmake.conf ..\..\qt5\qtbase\mkspecs\features\spec_pre.prf \
		..\..\qt5\qtbase\mkspecs\common\shell-win32.conf \
		..\..\qt5\qtbase\mkspecs\qconfig.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_axbase.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_axbase_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_axcontainer.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_axcontainer_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_axserver.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_axserver_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_bluetooth.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_bluetooth_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_bootstrap_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_clucene_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_concurrent.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_concurrent_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_core.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_core_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_declarative.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_declarative_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_designer.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_designer_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_designercomponents_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_gui.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_gui_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_help.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_help_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_multimedia.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_multimedia_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_multimediawidgets.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_network.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_network_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_nfc.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_nfc_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_opengl.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_opengl_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_openglextensions.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_openglextensions_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_platformsupport_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_positioning.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_positioning_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_printsupport.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_printsupport_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_qml.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_qml_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_qmltest.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_qmltest_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_quick.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_quick_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_quickparticles_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_quickwidgets.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_script.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_script_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_scripttools.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_scripttools_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_sensors.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_sensors_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_serialport.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_serialport_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_sql.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_sql_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_svg.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_svg_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_testlib.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_testlib_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_uitools.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_uitools_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_websockets.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_websockets_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_widgets.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_widgets_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_winextras.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_winextras_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_xml.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_xml_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_xmlpatterns.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_dumpcpp.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_dumpdoc.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_lconvert.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_lrelease.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_lupdate.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qcollectiongenerator.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qdoc.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qhelpgenerator.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qlalr.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qml.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qml1plugindump.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlbundle.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlimportscanner.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmljs.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlmin.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlplugindump.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlprofiler.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlscene.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmltestrunner.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_syncqt.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_uic.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_xmlpatterns.pri \
		..\..\qt5\qtbase\mkspecs\modules\qt_tool_xmlpatternsvalidator.pri \
		..\..\qt5\qtbase\mkspecs\features\qt_functions.prf \
		..\..\qt5\qtbase\mkspecs\features\qt_config.prf \
		..\..\qt5\qtbase\mkspecs\win32-msvc2013\qmake.conf \
		..\..\qt5\qtbase\mkspecs\features\spec_post.prf \
		..\..\qt5\qtbase\mkspecs\features\exclusive_builds.prf \
		..\..\qt5\qtbase\mkspecs\features\default_pre.prf \
		..\..\qt5\qtbase\mkspecs\features\win32\default_pre.prf \
		..\..\qt5\qtbase\mkspecs\features\resolve_config.prf \
		..\..\qt5\qtbase\mkspecs\features\exclusive_builds_post.prf \
		..\..\qt5\qtbase\mkspecs\features\default_post.prf \
		..\..\qt5\qtbase\mkspecs\features\qt.prf \
		..\..\qt5\qtbase\mkspecs\features\resources.prf \
		..\..\qt5\qtbase\mkspecs\features\moc.prf \
		..\..\qt5\qtbase\mkspecs\features\win32\opengl.prf \
		..\..\qt5\qtbase\mkspecs\features\win32\rtti.prf \
		..\..\qt5\qtbase\mkspecs\features\precompile_header.prf \
		..\..\qt5\qtbase\mkspecs\features\warn_on.prf \
		..\..\qt5\qtbase\mkspecs\features\win32\windows.prf \
		..\..\qt5\qtbase\mkspecs\features\testcase_targets.prf \
		..\..\qt5\qtbase\mkspecs\features\exceptions.prf \
		..\..\qt5\qtbase\mkspecs\features\yacc.prf \
		..\..\qt5\qtbase\mkspecs\features\lex.prf \
		sprite_editor.pro \
		C:/usr/local/qt5/qtbase/lib/Qt5Widgetsd.prl \
		C:/usr/local/qt5/qtbase/lib/Qt5Gui.prl \
		C:/usr/local/qt5/qtbase/lib/Qt5Core.prl
	$(QMAKE) -o Makefile sprite_editor.pro
..\..\qt5\qtbase\mkspecs\features\spec_pre.prf:
..\..\qt5\qtbase\mkspecs\common\shell-win32.conf:
..\..\qt5\qtbase\mkspecs\qconfig.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_axbase.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_axbase_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_axcontainer_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_axserver.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_axserver_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_bluetooth.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_bluetooth_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_bootstrap_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_clucene_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_concurrent.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_concurrent_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_core.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_core_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_declarative.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_declarative_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_designer.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_designer_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_designercomponents_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_gui.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_gui_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_help.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_help_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_multimedia.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_multimedia_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_network.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_network_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_nfc.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_nfc_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_opengl.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_opengl_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_openglextensions.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_openglextensions_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_platformsupport_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_positioning.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_positioning_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_printsupport.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_printsupport_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_qml.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_qml_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_qmldevtools_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_qmltest.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_qmltest_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_quick.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_quick_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_quickparticles_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_quickwidgets.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_quickwidgets_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_script.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_script_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_scripttools.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_scripttools_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_sensors.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_sensors_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_serialport.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_serialport_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_sql.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_sql_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_svg.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_svg_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_testlib.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_testlib_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_uitools.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_uitools_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_websockets.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_websockets_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_widgets.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_widgets_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_winextras.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_winextras_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_xml.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_xml_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_dumpcpp.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_dumpdoc.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_lconvert.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_lrelease.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_lupdate.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qcollectiongenerator.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qdoc.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qhelpgenerator.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qlalr.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qml.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qml1plugindump.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlbundle.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlimportscanner.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmljs.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlmin.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlplugindump.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlprofiler.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmlscene.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_qmltestrunner.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_syncqt.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_uic.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_xmlpatterns.pri:
..\..\qt5\qtbase\mkspecs\modules\qt_tool_xmlpatternsvalidator.pri:
..\..\qt5\qtbase\mkspecs\features\qt_functions.prf:
..\..\qt5\qtbase\mkspecs\features\qt_config.prf:
..\..\qt5\qtbase\mkspecs\win32-msvc2013\qmake.conf:
..\..\qt5\qtbase\mkspecs\features\spec_post.prf:
..\..\qt5\qtbase\mkspecs\features\exclusive_builds.prf:
..\..\qt5\qtbase\mkspecs\features\default_pre.prf:
..\..\qt5\qtbase\mkspecs\features\win32\default_pre.prf:
..\..\qt5\qtbase\mkspecs\features\resolve_config.prf:
..\..\qt5\qtbase\mkspecs\features\exclusive_builds_post.prf:
..\..\qt5\qtbase\mkspecs\features\default_post.prf:
..\..\qt5\qtbase\mkspecs\features\qt.prf:
..\..\qt5\qtbase\mkspecs\features\resources.prf:
..\..\qt5\qtbase\mkspecs\features\moc.prf:
..\..\qt5\qtbase\mkspecs\features\win32\opengl.prf:
..\..\qt5\qtbase\mkspecs\features\win32\rtti.prf:
..\..\qt5\qtbase\mkspecs\features\precompile_header.prf:
..\..\qt5\qtbase\mkspecs\features\warn_on.prf:
..\..\qt5\qtbase\mkspecs\features\win32\windows.prf:
..\..\qt5\qtbase\mkspecs\features\testcase_targets.prf:
..\..\qt5\qtbase\mkspecs\features\exceptions.prf:
..\..\qt5\qtbase\mkspecs\features\yacc.prf:
..\..\qt5\qtbase\mkspecs\features\lex.prf:
sprite_editor.pro:
C:/usr/local/qt5/qtbase/lib/Qt5Widgetsd.prl:
C:/usr/local/qt5/qtbase/lib/Qt5Gui.prl:
C:/usr/local/qt5/qtbase/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile sprite_editor.pro

qmake_all: FORCE

make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
	-$(DEL_FILE) sprite_editor.exp
	-$(DEL_FILE) sprite_editor.ilk
	-$(DEL_FILE) sprite_editor.idb
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) sprite_editor.pdb

debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
