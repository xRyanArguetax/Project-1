# Project-1


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
