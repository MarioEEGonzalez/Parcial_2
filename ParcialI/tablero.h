#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <string>

using namespace std;


class tablero
{
public:
    char ** matriz;
    int filas = 8,columnas = 8;
    int cant_negras, cant_blancas,cant_vacios;

public:
    tablero();
    void imprimir_matriz( );
};

#endif // TABLERO_H
