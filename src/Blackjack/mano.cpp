// mano.cpp
// Definición de la clase Mano

#include "mano.h"

// Constructor
// Crea un vector de punteros a carta de tamaño MAX_MANO e inicializa cada posición con NULL
// También inicializa la cantidad de cartas de la mano
Mano::Mano(){
	inicializarMano();
}

// Destructor
// Libera la memoria asignada a la mano del jugador - con la ayuda de la función 'limpiarMano()'
Mano::~Mano() {
	limpiarMano();
}

// Retorna un apuntador a la mano de cartas
Carta** Mano::getMano() const {
	return juego;
}

// Retorna la cantidad de cartas de la mano
int Mano::getCantidad() const {
	return cantidadCartas;
}

// Agrega una nueva carta a la mano del jugador
void Mano::agregarCarta(Carta* nuevaCarta) {
	juego[cantidadCartas++] = nuevaCarta;
}

// Asigna memoria para el vector de cartas de la mano (cada posición tiene un puntero a un objeto tipo Carta)
void Mano::inicializarMano() {
	juego = new Carta*[MAX_MANO];

	for (int i = 0; i < MAX_MANO; ++i)
		juego[i] = nullptr;

	cantidadCartas = 0;
}

// Elimina todas las cartas de la mano y libera la memoria asignada
void Mano::limpiarMano() {
	for (int i = 0; i < cantidadCartas; ++i)
		delete juego[i];

	delete[] juego;
	
	juego = nullptr;
	cantidadCartas = 0;
}

int Mano::getPuntaje() {
	int puntos = 0;
	
	for (int i = 0; i < cantidadCartas; ++i) {
		Rango valorCarta = juego[i]->getValor();
		
		// Si la carta es J, Q, o K entonces hay que agregar 10 a los puntos
		if (valorCarta >= Rango::J)
			puntos += 10;
		// Si la carta es un AS, entonces revisamos la cantidad de puntos. Si los puntos no superan los 10, entonces tomamos el valor del
		// AS como 11. En caso contrario, lo tomamos como 1.
		else if (valorCarta == Rango::AS && puntos <= 10)
			puntos += 11;
		else
			puntos += static_cast<int>(valorCarta);
	}
	return puntos;
}