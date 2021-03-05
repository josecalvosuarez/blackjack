// juego.cpp
// Definición de la clase Juego

#include "juego.h"

Juego::Juego() : listaJugadores(nullptr), baraja(nullptr) { }

Juego::~Juego() { }

void Juego::run() {
	intro();
	menuPrincipal();
}

void Juego::intro() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD consolaAttr;

	if (!consola)
		EXIT_FAILURE;
	else {
		CONSOLE_SCREEN_BUFFER_INFO info;
		bool salir = false;
		int i = 0;

		GetConsoleScreenBufferInfo(consola, &info);
		consolaAttr = info.wAttributes;

		PlaySound(TEXT("Media/intro.wav"), NULL, SND_FILENAME | SND_ASYNC);

		do {
			limpiar();

			if (i > NUM_COLORES)
				i = 1;

			SetConsoleTextAttribute(consola, i++);

			imprimir("\n\n\n\n\n\n\n");
			imprimir("\t\t.------..------..------..------..------..------..------..------..------. \n");
			imprimir("\t\t|B.--. ||L.--. ||A.--. ||C.--. ||K.--. ||J.--. ||A.--. ||C.--. ||K.--. | \n");
			imprimir("\t\t| :(): || :/\\: || (\\/) || :/\\: || :/\\: || :(): || (\\/) || :/\\: || :/\\: | \n");
			imprimir("\t\t| ()() || (__) || :\\/: || :\\/: || :\\/: || ()() || :\\/: || :\\/: || :\\/: | \n");
			imprimir("\t\t| '--'B|| '--'L|| '--'A|| '--'C|| '--'K|| '--'J|| '--'A|| '--'C|| '--'K| \n");
			imprimir("\t\t`------'`------'`------'`------'`------'`------'`------'`------'`------' \n");
			imprimir("\n\n\n");

			SetConsoleTextAttribute(consola, consolaAttr);

			imprimir("\t\t PRESIONE ENTER PARA CONTINUAR... \n");

			sleep(200);

			if (GetAsyncKeyState(VK_RETURN))
				salir = true;

		} while (!salir);

		SetConsoleTextAttribute(consola, consolaAttr);
		PlaySound(NULL, 0, 0);
	}
}

void Juego::menuPrincipal() {
	int opcion;
	bool salir = false;

	while (!salir) {
		limpiar();

		imprimir("  ----------------------------- \n");
		imprimir("  1. NUEVA PARTIDA DE BLACKJACK \n");
		imprimir("  2. CARGAR PARTIDA \n");
		imprimir("  3. SALIR \n");
		imprimir("  ----------------------------- \n");
		imprimir("  OPCION: "); 

		opcion = getEnteroEntre(1, 3);

		switch (opcion) {
		case 1:
			nuevoJuego();
			break;
		case 2:
			// cargarJuego();
			break;
		case 3:
			salir = true;
			break;
		}
	}
}

void Juego::nuevoJuego() {
	obtenerJugadores();
	repartirCartas();
	mostrarMesa();
}

void Juego::obtenerJugadores() {
	std::string nombreJugador;

	listaJugadores = new Lista();

	limpiar();
	imprimir("  --------------------------------- \n");
	imprimir("  DIGITE LA CANTIDAD DE JUGADORES ( 1 - 7 ): ");
	int numJugadores = getEnteroEntre(1, 7);
	limpiar();

	for (int i = 1; i <= numJugadores; ++i) {
		imprimir("  DIGITE EL NOMBRE DEL JUGADOR #" + convertirCadena(i) + ": ");
		nombreJugador = getCadena();

		JugadorGenerico* nuevoJugador = new Jugador(nombreJugador, false);
		listaJugadores->insertarElemento(nuevoJugador);

		imprimir("\n\n");
	}

	JugadorGenerico* laCasa = new Dealer("LA CASA", false, false);
	listaJugadores->insertarElemento(laCasa);
}

void Juego::repartirCartas() {
	Mazo* barajaCartas = new Mazo();

	Lista::iterador tmp = listaJugadores->getInicio();

	while (tmp) {
		tmp->getDato()->setManoInicial(barajaCartas);
		tmp = tmp->getNext();
	}
}

void Juego::mostrarMesa() {
	Lista::iterador tmp = listaJugadores->getInicio();
	Carta** mano;

	limpiar();
	while (tmp) {
		imprimir(" ---------------------- \n");
		imprimir(tmp->getDato()->getNickname() + "\n");

		mano = tmp->getDato()->getManoJugador()->getMano();
		int cartasMano = tmp->getDato()->getManoJugador()->getCantidad();
		for (int i = 0; i < cartasMano; ++i)
			dibujarCarta(mano[i]);
		tmp = tmp->getNext();

		imprimir("\n");
	}

	pausa();
}

void Juego::dibujarCarta(Carta* c) {
	if (!c->estaBocaArriba()) {
		imprimir("\t\t.--------. \n");
		imprimir("\t\t|XXXXXXXX| \n");
		imprimir("\t\t|XXXXXXXX| \n");
		imprimir("\t\t|XXXXXXXX| \n");
		imprimir("\t\t|XXXXXXXX| \n");
		imprimir("\t\t'--------' \n");

		return;
	}

	Rango valorOriginal = c->getValor();
	char rango;

	if (valorOriginal == Rango::AS)
		rango = 'A';
	else if (valorOriginal == Rango::J)
		rango = 'J';
	else if (valorOriginal == Rango::Q)
		rango = 'Q';
	else if (valorOriginal == Rango::K)
		rango = 'K';
	else
		rango = static_cast<char>(valorOriginal) + '0';

	switch (c->getPalo()) {
	case Palo::TREBOLES:
		imprimir("\t\t.--------. \n");
		imprimir("\t\t|" + convertirCadena(rango) + " .--.  | \n");
		imprimir("\t\t|  :():  | \n");
		imprimir("\t\t|  ()()  | \n");
		imprimir("\t\t|  '--' " + convertirCadena(rango) + "| \n");
		imprimir("\t\t'--------' \n");
		break;

	case Palo::CORAZONES:
		imprimir("\t\t.--------. \n");
		imprimir("\t\t|" + convertirCadena(rango) + " .--.  | \n");
		imprimir("\t\t|  (\\/)  | \n");
		imprimir("\t\t|  :\\/:  | \n");
		imprimir("\t\t|  '--' " + convertirCadena(rango) + "| \n");
		imprimir("\t\t'--------' \n");

		break;
	case Palo::ESPADAS:
		imprimir("\t\t.--------. \n");
		imprimir("\t\t|" + convertirCadena(rango) + " .--.  | \n");
		imprimir("\t\t|  :/\\:  | \n");
		imprimir("\t\t|  (__)  | \n");
		imprimir("\t\t|  '--' " + convertirCadena(rango) + "| \n");
		imprimir("\t\t'--------' \n");

		break;
	case Palo::DIAMANTES:
		imprimir("\t\t.--------. \n");
		imprimir("\t\t|" + convertirCadena(rango) + " .--.  | \n");
		imprimir("\t\t|  :/\\:  | \n");
		imprimir("\t\t|  :\\/:  | \n");
		imprimir("\t\t|  '--' " + convertirCadena(rango) + "| \n");
		imprimir("\t\t'--------' \n");

		break;
	}
}