#ifndef Card_h
#define Card_h
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;


class Card {


//Will pass on to the source file Card.cpp
//Private variables
private:
    string pri_value;
    string pri_type;
    int pri_score;
    int pri_dealerScore;
    bool pri_inHand;


//Will be setters in card.cpp file and getters
public:
    Card(string value, string type, int score, int dealerScore);
    ~Card();
    string getValue();
    string getType();
    int getScore();
    int getDealerScore();
    void setValue(string username);
    void setType(string password);
    void setScore(int score);
    void setDealerScore(int dealerScore);
    void setInHand(bool isInHand);
    bool getInHand();
};
#endif