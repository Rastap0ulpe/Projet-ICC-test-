TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++11

SOURCES = ..\..\ChaineMontagne.cc \
    ..\..\ChampPotentiels.cc \
    ..\..\Montagne.cc \
    ..\..\MontagneSimple.cc \
   ..\..\Nuages.cc \
   ..\..\Systeme.cc \
    ..\..\Vecteur2D.cc \
    ..\..\constantes.cc

HEADERS += ..\..\Boite3D.h \
    ..\..\ChaineMontagne.h \
    ..\..\ChampPotentiels.h \
    ..\..\Montagne.h \
    ..\..\MontagneSimple.h \
    ..\..\Nuages.h \
    ..\..\Systeme.h \
    ..\..\Vecteur2D.h \
    ..\..\constantes.h \
   ..\..\dessinable.h \
    ..\..\SupportADessin.h
