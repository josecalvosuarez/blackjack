#ifndef NODO_H
#define NODO_H

#include "jugadorgenerico.h"

class Nodo {
public:
	Nodo() : dato(nullptr), next(nullptr) { }
	~Nodo() { }

	void setDato(JugadorGenerico* jg) { dato = jg; }
	void setNext(Nodo* n) { next = n; }

	JugadorGenerico* getDato() const { return dato; }
	Nodo* getNext() const { return next; }

private:
	JugadorGenerico* dato;
	Nodo* next;
};

#endif