// mano.h
// Declaración de la clase Mano

#ifndef MANO_H
#define MANO_H

// Define el tamaño máximo de cartas que puede tener una mano
#define MAX_MANO	8

#include "mazo.h"

class Mano {
public:
	Mano();
	~Mano();

	Carta** getMano() const;
	int getCantidad() const;

	void agregarCarta(Carta*);
	void inicializarMano();
	void limpiarMano();
	int getPuntaje();

private:
	Carta** juego;
	int cantidadCartas;
};

#endif
