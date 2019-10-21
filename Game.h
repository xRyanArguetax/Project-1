#ifndef Game_h
#define Game_h
#include "Player.h"
#include "Card.h"
#include <iostream>
using namespace std;


class Game {

private:
    vector<Player*> m_gamePlayers;
    vector<Card*> m_discardPile;
    vector<Card*> m_drawPile;
    

public:
    Game();
    ~Game();
    void addCardFromDrawPile(Card* card);
    void discardCardToDiscardPile(Card* card);
    void shuffleCards();
    Player* getPlayer(int playerIndex);
    void displayPlayerHand();
    void displayTopCardInDiscardPile();
    void displayTopCardInDrawPile();
    void loadingCards();
    void setupPlayers();
    void menu();
    void gamePlay();
};
#endif 