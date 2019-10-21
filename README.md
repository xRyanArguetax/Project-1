# Project-1
# UNO
# Ryan Argueta
# CSC 17C
# 10/20/19

## Introduction 
The aim of the game is to be the first player to score 500 points, achieved (usually over several rounds of play) by being the first to play all of one's own cards and scoring points for the cards still held by the other players.
The deck consists of 108 cards: four each of "Wild" and "Wild Draw Four," and 25 each of four different colors (red, yellow, green, blue). Each color consists of one zero, two each of 1 through 9, and two each of "Skip," "Draw Two," and "Reverse." These last three types are known as "action cards."
To start a hand, seven cards are dealt to each player, and the top card of the remaining deck is flipped over and set aside to begin the discard pile. The player to the dealer's left plays first unless the first card on the discard pile is an action or Wild card (see below). On a player's turn, they must do one of the following:
play one card matching the discard in color, number, or symbol
play a Wild card, or a playable Wild Draw Four card (see restriction below)
draw the top card from the deck, then play it if possible
Cards are played by laying them face-up on top of the discard pile. Play proceeds clockwise around the table.
Action or Wild cards have the following effects:
 
 
  
Card
Effect when played from hand
Effect as first discard
Skip
Next player in sequence misses a turn
Player to dealer's left misses a turn
Reverse
Order of play switches directions (clockwise to counterclockwise, or vice versa)
Dealer plays first; play proceeds counterclockwise
Draw Two (+2)
Next player in sequence draws two cards and misses a turn
Player to dealer's left draws two cards and misses a turn
Wild
Player declares the next color to be matched (may be used on any turn even if the player has matching color)
Player to dealer's left declares the first color to be matched and plays a card in it
Wild Draw Four/Draw Four Wild (+4 and wild)
Player declares the next color to be matched; next player in sequence draws four cards and misses a turn. May be legally played only if the player has no cards of the current color (see Penalties).
Return card to the deck, shuffle, flip top card to start discard pile
A player who draws from the deck must either play or keep that card and may play no other card from their hand on that turn.
A player may play a Wild card at any time, even if that player has other playable cards.
A player may play a Wild Draw Four card only if that player has no cards matching the current color. The player may have cards of a different color matching the current number or symbol or a Wild card and still play the Wild Draw Four card. A player who plays a Wild Draw Four may be challenged by the next player in sequence (see Penalties) to prove that their hand meets this condition.
If the entire deck is used during play, the top discard is set aside and the rest of the pile is shuffled to create a new deck. Play then proceeds normally.

 
 
 
## Summary
Project Size : 564 lines
This project included concepts we went over such as vectors, algorithms, and iterators.
This project is a basic game of UNO.
I could improve the game more for example, if player one puts 1 yellow card down and its player two turn, if another player has exactly a 1 yellow card, they can put it down, skipping player two for being to slow to put a card down.

This project opened me to more experience using STL though at first I was having a little trouble here and there, but using the STL book as my reference, the book helped me to use the STL more properly. This project definitely was very challenging. To be honest, I'm not pleased with my project, but doing this game did make me learn many things throughout the development. Overall, the thinking I put in this was fun seeing the game UNO work.

## Description
The point of this game is to be the first to have no cards left to play. 
Whenever it is your turn, you place a card down, making you have 1 less card on your deck.
 
 
 
 # Main
 ```c++
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
```
 


