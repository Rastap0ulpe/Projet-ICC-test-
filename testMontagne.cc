#include <iostream>
#include <vector>
#include "Montagne.h"
#include <iomanip>
using namespace std;

int main(){
Montagne m(15,15,18,5,10);

for (size_t i(0); i <=29 ;++i){
	for (size_t j(0); j <=29 ;++j){
		cout<<i<<" "<<j<<" "<<m.altitude(i,j)<<endl;

	}
	cout<<endl;
}



return 0;

}
