#include "ChampPotentiels.h"

ChampPotentiels::ChampPotentiels(double lx, double ly, double lz, double pas_echantillonage)
{

	lamda = pas_echantillonage;

	L_x = lx;

	L_y = ly;

	L_z = lz;

	N_x = round(L_x / lamda + 1.0);

	N_y = round(L_y / lamda + 1.0);

	N_z = round(L_z / lamda + 1.0);

}

void ChampPotentiels::initialise(double v_inf, Montagne& const M)
{

	v_infty = v_inf;

	Mont = M;
	
	boite.resize(N_x );
	for (int i = 0; i < N_x; i++) {


		boite[i].resize(N_y );
		for (int j = 0; j < N_y; j++) {
			
			
			boite[i][j].resize(N_z);
			for (int k = 0; k < N_z; k++) {
				
				if (k  < M.altitude(i , j )) {		// <= ??!!

					boite[i][j][k].potentiel.x = 0;
					boite[i][j][k].potentiel.y = 0;
				

				}
				else {
					boite[i][j][k].potentiel.x = -v_inf / 2 * k * lamda;
					boite[i][j][k].potentiel.y = v_inf / 2 * (j * lamda - L_y / 2);
					
				};

				boite[i][j][k].laplacien.x = 0;
				boite[i][j][k].laplacien.x = 0;
				
				
			};
			

		};

	
	};


}

void ChampPotentiels::calcule_laplacien()
{
	double precission = 1e-14;
	double a;
	double b;
	for (int i = 1; i <= N_x-2; i++) {
		for (int j = 1; j <= N_y-2; j++) {
			for (int k = 1; k <= N_z-2; k++) {
				
				if(k < Mont.altitude(i, j)){ 
					boite[i][j][k].laplacien.x = 0; 
					boite[i][j][k].laplacien.y = 0;
				}
				else {
					a = boite[i - 1][j][k].potentiel.x + boite[i][j - 1][k].potentiel.x + boite[i][j][k - 1].potentiel.x - 6 * boite[i][j][k].potentiel.x + boite[i + 1][j][k].potentiel.x + boite[i][j + 1][k].potentiel.x + boite[i][j][k + 1].potentiel.x;
					b = boite[i - 1][j][k].potentiel.y + boite[i][j - 1][k].potentiel.y + boite[i][j][k - 1].potentiel.y - 6 * boite[i][j][k].potentiel.y + boite[i + 1][j][k].potentiel.y + boite[i][j + 1][k].potentiel.y + boite[i][j][k + 1].potentiel.y;
					if (abs(a) < precission) { boite[i][j][k].laplacien.x = 0; }
					else { boite[i][j][k].laplacien.x = a; }

					if (abs(b) < precission) { boite[i][j][k].laplacien.y = 0; }
					else { boite[i][j][k].laplacien.y = b; }
				}
			}
		}
	}

}

void ChampPotentiels::affiche_potentiel(int i, int j, int k)
{
			
				cout  << boite[i][j][k].potentiel.x << " " << boite[i][j][k].potentiel.y ;

}

void ChampPotentiels::affiche_laplacien(int i, int j, int k)
{

				cout  << boite[i][j][k].laplacien.x << " " << boite[i][j][k].laplacien.y;


}

double ChampPotentiels::erreur()
{
	
	double error=0;

	for (int i = 0; i < N_x; i++) {
		for (int j = 0; j < N_y; j++) {
			for (int k = 0; k < N_z; k++) {

				error += (pow(boite[i][j][k].laplacien.x, 2) + pow(boite[i][j][k].laplacien.y, 2));
				
			}
		}
	}


	return error;
}

void ChampPotentiels::iteration(double e )
{
	

	for (int i = 1; i <= N_x - 2; i++) {
		for (int j = 1; j <= N_y - 2; j++) {
			for (int k = 1; k <= N_z - 2; k++) {


				boite[i][j][k].potentiel.x += e * boite[i][j][k].laplacien.x;
				boite[i][j][k].potentiel.y += e * boite[i][j][k].laplacien.y;

			}
		}
	}

	calcule_laplacien();

}

void ChampPotentiels::resolution(double precision, int max_iteration, bool verbeuse)
{

	calcule_laplacien();
	int l = 1;
	while (l<=max_iteration && erreur()>precision) {
		if (verbeuse) {
			cout << l << "  " << erreur() << endl;
		}
				
		iteration();
		
		l++;
	}


}

Vecteur3D ChampPotentiels::vitesse(int i, int j, int k)
{
	Vecteur3D vites;
	if (0 < i && i< N_x - 1 && 0 < j && j< N_y - 1 && 0 < k && k < N_z - 1) {
		vites.x = (1 / (2 * lamda)) * (boite[i][j + 1][k].potentiel.y - boite[i][j - 1][k].potentiel.y - boite[i][j][k + 1].potentiel.x + boite[i][j][k - 1].potentiel.x);
		vites.y = (1 / (2 * lamda)) * (-boite[i + 1][j][k].potentiel.y + boite[i - 1][j][k].potentiel.y);
		vites.z = (1 / (2 * lamda)) * (boite[i + 1][j][k].potentiel.x - boite[i - 1][j][k].potentiel.x);
	}
	else {
	
		vites.x = 0;
		vites.y = 0;
		vites.z = 0;
	}
	return vites;
}
