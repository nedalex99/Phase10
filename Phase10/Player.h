#pragma once

#include <string>

#include "PlayedCards.h"
#include"Deck.h"
#include "DiscardedCards.h"
#include "Rules.h"

class Player
{
public:
	//Rule of 5 apllied on the Player class
	Player(std::string playerName);
	Player(const Player& player);
	Player operator=(const Player& player);
	Player(Player&& other);
	Player& operator=(Player&& other);
	////Overrode the relational operators which compare 2 players
	bool operator!=(const Player& player);
	bool operator==(const Player& player);
	bool operator<(const Player& player);
	~Player() {};

public:

	//Overrode the writing operator
	friend std::ostream& operator<<(std::ostream& out, const Player& player);

public:

	//Getters and setters
	std::string GetPlayerName() const;
	void SetPlayerName(const std::string& playerName);
	//Function to print the cards in hand
	void PrintCardsInHand();
	int GetPhase() const;
	void SetPhase(const int& phase);
	int GetPoints();
	void SetPoints(const int& points);

	//Function used to calculate the points at the end of the round
	void CalculatePoints();

	//More getters and setters...
	bool GetIsSkipped();
	void SetIsSkipped(bool skip);
	bool GetHasCardsDown();
	void SetHasCardsDown(bool hasCardsDown);
	std::vector<Card>& GetCardsInHand();
	PlayedCards& GetPlayedCards();
	void GiveCard(Deck& deck);

	//Draw and put options
	void DrawCardFromDeck(Deck& deck);
	void DrawCardFromStack(DiscardedCards& discardedCards);
	void PutCardInStack(const int& indexOfCard, DiscardedCards& discardedCards);

	//Functions who sort the cards
	void SortCardsByNumber();
	void SortCardsByColor();
	void SortCardsByType();
	void SortCardsByChoice();

	//Functions to place cards down or in other players decks
	void PutCardsInPlayedCards();
	void PrintCardsInPlayedCards() const;
	void PutCardsInOtherPlayerDeck(Player& player);

	//Functions who give the players the options to place and draw cards
	void OptionDraw(Deck& deck, DiscardedCards& discardedCards);
	void OptionPut(DiscardedCards& discardedCards);

	//Function to reinitialize the player stats and cards
	void Reintialize();

private:
	std::string m_name;
	int m_phase;
	int m_points;
	std::vector<Card> m_cardsInHand;
	PlayedCards m_playedCards;
	bool m_isSkipped;
	bool m_hasCardsPutDown;
};


