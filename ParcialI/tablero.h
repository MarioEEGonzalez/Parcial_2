#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <string>
#define myturn *;
#define otherturn -;
#include "player.h"
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



    void movimientosposibles();
    char getvalue(int fila, int columna);
    bool sandwichCheck(unsigned short fila, unsigned short columna, short sumax, short sumay);
    bool adyacentcelds(unsigned short fila, unsigned short columna);
    bool checklimits(unsigned short fila, unsigned short columna, short sumax, short sumay);

};

#endif // TABLERO_H
