TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++11

SOURCES = contenu.cc \
    ChaineMontagne.cpp \
    ChampPotentiels.cpp \
    Montagne.cpp \
    MontagneSimple.cpp \
    Nuages.cpp \
    Systeme.cpp \
    Vecteur2D.cpp \
    constantes.cpp

HEADERS += \
    Boite3D.h \
    ChaineMontagne.h \
    ChampPotentiels.h \
    Montagne.h \
    MontagneSimple.h \
    Nuages.h \
    Systeme.h \
    Vecteur2D.h \
    constantes.h \
    contenu.h \
    dessinable.h \
    support_a_dessin.h
