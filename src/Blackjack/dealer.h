// dealer.h
// Declaración de la clase Dealer

#ifndef DEALER_H
#define DEALER_H

#include "JugadorGenerico.h"
#include <string>

class Dealer : public JugadorGenerico {
public:
	Dealer();
	Dealer(std::string n, bool t, bool p);
	virtual ~Dealer();

	virtual Carta* pedirCarta(Mazo*);
	virtual void setManoInicial(Mazo*);

private:
	bool sePaso;
};

#endif

