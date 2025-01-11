cmake_minimum_required(VERSION 3.16)
project(tank300 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_standard_project_setup()

qt_add_executable(tankGame
        src/achievement.cpp
        src/achievementwidget.cpp  
        src/gamemanager.cpp  
        src/main.cpp      
        src/map.cpp         
        src/projectile.cpp    
        src/tank.cpp
        src/achievementsscene.cpp  
        src/botTank.cpp            
        src/gameObject.cpp   
        src/mainmenu.cpp  
        src/playerTank.cpp  
        src/settingsmenu.cpp    
        resources.qrc
)

set_target_properties(tankGame PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(tankGame PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    Qt6::Widgets
)

install(TARGETS tankGame
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET tankGame
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
