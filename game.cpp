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