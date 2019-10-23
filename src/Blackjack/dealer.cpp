// Dealer.cpp
// Implementación de la clase Dealer

#include "dealer.h"

Dealer::Dealer() { }

Dealer::Dealer(std::string n, bool t, bool p) : JugadorGenerico(n, t), sePaso(p) { }

Dealer::~Dealer() {
	nickname.clear();
}

Carta* Dealer::pedirCarta(Mazo* cartasDisponibles) {
	int puntosMano = 0;
	Carta* nuevaCarta = cartasDisponibles->tomarCarta();

	manoJugador.agregarCarta(nuevaCarta);

	if (puntosMano = manoJugador.getPuntaje() > 21)
		turno = false;

	return nuevaCarta;
}

void Dealer::setManoInicial(Mazo* cartasDisponibles) {
	Carta* primera = cartasDisponibles->tomarCarta();
	primera->voltear();
	manoJugador.agregarCarta(primera);

	Carta* segunda = cartasDisponibles->tomarCarta();
	manoJugador.agregarCarta(segunda);
}