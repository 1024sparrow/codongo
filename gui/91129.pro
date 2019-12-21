QT = core widgets qml

SOURCES += \
    main.cpp \
    mw.cpp \
    backend.cpp \
    mouselistener.cpp

HEADERS += \
    mw.h \
    backend.h \
    mouselistener.h \
    commonsettings.h \
    layout.h \
    keycodes.h

LIBS += -lX11 -lXext -lXfixes
