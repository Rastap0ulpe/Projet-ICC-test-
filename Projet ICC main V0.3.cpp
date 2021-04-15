
#include <iostream>

#include "Vecteur2D.h"

#include "Montagne.h"

#include "ChampPotentiels.h"

#include "constantes.h"

using namespace std;

ostream& operator<<(ostream& os, Vecteur2D const& v1) {
    
    os << "(" << v1.x << " " <<v1.y << ")";

    return os;
};


Vecteur2D operator+(Vecteur2D v1, Vecteur2D v2) {

    v1 += v2;
    return v1;
};

Vecteur2D operator-(Vecteur2D v1, Vecteur2D v2) {

    v1 -= v2;
    return v1;
};


int main()
{

    
    //// un vecteur en 2D :
    //Vecteur2D vect1(1.0, 2.0);

    //// d'autres vecteurs en 2D
    //Vecteur2D vect2(2.6, 3.5);
    //Vecteur2D vect3(vect1);  // copie de V1
    //Vecteur2D vect4;         // le vecteur nul

    //cout << "Vecteur 1 : " << vect1 << endl;
    //cout << "Vecteur 2 : " << vect2 << endl;
    //cout << "Vecteur 3 : " << vect3 << endl;
    //cout << "Vecteur 4 : " << vect4 << endl;

    //cout << "Le vecteur 1 est ";
    //if (vect1 == vect2) {
    //    cout << "égal au";
    //}
    //else {
    //    cout << "différent du";
    //}
    //cout << " vecteur 2," << endl << "et est ";
    //if (vect1 != vect3) {
    //    cout << "différent du";
    //}
    //else {
    //    cout << "égal au";
    //}
    //cout << " vecteur 3." << endl;

    //cout << endl << endl;

    Montagne m1(15, 15,15, 5, 5);

     //for (int i = 0; i <= 29; i++) {
     //    for (int j = 0; j <= 29; j++) {


     //        cout << i << " " << j << " " << m1.altitude(i, j) << endl;

     //    };
     //    cout << endl;
     //};

    ChampPotentiels test(20, 20, 20, 20.0 / 29.0);


    test.initialise(20, m1);
    test.calcule_laplacien();
    

    //for(int i=0;i<=29;i++){
    //    for(int j=0;j<=29;j++){
    //        for (int k = 0; k <= 29; k++) {

    //            cout << i << " " << j << " " << k << " " ;
    //            test.affiche_potentiel(i, j, k);
    //            cout << endl;

    //
    //        }
    //    }
    //}
    
    /*for (int i = 1; i <= 28; i++) {
        for (int j = 1; j <= 28; j++) {
            for (int k = 1; k <= 28; k++) {

                cout << i << " " << j << " " << k << " ";
                test.affiche_laplacien(i, j, k);
                cout << endl;


            }
        }
    }*/

    //cout << test.erreur() << endl;

    test.resolution(pow(test.lamda,4)*(1e-4),5000,false);

    Vecteur3D vitesse;
    double n_vit;
    for (int i = 0; i <= 29; i++) {
        for (int j = 0; j <=29; j++) {
            for (int k = 0; k <= 29; k++) {
                vitesse = test.vitesse(i, j, k);
                n_vit= (pow(vitesse.x, 2) + pow(vitesse.y, 2) + pow(vitesse.z, 2));
              cout << i << " " << j << " " << k << " ";
                test.affiche_potentiel(i, j, k);
                cout << " ";
                cout << vitesse.x << " "<< vitesse.y << " " << vitesse.z << " " << n_vit ;
                cout << endl;


            }
        }
    }


    



}

