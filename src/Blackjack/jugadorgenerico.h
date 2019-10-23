// jugadorgenerico.h
// Declaración de la clase abstracta JugadorGenerico

#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include "mano.h"
#include <string>

#define MANO_INICIAL	2

class JugadorGenerico {
public:
	JugadorGenerico() : nickname(" "), turno(false) { }
	JugadorGenerico(std::string n, bool t) : nickname(n), turno(t) { }  
	virtual ~JugadorGenerico() { }

	virtual Carta* pedirCarta(Mazo*) = 0;
	virtual void setManoInicial(Mazo*) = 0;

	void pasar() { turno = false; }
	void setNickname(std::string n) { nickname = n; }

	std::string getNickname() { return nickname; }
	Mano* getManoJugador() { return &manoJugador; }

protected:
	std::string nickname;
	Mano manoJugador;
	bool turno;
};

#endif

