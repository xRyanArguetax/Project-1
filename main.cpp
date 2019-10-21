#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>


//Inlcude Header Files 
#include "Game.h"     //Game header file
#include "Player.h"   //Player header file
#include "Card.h"     //Card header file
using namespace std;


int main() {
    //create instances of files we've created
    Game* unoGame = new Game;
    unoGame->menu();
    delete unoGame;
    system("pause");
    return 0;
};