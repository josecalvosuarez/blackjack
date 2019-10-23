// lista.cpp
// Definición de la clase Lista

#include "lista.h"

// Inicializa la lista enlazada, con el nodo inicial apuntando a nullptr
Lista::Lista() {
	inicio = nullptr;
}

// Llama a la función borrarLista() para eliminar todos los elementos
Lista::~Lista() {
	borrarLista();
}

// Inserta un nuevo puntero a JugadorGenerico dentro de la lista
// Los elementos se insertan al final
void Lista::insertarElemento(JugadorGenerico* item) {
	Nodo *nuevo;

	nuevo = new Nodo; 
	nuevo->setDato(item);     
	nuevo->setNext(nullptr);
	
	// Si la lista está vacía, el nodo creado se convierte en el primer elemento
	if (inicio == nullptr)
		inicio = nuevo;
	else {                             
		Nodo *tmp = inicio;     
		while (tmp->getNext() != nullptr)
			tmp = tmp->getNext();
		tmp->setNext(nuevo);   
	  }                                                
}

// Libera la memoria de la lista enlazada. Para cada nodo, libera la memoria del objeto que contiene. Luego, se libera la memoria
// asignada al nodo
void Lista::borrarLista() {
	Nodo *tmp;
	while (inicio != nullptr) {
		tmp = inicio;
		inicio = inicio->getNext();
		delete tmp->getDato();  
		delete tmp;                    
	}
}

// Retorna la dirección de memoria del primer nodo de la lista
Nodo* Lista::getInicio() const {
	return inicio;
}