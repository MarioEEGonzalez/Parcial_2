#include "game.h"
#include <iostream>
#include <fstream>
using namespace std;
game::game()
{

}
void game::print_register(){
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

void game::update_register(string player1, string player2, string winner, string score ){
    string new_string = "";
    string  hora= hour();
    string fecha = date();
    new_string= new_string + player1+"    "+ player2+"   " + hora + "  "+ fecha +"   "+ winner +"     "+ score;

    fstream registro;
    registro.open("registros.txt",ios::in | ios::out);

    if (!registro) {
        cout << "No se pudo abrir el archivo." << endl;
    }

    registro.seekp(0, ios::end);
    registro<< new_string<<endl;
    registro.close();


}


string game::date(){
    time_t tiempo_actual = time(nullptr);
    struct tm* local_time = localtime(&tiempo_actual);
    stringstream fecha_stream;
    fecha_stream << (local_time->tm_year + 1900) << "/"
                 << (local_time->tm_mon + 1) << "/"
                 << local_time->tm_mday;

    return fecha_stream.str();


}

string game::hour(){


    time_t tiempo_actual = time(nullptr);
    struct tm* local_time = localtime(&tiempo_actual);

    // Formatear la hora en formato de 24 horas
    char buffer[9]; // Suficiente espacio para "HH:MM:SS\0"
    strftime(buffer, sizeof(buffer), "%H:%M:%S", local_time);

    return buffer;

}