# Card.cpp
```c++
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;


//Constructor, included from private variables in Card.h
Card::Card(string value, string type, int score, int dealerScore) {
    pri_value = value;
    pri_type = type;
    pri_score = score;
    pri_dealerScore = dealerScore;
    pri_inHand = false;
}


//Getters
string Card::getValue() {
    return pri_value;
}


string Card::getType() {
    return pri_type;
}


int Card::getScore(){
    return pri_score;
}


int Card::getDealerScore(){
    return pri_dealerScore;
}


//Setters
void Card::setValue(string value){
    pri_value = value;
}


void Card::setType(string type){
    pri_type = type;
}
void Card::setScore(int score){
    pri_score = score;
}


void Card::setDealerScore(int dealerScore){
    pri_dealerScore = dealerScore;
};


void Card::setInHand(bool isInHand){
    pri_inHand = isInHand;
}


bool Card::getInHand(){
    return pri_inHand;
}
```
Member Function | Description |
| --------------| ---- |
| Card::Card(string value, string type, int score, int dealerScore) | Constructor |
| void Card::setValue(string value) | Sets value |
| void Card::setType(string type) | Sets type |
| void Card::setScore(int score) | Sets score |
| void Card::setDealerScore(int dealerScore) | sets dealerScore |
| void Card::setInHand(bool isInHand) | Sets isInHand |
| string Card::getValue() | returns value |
| string Card::getType() | returns type |
| int Card::getScore() | returns score |
| int Card::getDealerScore() | returns dealerScore |


