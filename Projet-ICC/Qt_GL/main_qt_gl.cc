#include <QApplication>
#include "glwidget.h"
#include "MontagneSimple.h"
#include "ChaineMontagne.h"
#include "Systeme.h"
int main(int argc, char* argv[])
{
  QApplication a(argc, argv);

  Montagne_simple m(15,15,15,5,5);

  GLWidget w;
  w.resize(1000,1000);
  w.move(900,5);
  w.M=m;
  w.S.initialise_systeme(&m,30,30,30,29.0/20.0);
  w.show();
  w.pause();

  return a.exec();
}
