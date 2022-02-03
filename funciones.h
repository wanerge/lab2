#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

void problema1();
void problema2();
void problema3();
void problema4();
void problema5();
void problema6();
void problema7();
void problema8();
void problema9();
void problema10();
void problema11();
void problema12();
void problema13();
void problema14();
void problema15();
void problema16();
void problema17();
void problema18();

void entrada_caracteres(char *cadena, unsigned short int longitud);
void iniciar_matriz(char **matriz, unsigned short int filas, unsigned short int colum, char valor_ini);
bool validar_cuadrado(unsigned short int **matriz, unsigned short int tam);
void interseccion_vectores(unsigned short int *vector1, unsigned short int *vector2);

template <typename T>
void mostrar_matriz(T **matriz, unsigned short int filas, unsigned short int colum, bool guia);

template <typename R>
void rotar_matriz(R **matriz, unsigned short int tam);

#endif // FUNCIONES_H
