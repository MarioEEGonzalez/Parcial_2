#include "tablero.h"
#include "game.h"



int main()
{

    game juego;
    tablero tablero1;
    tablero1.imprimir_matriz();
    player jugador("mario",'-');
    tablero1.movimientosposibles(jugador.getpieza());
    tablero1.insert_piece(jugador);
    tablero1.imprimir_matriz();
    tablero1.movimientosposibles(jugador.getpieza());


return 0;



}
