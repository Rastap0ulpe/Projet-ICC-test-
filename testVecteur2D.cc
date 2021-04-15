#include <iostream>
#include "Vecteur2D.h"

using namespace std;

int main(){
	
	
// un vecteur en 2D :
Vecteur2D vect1(-3.0, 4.0);

// d'autres vecteurs en 2D
Vecteur2D vect2(0, 0);

Vecteur2D vect3;

vect3 = vect1.mult(2) + vect2 ;
cout<<vect3<<endl;
cout<<vect2.norme2()<<" "<<vect1.norme2()<<endl;
/* cout<<~vect1;
vect3=vect1-vect2;
cout<<"vecteur 1: "<<vect1<<endl;
cout<<"vecteur 2: "<<vect2<<endl;
cout<<"vecteur 3: "<<vect3<<endl;
vect1-=vect2;
vect1-=vect2;
vect3=vect1-vect2;
cout<<"vecteur 1: "<<vect1<<endl;
cout<<"vecteur 2: "<<vect2<<endl;
cout<<"vecteur 3: "<<vect3<<endl;
/*Vecteur vect3(vect1);  // copie de V1
Vecteur vect4;         // le vecteur nul

cout << "Vecteur 1 : " << vect1 << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;
cout << "Vecteur 4 : " << vect4 << endl;

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (vect1 != vect3) {
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl;*/

return 0;
}

