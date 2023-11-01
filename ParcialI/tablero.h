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
    int cant_negras = 2 ,cant_blancas = 2,cant_vacios;
    short unsigned cantmovimientosposibles;
public:
    tablero();
    void imprimir_matriz( );
    short validacionentrada1(char entrada);
    int validacion_entrada_fila(int fila);

    char otroturno(char turnoactual);
    void movimientosposibles(char turnoactual);
    char getvalue(int fila, int columna);
    bool sandwichCheck(unsigned short fila, unsigned short columna, short sumax, short sumay,char micaracter);
    bool adyacentcelds(unsigned short fila, unsigned short columna, char turnoactual);
    bool checklimits(unsigned short fila, unsigned short columna, short sumax, short sumay);
    bool checklimits2(unsigned short fila, unsigned short columna, short sumax, short sumay);
    void insert_piece(player jugador);
    void change_color(unsigned short fila, unsigned short columna, short sumax, short sumay,player jugador);

};

#endif // TABLERO_H
