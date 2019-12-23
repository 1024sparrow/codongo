QT = core widgets qml

SOURCES += \
    main.cpp \
    mw.cpp \
    backend.cpp \
    mouselistener.cpp \
    layout.cpp \
    qmlgenerator.cpp

HEADERS += \
    mw.h \
    backend.h \
    mouselistener.h \
    commonsettings.h \
    layout.h \
    keycodes.h \
    qmlgenerator.h \
    screenspec.h

LIBS += -lX11 -lXext -lXfixes

RESOURCES += \
	qmltemplateres.qrc
