// juego.cpp
// Definición de la clase Juego

#include "juego.h"

Juego::Juego() : listaJugadores(nullptr), baraja(nullptr) { }

Juego::~Juego() { }

void Juego::run() {
	intro();
	menuPrincipal();
}

void Juego::intro(){
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
			system("cls");

			if (i > NUM_COLORES)
				i = 1;

			SetConsoleTextAttribute(consola, i++);

			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout <<
				"\t\t.------..------..------..------..------..------..------..------..------." << std::endl <<
				"\t\t|B.--. ||L.--. ||A.--. ||C.--. ||K.--. ||J.--. ||A.--. ||C.--. ||K.--. |" << std::endl <<
				"\t\t| :(): || :/\\: || (\\/) || :/\\: || :/\\: || :(): || (\\/) || :/\\: || :/\\: |" << std::endl <<
				"\t\t| ()() || (__) || :\\/: || :\\/: || :\\/: || ()() || :\\/: || :\\/: || :\\/: |" << std::endl <<
				"\t\t| '--'B|| '--'L|| '--'A|| '--'C|| '--'K|| '--'J|| '--'A|| '--'C|| '--'K|" << std::endl <<
				"\t\t`------'`------'`------'`------'`------'`------'`------'`------'`------'";
			std::cout << std::endl << std::endl << std::endl;

			SetConsoleTextAttribute(consola, consolaAttr);
			std::cout << "\t\tPRESIONE ENTER PARA CONTINUAR...";

			std::this_thread::sleep_for(std::chrono::milliseconds(200));

			if (GetAsyncKeyState(VK_RETURN))
				salir = true;

		} while (!salir);

		SetConsoleTextAttribute(consola, consolaAttr);
		PlaySound(NULL, 0, 0);
	}
}

void Juego::menuPrincipal() {
	char opcion;
	bool salir = false;

	while (!salir) {
		do {
			system("cls");
			
			std::cout << "  -----------------------------" << std::endl;
			std::cout << "  1. NUEVA PARTIDA DE BLACKJACK" << std::endl;
			std::cout << "  2. CARGAR PARTIDA" << std::endl;
			std::cout << "  3. SALIR" << std::endl;
			std::cout << "  -----------------------------" << std::endl;
			std::cout << "         Opcion: ";

			std::cin.get(opcion);

		} while (opcion < '1' || opcion > '3');

		switch (opcion) {
		case '1':
			nuevoJuego();
			break;
		case '2':
			// cargarJuego();
			break;
		case '3':
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
	int numJugadores;
	std::string nombreJugador;

	listaJugadores = new Lista();
	   
	std::cin.ignore();
	std::cin.clear();

	do {
		system("cls");

		std::cout << "  ---------------------------------" << std::endl;
		std::cout << "  DIGITE LA CANTIDAD DE JUGADORES ( 1 - 7 ): ";

		std::cin >> numJugadores;

	} while (numJugadores < 1 || numJugadores > 7 || isalpha(numJugadores));

	system("cls");

	std::cin.ignore();
	std::cin.clear();

	for (int i = 1; i <= numJugadores; ++i) {
		std::cout << "DIGITE EL NOMBRE DEL JUGADOR #" << i << ": ";
		std::getline(std::cin, nombreJugador);

		JugadorGenerico* nuevoJugador = new Jugador(nombreJugador, false);
		listaJugadores->insertarElemento(nuevoJugador);

		std::cout << std::endl << std::endl;
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
	system("cls");

	Lista::iterador tmp = listaJugadores->getInicio();
	Carta** mano;

	while (tmp) {
		std::cout << "----------------------" << std::endl;
		std::cout << tmp->getDato()->getNickname() << std::endl;
		mano = tmp->getDato()->getManoJugador()->getMano();
		int cartasMano = tmp->getDato()->getManoJugador()->getCantidad();
		for (int i = 0; i < cartasMano; ++i)
			dibujarCarta(mano[i]);
		tmp = tmp->getNext();
		std::cout << std::endl;
	}

	std::cin.get();
}

void Juego::dibujarCarta(Carta* c) {
	if (!c->estaBocaArriba()) {
		std::cout <<
			"\t\t.--------. " << std::endl <<
			"\t\t|XXXXXXXX| " << std::endl <<
			"\t\t|XXXXXXXX| " << std::endl <<
			"\t\t|XXXXXXXX| " << std::endl <<
			"\t\t|XXXXXXXX| " << std::endl <<
			"\t\t`--------' ";
	}
	else {
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
			std::cout <<
				"\t\t.--------. " << std::endl <<
				"\t\t|" << rango << " .--.  | " << std::endl <<
				"\t\t|  :():  | " << std::endl <<
				"\t\t|  ()()  | " << std::endl <<
				"\t\t|  '--'" << rango << " | " << std::endl <<
				"\t\t`--------' " << std::endl;
			break;
		case Palo::CORAZONES:
			std::cout <<
				"\t\t.--------. " << std::endl <<
				"\t\t|" << rango << " .--.  | " << std::endl <<
				"\t\t|  (\\/)  | " << std::endl <<
				"\t\t|  :\\/:  | " << std::endl <<
				"\t\t|  '--'" << rango << " | " << std::endl <<
				"\t\t`--------' " << std::endl;
			break;
		case Palo::ESPADAS:
			std::cout <<
				"\t\t.--------. " << std::endl <<
				"\t\t|" << rango << " .--.  | " << std::endl <<
				"\t\t|  :/\\:  | " << std::endl <<
				"\t\t|  (__)  | " << std::endl <<
				"\t\t|  '--'" << rango << " | " << std::endl <<
				"\t\t`--------' " << std::endl;
			break;
		case Palo::DIAMANTES:
			std::cout <<
				"\t\t.--------. " << std::endl <<
				"\t\t|" << rango << " .--.  | " << std::endl <<
				"\t\t|  :/\\:  | " << std::endl <<
				"\t\t|  :\\/:  | " << std::endl <<
				"\t\t|  '--'" << rango << " | " << std::endl <<
				"\t\t`--------' " << std::endl;
			break;
		}
	}
}