#include "game.h"
#include <iostream>
#include <fstream>
using namespace std;
game::game()
{

}
void game::start_game(){
    fstream registro;
    registro.open("registros.txt",ios::in | ios::out);

    if (!registro) {
    cout << "No se pudo abrir el archivo." << endl;
    }


    string linea;
    while (getline(registro, linea)) {
        // Procesa la línea como desees
        cout << linea << endl;
    }

    registro.close();
}
