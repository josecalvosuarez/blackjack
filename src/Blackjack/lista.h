// lista.h
// Declaración de la clase Lista

#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista {
public:
	Lista();
	~Lista();

	void insertarElemento(JugadorGenerico*);
	void borrarLista();

	typedef Nodo* iterador;
	Nodo* getInicio() const;

private:
	Nodo *inicio;
};

#endif