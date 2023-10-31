#include "game.h"
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "tablero.h"
game::game()
{

}
void game::startgame(){

    string n="0";
    std::cout<<"________________________________________"<<endl;
    std::cout<<"Bienvenido, que accion desea realizar: "<<endl;
    std::cout<<"1. Visualizar registros."<<endl;
    std::cout<<"2. Nueva partida."<<endl;
    std::cin>>n;
    if(n=="1"){

    }else if(n=="2"){
        nuevapartida();

    }else{
        std::cout<<"Opcion invalida";
        startgame();
    }


}
void game::nuevapartida()
{
    string use1,use2,X;
    std::getline(std::cin,X);
    std::cout<<"Ingrese el nombre del jugador que maneja las negras: ";
    std::getline(std::cin,use1);
    std::cout<<"Ingrese el nombre del jugador que maneja las blancas: ";
    std::getline(std::cin,use2);
    player usuarionegro(use1,'-'),usuarioblanco(use2,'*');
    tablero tablero1;
    unsigned short z = 0;
    while (tablero1.cant_vacios != 0 && z < 2){

        if (usuarionegro.turn){
            tablero1.movimientosposibles(usuarionegro.getpieza());
            if (tablero1.cantmovimientosposibles != 0){
                tablero1.insert_piece(usuarionegro);
                z=0;
            }
            else{
                usuarioblanco.turn = true;
                usuarionegro.turn = false;
                z++;
            }
        }
        else if (usuarioblanco.turn){
            tablero1.movimientosposibles(usuarioblanco.getpieza());
            if (tablero1.cantmovimientosposibles != 0){
                tablero1.insert_piece(usuarionegro);
                z= 0;
            }
            else{
                usuarioblanco.turn = true;
                usuarionegro.turn = false;
                z++;
            }
        }
    }


}

void game::print_register(){
    fstream registro;
    registro.open("registros.txt",ios::in | ios::out);

    if (!registro) {
    cout << "No se pudo abrir el archivo." << endl;
    }


    string linea;
    while (getline(registro, linea)) {

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
