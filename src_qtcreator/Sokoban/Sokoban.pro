TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

linux-g++ | linux-g++-64 | linux-g++-32 {
    INCLUDEPATH += "/usr/local/include/"
    LIBS += -L"/usr/local/lib/" -lsfml-graphics -lsfml-window -lsfml-system
}

win32{
    INCLUDEPATH += "C:/libs/SFML/include"
    LIBS += -L"C/home/krock/libs/SFML/lib/" -lsfml-graphics -lsfml-main -lsfml-window -lsfml-system
}

SOURCES += \
        Config.cpp \
        Game.cpp \
        Map.cpp \
        MenuScreen.cpp \
        Player.cpp \
        ScreenManager.cpp \
        Sokoban.cpp \
        boardstate.cpp

HEADERS += \
    Case.h \
    Config.h \
    Context.h \
    Game.h \
    Map.h \
    MenuScreen.h \
    Player.h \
    ScreenManager.h \
    boardstate.h


