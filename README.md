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

 
 
 
 
 


# Card.cpp
Member Function | Dsc |
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

Member Function | Dsc |
| -------------- | ---- |
| void Game::addCardFromDrawPile(Card* card) | Sets to push back the discardPile |
| void Game::discardCardToDiscardPile(Card* card) | Sets card to discardPile |
| void Game::displayPlayerHand() | Sets card to display |
| void Game::displayTopCardInDiscardPile() | Sets most recent card played on top to display |
| void Game::displayTopCardInDrawPile() | Sets drawPile to show top card |
| void Game::loadingCards() | Sets cards to display in every players hand |
| void Game::setupPlayers() | Sets the players name and pass|
| void Game::menu() | Sets up the menu |
