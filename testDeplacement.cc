#include <iostream>
#include "Systeme.h"
#include "TextViewer.h"
#include "MontagneSimple.h"
using namespace std;

int main(){

TextViewer text(cout);
Montagne_simple m(15,15,15,5,5);
Systeme systeme(&m,30,30,30,20.0/29.0);
systeme.demarre(text);

	
	return 0;
}
