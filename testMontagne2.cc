#include <iostream>
using namespace std;
#include "ChaineMontagne.h"
#include "Montagne.h"
#include "MontagneSimple.h"
#include <vector>




int main(){


Montagne_simple m3(2,22,12,12,3);
Montagne_simple m2(20,2,15,8,4);

Montagne_simple m1(15,15,18,5,10);
ChaineMontagne M({&m3,&m2});

ChaineMontagne M2({&M,&m1});

M2.affiche_altitude();






return 0;

}
