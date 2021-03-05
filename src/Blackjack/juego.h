// juego.h
// Declaración de la clase Juego

// Se requiere hacer link de la librería winmm.lib  --> Linker Options

#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <cctype>
#include <windows.h>
#include <mmsystem.h>
#include "lista.h"
#include "jugador.h"
#include "dealer.h"

// Agregación de útiles.
#include "utiles.h"

#define NUM_COLORES	7

class Juego {
public:
	Juego();
	~Juego();
	void run();

private:
	Lista* listaJugadores;
	Mazo* baraja;

	void intro();
	void menuPrincipal();
	void nuevoJuego();
	void obtenerJugadores();
	void repartirCartas();
	void mostrarMesa();
	void dibujarCarta(Carta*);
	void cargarJuego();
};

#endif


