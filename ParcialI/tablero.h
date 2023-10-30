#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <string>
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


    char otroturno(char turnoactual);
    short unsigned movimientosposibles(char turnoactual);
    char getvalue(int fila, int columna);
    bool sandwichCheck(unsigned short fila, unsigned short columna, short sumax, short sumay,char micaracter);
    bool adyacentcelds(unsigned short fila, unsigned short columna, char turnoactual);
    bool checklimits(unsigned short fila, unsigned short columna, short sumax, short sumay);
    void insert_piece(player jugador);
    void change_color(unsigned short fila, unsigned short columna, short sumax, short sumay,player jugador);

};

#endif // TABLERO_H
