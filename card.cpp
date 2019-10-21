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