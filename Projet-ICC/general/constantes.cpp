#include "constantes.h"

namespace Physique{
	extern const double g(9.81);
	extern const double R(8.3144621);
	extern const double Mol_air(0.02896);
	extern const double Mol_eau(0.0180153);	
}

namespace const_sys{
	extern const double v_loin(20);
	extern const double P_loin(101325);
	extern const double T_loin(284.5);
	extern const double h_loin((7.0/2.0)*T_loin*(Physique::R/Physique::Mol_air));	
	extern const double P_ref(101325);
	extern const double cte(0.5*v_loin*v_loin + h_loin);
	extern const double taux_hum(8.0/1000.0);
}
