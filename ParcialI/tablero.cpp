#include "tablero.h"
tablero::tablero(){

    matriz =  new char* [filas];

        for (unsigned short i = 0;i<filas;i++){
            matriz[i]= new char [columnas];
        }

    for (unsigned short i = 0; i<filas; i++){
        for (unsigned short u = 0; u<columnas; u++ ){

                if (i==(columnas/2) && u== i || i == (columnas/2)-1 && u == i) {
                matriz[i][u] = '*';
            }
            else if (u  ==(filas/2) && i == u-1 || u  ==(filas/2)-1 && i == u+1 ){
                matriz[i][u] = '-';
            }
            else{
                matriz[i][u]= 'o';
            }
        }
    }
}

void tablero::imprimir_matriz(){
    cout<<"  A B C D E F G H"<<endl;
    for (unsigned short i = 0; i<filas; i++){
        cout<<i<<" ";
        for (unsigned short u = 0; u<columnas; u++ ){
            cout<< matriz[i][u]<< " ";
        }
        cout<<i<<" ";
        cout<< endl;

    }
    cout<<"  A B C D E F G H"<<endl;
}

void tablero::movimientosposibles(){
    cout<<"  A B C D E F G H"<<endl;
    for (int i = 0; i<filas; i++){
        cout<<i<<" ";
        for (int u = 0; u<columnas; u++ ){
            if(matriz[i][u]=='o'){
                bool status=adyacentcelds(i,u);
                if(status){
                    cout<<"X"<<" ";
                }else
                    cout<<'o'<<" ";

            }else
                cout<< matriz[i][u]<< " ";
        }
        cout<<i<<" ";
        cout<< endl;

    }
    cout<<"  A B C D E F G H"<<endl;
}
bool tablero::adyacentcelds(unsigned short fila, unsigned short columna){
    bool arriba,abajo,izquierda,derecha,diagonal1,diagonal2,diagonal3,diagonal4,flag;
    if(columna!=0){
    if(getvalue(fila,columna-1)=='-'){
        arriba=sandwichCheck(fila,columna,0,-1);
    }else
        arriba=false;
    }else
        arriba=false;

    if (columna!=(columnas-1)){
    if(getvalue(fila,columna+1)=='-'){
        abajo=sandwichCheck(fila,columna,0,+1);
    }else
        abajo=false;
    }
    else abajo=false;

    if(fila!=0){
    if(getvalue(fila-1,columna)=='-'){
        izquierda=sandwichCheck(fila,columna,-1,0);
    }else
        izquierda=false;
    }
    else izquierda=false;

    if(fila!=filas-1){
    if(getvalue(fila+1,columna)=='-'){
        derecha=sandwichCheck(fila,columna,1,0);}
    else
        derecha=false;
    }else derecha=false;

    if(columna!=columnas-1 && fila!=filas-1){
    if(getvalue(fila+1,columna+1)=='-'){
        diagonal1=sandwichCheck(fila,columna,1,1);}
    else
        diagonal1=false;
    }else diagonal1=false;

    if(columna!=columnas-1 && fila!=0){
    if(getvalue(fila-1,columna+1)=='-'){
        diagonal2=sandwichCheck(fila,columna,-1,1);}
    else
        diagonal2=false;
    }else diagonal2=false;

    if(columna!=0 && fila!=filas-1){
    if(getvalue(fila+1,columna-1)=='-'){
        diagonal3=sandwichCheck(fila,columna,1,-1);}
    else diagonal3=false;
    }else diagonal3=false;

    if(columna!=0 && fila!=0){
    if(getvalue(fila-1,columna-1)=='-'){
        diagonal4=sandwichCheck(fila,columna,-1,-1);}
    else diagonal4=false;
    } else diagonal4=false;

    if(arriba||abajo||derecha||izquierda||diagonal4||diagonal3||diagonal2||diagonal1){
    flag=true;
    }else
    flag=false;
    return flag;
}
bool tablero::sandwichCheck(unsigned short fila, unsigned short columna, short sumax, short sumay){
    bool flag=checklimits(fila,columna,sumax,sumay);
    if(flag){
        if(matriz[fila+sumax][columna+sumay]=='o'){
          flag= false;
        }
        else if(matriz[fila+sumax][columna+sumay]=='*'){
          flag=true;
        }
        else{
          flag=sandwichCheck(fila+sumax,columna+sumay,sumax,sumay);
        }
    }
    return flag;
}
bool tablero:: checklimits(unsigned short fila, unsigned short columna, short sumax, short sumay){
    bool flag=true;
    if(fila==8||fila==0){
        if(sumax!=0){
            flag= false;
        }
    }
    if(columna==8||columna==0){
        if(sumay!=0){
            flag= false;
        }
    }
    return flag;
}
char tablero::getvalue(int fila, int columna){
    return matriz[fila][columna];

}
