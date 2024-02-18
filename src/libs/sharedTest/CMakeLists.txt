cmake_minimum_required(VERSION 3.16)


qt_add_library(sharedTest SHARED)

qt_add_qml_module(sharedTest
  URI "sharedTest"
  VERSION 1.0
  QML_FILES Shared.qml
)

target_link_libraries(sharedTest
  PUBLIC 
  Qt6::Qml 
  Qt6::QmlPrivate 
  Qt6::Quick 
  Qt6::QuickPrivate 
  Qt6::QuickLayouts 
  Qt6::QuickLayoutsPrivate 
)

set_target_properties(sharedTestplugin PROPERTIES INSTALL_RPATH "$ORIGIN/../lib")


install(TARGETS sharedTest)
install(TARGETS sharedTestplugin
LIBRARY DESTINATION plugins)

# qt_generate_deploy_qml_app_script(
#   TARGET sharedLib
#   OUTPUT_SCRIPT depScript)

# install(SCRIPT ${depScript})