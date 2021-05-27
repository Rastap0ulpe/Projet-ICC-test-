QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = ex_05_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc \
    ../general/ChaineMontagne.cpp \
    ../general/MontagneSimple.cpp \
    ../general/Systeme.cpp \
    ../general/ChampPotentiels.cpp \
    ../general/Vecteur2D.cpp \
    ../general/Nuages.cpp \
    ../general/constantes.cpp

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h \
    ../general/contenu.h \
    ../general/ChaineMontagne.h \
    ../general/MontagneSimple.h \
    ../general/Systeme.h \
    ../general/ChampPotentiels.h \
    ../general/Vecteur2D.h \
    ../general/Nuages.h \
    ../general/constantes.h

RESOURCES += \
resource.qrc


