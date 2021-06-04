#include <QApplication>
#include "glwidget.h"
#include "..\..\Montagne.h"
#include "..\..\ChaineMontagne.h"
#include "..\..\Systeme.h"
#include <vector>
int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
/*
  Montagne_simple m3(2,22,12,12,3);
  Montagne_simple m2(20,2,15,8,4);
  std::vector<Montagne*> chaine({&m3,&m2});
  Montagne_simple m1(15,15,18,5,10);
  ChaineMontagne M(chaine); // chaine montagne avec deux montagne gaussienne
 std::vector<Montagne*> chaine2({&M,&m1});
  ChaineMontagne M2(chaine2); //  chaine de montagne avec une montagne gausienne et une chaine de montagne
  GLWidget w(&M2,30,30,30,20.0/29.0);*/

 Montagne_simple m(15,15,15,5,5);
 GLWidget w(&m,30,30,30,20.0/29.0);
  w.resize(1000,1000);
  w.move(900,5);
  w.show();



  return a.exec();
}
