#include "utiles.h"

/*
	Función para imprimir una cadena de caracteres.

	@param std::string
	@return void
*/
void imprimir(std::string cadena) {
	std::cout << cadena;
}

/*
	Función para limpiar la consola de la terminal.

	@return void
*/
void limpiar() {
	system("cls");
}

/*
	Función para esperar un enter por teclado.

	@return void
*/
void pausa() {
	system("pause");
}

/*
	Función para recibir una cadena de caracteres por teclado.

	@return std::string
*/
std::string getCadena() {
	std::string cadena;
	getline(std::cin, cadena);
	return cadena;
}

/*
	Función para recibir un número entero por teclado. 

	@return int
*/
int getEntero() {
	int numero;
	bool salir = false;

	while (!salir) {
		if (std::cin >> numero) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			salir = true;
		}
		else {
			imprimir("  - EL VALOR DEBE SER DE TIPO NUMERICO: ");
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
	}

	return numero;
}

/*
	Función para recibir un entero por teclado con un intervalo definido.

	@param int 
	@param int 
	@return int 
*/
int getEnteroEntre(int min, int max) {
	int numero;
	do {
		numero = getEntero();

		if (numero < min || numero > max) {
			imprimir("  - EL NUMERO DEBE ESTAR ENTRE " + convertirCadena(min) + " Y " + convertirCadena(max) + ": ");
		}

	} while (numero < min || numero > max);

	return numero;
}

/*
	Función para esperar un número definido de milisegundos.

	@return void
*/
void sleep(int miliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
}

/*
	Función para convertir una variable de tipo char a string.

	@param char
	@return string
*/
std::string convertirCadena(char caracter) {
	std::string cadena(1, caracter);
	return cadena;
}

/*
	Función para convertir una variable de tipo int a string.

	@param int
	@return string
*/
std::string convertirCadena(int numero) {
	return std::to_string(numero);
}



