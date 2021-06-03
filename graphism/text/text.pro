QMAKE_CXXFLAGS += -std=c++11

TARGET = ex_05_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    ../../TextViewer.cc \
    main_text.cc \
    ../../ChaineMontagne.cc \
    ../../MontagneSimple.cc \
    ../../Systeme.cc \
    ../../ChampPotentiels.cc \
    ../../Vecteur2D.cc \
    ../../Nuages.cc \
    ../../constantes.cc


HEADERS += \
    ../../TextViewer.h \
    ../../dessinable.h \
    ../../support_a_dessin.h \
    ../../ChaineMontagne.h \
    ../../MontagneSimple.h \
    ../../Montagne.h \
    ../../Systeme.h \
    ../../ChampPotentiels.h \
    ../../Vecteur2D.h \
    ../../Nuages.h \
    ../../constantes.h



