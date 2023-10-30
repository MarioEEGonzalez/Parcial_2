#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;
class player
{

public:
    player();
    player(string usuario, string pieza);

private:
    string name;
    bool turn;
    short unsigned score;
    string piece;

};

#endif // PLAYER_H
