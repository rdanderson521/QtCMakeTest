cmake_minimum_required(VERSION 3.16)


qt_add_executable(app
  main.cpp
)

set_target_properties(app PROPERTIES INSTALL_RPATH "$ORIGIN/../lib")

qt_add_qml_module(app
  URI "mainApp"
  VERSION 1.0
  QML_FILES main.qml
  SOURCES main.cpp

  IMPORTS QtMultimedia
)

target_link_libraries(app
  PUBLIC 
  Qt6::Qml 
  Qt6::QmlPrivate 
  Qt6::Quick 
  Qt6::QuickPrivate 
  Qt6::QuickControls2
  Qt6::QuickControls2Private
  Qt6::QuickLayouts 
  Qt6::QuickLayoutsPrivate 
  Qt6::Multimedia 


  staticLibplugin
  sharedTest
)

install(TARGETS app)

qt_generate_deploy_qml_app_script(
  TARGET app
  OUTPUT_SCRIPT depScript)

install(SCRIPT ${depScript})
