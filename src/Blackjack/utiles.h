/*
	Descripción: 
		- Funciones básicas para gestionar la interacción con el usuario.
		- Las funciones válidan que las entradas sean del tipo correcto.
*/

#ifndef UTILES_H
#define UTILES_H

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

void imprimir(std::string);

void limpiar();

void pausa();

std::string getCadena();

int getEntero();

int getEnteroEntre(int, int);

void sleep(int);

std::string convertirCadena(char);

std::string convertirCadena(int);

#endif
