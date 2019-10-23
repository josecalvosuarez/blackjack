// jugador.cpp
// Implementación de la clase Jugador

#include "jugador.h"

Jugador::Jugador() { }

Jugador::Jugador(std::string n, bool t) : JugadorGenerico(n, t) { }

Jugador::~Jugador() { 
	nickname.clear();
}

Carta* Jugador::pedirCarta(Mazo* cartasDisponibles) {
	int puntosMano = 0;
	Carta* nuevaCarta = cartasDisponibles->tomarCarta();
		
	manoJugador.agregarCarta(nuevaCarta);
	
	if (puntosMano = manoJugador.getPuntaje() > 21)
		turno = false;

	return nuevaCarta;
}

void Jugador::setManoInicial(Mazo* cartasDisponibles) {
	for (int i = 0; i < MANO_INICIAL; ++i){
		Carta* nuevaCarta = cartasDisponibles->tomarCarta();
		nuevaCarta->voltear();
		manoJugador.agregarCarta(nuevaCarta);
	}
}