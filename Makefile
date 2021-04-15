CXX = g++
CC = $(CXX)
all: testMontagne testVecteur2D testPotentiels testLaplace

testMontagne: Montagne.o testMontagne.o
testVecteur2D: Vecteur2D.o testVecteur2D.o
testPotentiels: Montagne.o Vecteur2D.o testPotentiels.o ChampPotentiels.o 
testLaplace: Montagne.o Vecteur2D.o testLaplace.o ChampPotentiels.o 

