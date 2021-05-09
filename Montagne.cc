#include <iostream>
using namespace std;

#include "Montagne.h"

void Montagne::affiche() const{
		for (size_t i(0); i <=29 ;++i){
			for (size_t j(0); j <=29 ;++j){
				cout<<i<<" "<<j<<" "<<altitude(i,j)<<endl;

	}
	cout<<endl;
}
	};
