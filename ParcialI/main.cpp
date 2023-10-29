#include "tablero.h"

void imprimir_matriz(string** matriz, int filas, int columnas){
    cout<<"  A B C D E F G H"<<endl;
    for (int i = 0; i<filas; i++){
        cout<<i<<" ";
        for (int u = 0; u<columnas; u++ ){
            cout<< matriz[i][u]<< " ";
        }
        cout<<i<<" ";
        cout<< endl;

    }
    cout<<"  A B C D E F G H"<<endl;
}

int main()
{


    tablero tablero1(8,8);
    imprimir_matriz(tablero1.matriz,8,8);
     return 0;
}
