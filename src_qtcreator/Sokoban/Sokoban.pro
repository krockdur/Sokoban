TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:\libs\SFML\include"
LIBS += "C:\libs\SFML\lib" -lsfml-graphics -lsfml-main -lsfml-main -lsfml-window -lsfml-system

SOURCES += \
        Config.cpp \
        Game.cpp \
        Map.cpp \
        MenuScreen.cpp \
        Player.cpp \
        ScreenManager.cpp \
        Sokoban.cpp

HEADERS += \
    Case.h \
    Config.h \
    Context.h \
    Game.h \
    Map.h \
    MenuScreen.h \
    Player.h \
    ScreenManager.h
