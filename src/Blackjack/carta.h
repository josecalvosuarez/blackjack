// carta.h
// Declaración de la clase Carta

#ifndef CARTA_H
#define CARTA_H

#define MAX_RANGO	13
#define	MAX_PALOS	4

// Declaramos dos enumeraciones para manejar el rango y el palo de cada carta
enum class Rango { AS = 1, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, OCHO, NUEVE, DIEZ, J, Q, K };
enum class Palo { ESPADAS, CORAZONES, DIAMANTES, TREBOLES };

class Carta {
public:
	Carta();
	Carta(Rango, Palo, bool);
	~Carta();

	Rango getValor() const;
	Palo getPalo() const;
	bool estaBocaArriba() const;

	void setValor(Rango);
	void setPalo(Palo);

	void voltear();

private:
	Rango valorCarta;
	Palo paloCarta;
	bool bocaArriba;
};

#endif
