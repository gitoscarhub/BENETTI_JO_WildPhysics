// BENETTI_JO_WildPhisycs.cpp: define el punto de entrada de la aplicación.


#include "stdafx.h"
#include "Juego.h"

using namespace sf;

int _tmain(int argc, _TCHAR* argv[])
{
	
	time_t tiempo_actual = time(NULL);
	unsigned int tiempo = static_cast<unsigned int>(tiempo_actual);
	srand(tiempo);
	Juego WildPhysics;
	WildPhysics.Loop();
	
	return 0;
};


