// mazo.h
// Declaración de la clase Mazo

#ifndef MAZO_H
#define MAZO_H

#include "carta.h"
#include <random>
#include <algorithm>


// Tamaño de la baraja
#define NUMCARTAS	52

class Mazo {
public:
	Mazo();
	~Mazo();

	void inicializar();
	void barajar();
	void limpiar();
	Carta* tomarCarta();

private:
	Carta** naipe;
	int primera;
};

#endif
