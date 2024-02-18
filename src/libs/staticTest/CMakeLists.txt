cmake_minimum_required(VERSION 3.16)


qt_add_library(staticLib STATIC)

qt_add_qml_module(staticLib
  URI "staticTest"
  VERSION 1.0
  QML_FILES Static.qml

  OUTPUT_TARGETS testOut
)

target_link_libraries(staticLib
  PUBLIC 
  Qt6::Qml 
  Qt6::QmlPrivate 
  Qt6::Quick 
  Qt6::QuickPrivate 
  Qt6::QuickLayouts 
  Qt6::QuickLayoutsPrivate 

  Qt6::Multimedia 

)