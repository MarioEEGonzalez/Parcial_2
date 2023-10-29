#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <string>

using namespace std;


class tablero
{
public:
    string ** matriz;
    int cant_negras, cant_blancas,cant_vacios;

public:
    tablero(int filas,int columnas);
};

#endif // TABLERO_H
