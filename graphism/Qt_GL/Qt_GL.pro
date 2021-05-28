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
    ../../ChaineMontagne.cc \
    ../../MontagneSimple.cc \
    ../../Systeme.cc \
    ../../ChampPotentiels.cc \
    ../../Vecteur2D.cc \
    ../../Nuages.cc \
    ../../constantes.cc


HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    ../../dessinable.h \
    ../../support_a_dessin.h \
    ../../ChaineMontagne.h \
    ../../MontagneSimple.h \
    ../../Systeme.h \
    ../../ChampPotentiels.h \
    ../../Vecteur2D.h \
    ../../Nuages.h \
    ../../constantes.h

RESOURCES += \
resource.qrc


