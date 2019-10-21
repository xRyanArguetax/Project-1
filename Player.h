#ifndef Player_h
#define Player_h
#include "Card.h"
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;


class Player {

private:
    string m_username;
    string m_password;
    int m_score;
    vector<Card*> m_drawPile;
    void discardCardToDiscardPile(Card* playerCard);
    

public:
    Player(string username, string password, int score);
    ~Player();
    string getUsername();
    string getPassword();
    int getScore();
    void setUsername(string username);
    void setPassword(string password);
    void setScore(int score);
    string displayPlayerHand();
    void addCardFromDrawPile(Card* playerCard);
    void retrieveCardsFromDrawPile(Card* playerCard);
    void playGame();
    void computerPlayerGame();
    vector<Card*> m_playerHand;
};
#endif 