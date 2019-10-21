#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// Declare other variables
int nUserNum = 0;
int numToDelete = 0;
Player::Player(string username, string password, int score) {
    m_username = username;
    m_password = password;
    m_score = score;
}


string Player::getUsername() {
    return m_username;
}


string Player::getPassword() {
    return m_password;
}


int Player::getScore(){
    return m_score;
}


void Player::setUsername(string username){
    m_username = username;
}


void Player::setPassword(string password){
    m_password = password;
}


void Player::setScore(int score){
    m_score = score;
}


void Player::addCardFromDrawPile(Card* card){
    m_playerHand.push_back(card);
}


void Player::retrieveCardsFromDrawPile(Card* card){
    m_drawPile.push_back(card);
}


void Player::discardCardToDiscardPile(Card* card){
    vector<Card*>::iterator found = find(m_playerHand.begin(), m_playerHand.end(), card);
    if (found != m_playerHand.end()){
        m_playerHand.erase(found);
    }
}


string Player::displayPlayerHand(){
    stringstream sPlayerHand;
    sPlayerHand << "Player's " << m_username << endl;
    for (int i = 0; i < m_playerHand.size(); i++){
        sPlayerHand << i + 1 << ". " << m_playerHand[i]->getValue() << " - " << m_playerHand[i]->getType() << endl;
        m_playerHand[i]->setInHand(false);
    }
    return sPlayerHand.str();
}


void Player::playGame(){
    stringstream sPlayerHand;
    sPlayerHand << "Player's " << m_username << endl;
    int option = 0;


    for (int i = 0; i < m_playerHand.size(); i++){
        m_playerHand[i]->setInHand(false);
        sPlayerHand << option  << ". " << m_playerHand[i]->getValue() << " - " << m_playerHand[i]->getType() << endl;
    }


    cout << "Enter a choice for " << m_username << ": " ;
    cin >> option;
    cout << "You have selected the card: (" << m_playerHand[option-1]->getValue() << " - " << m_playerHand[option-1]->getType() << ").\n\n";
    //if value and type matches with top card, then remove, else, return error message
    clock_t start;
    int pause = 1000;


    for (int i = 0; i < 1; i++){
        cout << "Loading next player's hands..." << flush << "\n\n";
        start = clock();
        while (clock() < start + pause);
    }
}


void Player::computerPlayerGame() {
    Card* card = m_playerHand[rand() % m_playerHand.size()];
    stringstream sPlayerHand;
    sPlayerHand << "Player " << m_username << "\n\n";
    int option = 0;
    for (int i = 0; i < m_playerHand.size(); i++){
        sPlayerHand << option << ". " << m_playerHand[i]->getValue() << " - " << m_playerHand[i]->getType() << endl;
    }
    cout << m_username << " have selected the card: (" << card->getValue() << " - " << card->getType() <<  ").\n\n"; 
    clock_t start;
    int pause = 2000;
    for (int i = 0; i < 1; i++){
        cout << "Loading next player's hands..." << flush << "\n\n";
        start = clock();
        while (clock() < start + pause);
    }

    
};