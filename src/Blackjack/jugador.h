// jugador.h
// Declaración de la clase Jugador

#ifndef JUGADOR_H
#define JUGADOR_H

#include "jugadorgenerico.h"
#include <string>

class Jugador : public JugadorGenerico {
public:
	Jugador();
	Jugador(std::string n, bool t);
	virtual ~Jugador();

	virtual Carta* pedirCarta(Mazo*);
	virtual void setManoInicial(Mazo*);
};

#endif

