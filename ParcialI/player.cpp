#include "player.h"
#include <iostream>
player::player()
{


}

player::player(string usuario, string pieza)
{
    name=usuario;
    piece=pieza;
    score=0;
    if(piece=="-"){
        turn=true;
    }else if(piece=="*"){
        turn=false;
    }else{
        std::cout<<"Error en la creacion de usuario";
    }

}
