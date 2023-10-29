#include "tablero.h"

tablero::tablero(int filas, int columnas){

    matriz =  new string* [filas];

        for (int i = 0;i<filas;i++){
            matriz[i]= new string [columnas];
        }

    for (int i = 0; i<filas; i++){
        for (int u = 0; u<columnas; u++ ){

                if (i==(columnas/2) && u== i || i == (columnas/2)-1 && u == i) {
                matriz[i][u] = "*";
            }
            else if (u  ==(filas/2) && i == u-1 || u  ==(filas/2)-1 && i == u+1 ){
                matriz[i][u] = "-";
            }
            else{
                matriz[i][u]= "o";
            }
        }
    }
}