# Game.cpp
```c++
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>


//Header Files
#include "Game.h"
#include "Player.h"
#include "Card.h"
using namespace std;


void loadingCards();
void gamePlay();
void setupPlayers();
void menu();


string displayPlayerHand();


vector<Card*> cards;
vector<Card*> drawPile;

//Variables
string value;
string type;
int score;
int dealerScore;


vector<Player*> players;
Game::Game(){
}


Game::~Game(){
}


void Game::shuffleCards(){
}


void Game::addCardFromDrawPile(Card* card){
    m_discardPile.push_back(card);
}


void Game::discardCardToDiscardPile(Card* card){
    m_drawPile.push_back(card);
}


Player* Game::getPlayer(int playerIndex){
    if (playerIndex >= 0 && playerIndex < m_gamePlayers.size()){
        return m_gamePlayers[playerIndex];
    }
    else{
        return nullptr;
    }
}


void Game::displayPlayerHand(){
    for (auto it = m_gamePlayers.begin(); it != m_gamePlayers.end(); ++it){
        Player* player = *it;
        //cout << player->displayPlayerHand() << endl; //deference the pointer address to grab the function
    }
}


void Game::displayTopCardInDiscardPile(){
    while (m_discardPile.back() != 0)
    {
        m_discardPile.push_back(m_discardPile.back() - 1);
    }
    cout << "Top Card in Discard Pile:";
    for (unsigned i = 0; i < m_discardPile.size(); i++){
        cout << ' ' << m_discardPile[0];
    }
}


void Game::displayTopCardInDrawPile(){
    while (m_drawPile.back() != 0)
    {
        m_drawPile.push_back(m_drawPile.back() - 1);
    }
    cout << "Top Card in Draw Pile:";
    for (unsigned i = 0; i < m_drawPile.size(); i++){
        cout << ' ' << m_drawPile[0];
    }
}


void Game::loadingCards(){
    ifstream file("Deck.txt");
    cout << "\n-- LET'S PLAY UNO --" << endl << "\n";
    if (file.is_open()){
        string line;
        while (getline(file, line)){
            file >> ws;
            stringstream ss;
            ss << line;
            Card* card = nullptr;
            ss >> value;
            ss >> type;
            ss >> score;
            ss >> dealerScore;
            srand(time(NULL));
            // Make the new card and put it in the cards vector
            card = new Card(value, type, score, dealerScore);
            cards.push_back(card);
        }
        // Scramble the vector
        random_shuffle(cards.begin(), cards.end());
    }
    setupPlayers();
}


void Game::setupPlayers() {
    int numPlayers = 4;
    Player* player1 = new Player("Karla", "nah", 0);
    Player* player2 = new Player("Quintin", "quin", 0);
    Player* player3 = new Player("Ferny", "fern", 0);
    Player* player4 = new Player("Carlos", "car", 0);


    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);
    players.push_back(player4);
    int playerIndex = 0;


    for (int i = 1; i <= 7 * numPlayers; ++i){
        // If the number we look at is divisible by 7, then it means we just hit the first 7 items
        if (i < cards.size()) {
            // Put first element into the cards pile 
            players[playerIndex]->addCardFromDrawPile(cards[i - 1]);
            /* Say that the card is in a hand (so when you go to draw a new card from the pile, you'll interate through till you find a card
            that has getInHand() == false and then you set it to true because it gets put in the user's hand. When you want to put a card back
            in the pile, you would search for the card in the cards vector and then when you find that card go cards[i]->setInHand(false)
            because it is no longer in someone's hand */
            cards[i]->setInHand(true);
        }
        if (i % 7 == 0){
            // Move to putting cards in the hand of the next player
            playerIndex++;
        }
        Card* remainingCards = cards[cards.size() - (player1->m_playerHand.size() * 4)];
        drawPile.push_back(remainingCards);
    }


    string displayPlayer1Cards = player1->displayPlayerHand();
    string displayPlayer2Cards = player2->displayPlayerHand();
    string displayPlayer3Cards = player3->displayPlayerHand();
    string displayPlayer4Cards = player4->displayPlayerHand();


    for (int i = 0; i < 2; --i){
        cout << displayPlayer4Cards << endl;
        player4->playGame();
        cout << displayPlayer1Cards << endl;
        player1->computerPlayerGame();
        cout << displayPlayer2Cards << endl;
        player2->computerPlayerGame();
        cout << displayPlayer3Cards << endl;
        player3->computerPlayerGame();
    }
}


void Game::menu() {
    // Declare other variables
    int nMenuChoice = 0;
    cout << setw(50) << "UNO GAME" << endl;
    cout << setw(53) << "--------- \n" << endl;


    // Create while loop until to run till 4 is picked which ends the program.
    while (nMenuChoice != 4) {
        cout << setw(50) << "Main Menu" << endl;
        cout << setw(60) << "-----------------------------------" << endl;
        cout << setw(52) << "1. Start Game\n";
        cout << setw(50) << "2. Tutorial\n";
        cout << setw(58) << "3. Leadership Board\n";
        cout << setw(46) << "4. Quit\n";
        cout << "\nPick a choice: ";
        cin >> nMenuChoice;
        // Switch based on user input
        switch (nMenuChoice) {
            // Start game 
        case 1:
            loadingCards();
            break;


            // Tutorial
        case 2:
            cout << "--- HOW TO PLAY UNO ---" << endl;
            cout << "Rules:" << endl
                << "1. Play a card by entering the number on the left of the card." << endl 
                << "EXAMPLE : 1. 5 - Red" << endl
                <<"          ^" << endl <<endl
                << "2. A card can only be played if the color or the title of the card is same " << endl
                << "   as the card on the pile." << endl
                << "3. Draw a card if you cannot play any card, or you want to have more cards just" << endl
                << "   for fun." << endl
                << "4. The last card in your hand can be a power card." << endl
                << "5. Draw Two and Draw Four will cause the next user to be skipped." << endl
                << "6. Wild card can be played at any time without restriction, but for Draw Four," << endl
                << "   the computer players might challenge you.  Draw Four can only be played when" << endl
                << "   you have no same colour/ title card in your hand.  If you are found guilty," << endl
                << "   you will draw 4 cards as punishment, but you still can choose your colour." << endl
                << "   If challenge failed, the challenger will draw 6 cards instead of 4." << endl
                << "7. A game will end, when one of the player had finished all the cards in his " << endl
                << "   hand, or when the cards had ran out of stock." << endl << endl;
            break;


            // Leadership Board  
        case 3:
            //processLeadershipBoard();
            break;


            // Quit condition   
        case 4:
            break;

            
            // Invalid selection    
        default:
            cout << "Invalid menu Choice!\n";
            break;
        }
    }
};
```
Member Function | Description |
| -------------- | ---------- |
| void Game::addCardFromDrawPile(Card* card) | Sets to push back the discardPile |
| void Game::discardCardToDiscardPile(Card* card) | Sets card to discardPile |
| void Game::displayPlayerHand() | Sets card to display |
| void Game::displayTopCardInDiscardPile() | Sets most recent card played on top to display |
| void Game::displayTopCardInDrawPile() | Sets drawPile to show top card |
| void Game::loadingCards() | Sets cards to display in every players hand |
| void Game::setupPlayers() | Sets the players name and pass|
| void Game::menu() | Sets up the menu |


# player.cpp
```c++
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
```
