CXX = g++
CC = $(CXX)
all: testMontagne testVecteur2D testPotentiels testLaplace test_nuage testDeplacement testMontagne2 testLaplace_sans_resolution

testMontagne: Montagne.o testMontagne.o MontagneSimple.o 
testVecteur2D: Vecteur2D.o testVecteur2D.o
testPotentiels: Montagne.o Vecteur2D.o testPotentiels.o ChampPotentiels.o MontagneSimple.o constantes.o
testLaplace: Montagne.o Vecteur2D.o testLaplace.o ChampPotentiels.o  MontagneSimple.o constantes.o
test_nuage: Montagne.o test_nuage.o ChampPotentiels.o Nuages.o constantes.o Vecteur2D.o MontagneSimple.o
testDeplacement:  Montagne.o ChampPotentiels.o Nuages.o Vecteur2D.o testDeplacement.o constantes.o Systeme.o TextViewer.o MontagneSimple.o
testMontagne2: Montagne.o ChaineMontagne.o testMontagne2.o MontagneSimple.o 
testLaplace_sans_resolution: Montagne.o Vecteur2D.o testLaplace_sans_resolution.o ChampPotentiels.o  MontagneSimple.o constantes.o
