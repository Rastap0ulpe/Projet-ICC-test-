#include <iostream>
#include "..\..\TextViewer.h"
#include "..\..\MontagneSimple.h"
#include "..\..\Systeme.h"
#include <vector>
using namespace std;

int main()
{
  TextViewer ecran(cout);
  Montagne_simple M(15,15,15,5,5);
  Systeme s(&M,30,30,30,20.0/29.0);
  cout<<"Au depart :"<<endl;
  s.demarre(ecran);


  cout<<"Apres un pas de calcule :"<<endl;
  s.evolue(ecran,0.031);


  cout<<"Apres deux pas de calcule :"<<endl;
  s.evolue(ecran,0.031);



  return 0;
}

