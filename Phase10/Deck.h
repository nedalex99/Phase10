#pragma once
#include "Card.h"
#include <vector>
#include <random>

class Deck
{
public:

	//Constructor of the deck which initialize all the cards
	Deck();

public:

	//Overrode the writing operator
	friend std::ostream& operator<<(std::ostream& out, const Deck& deck);

public:

	int GetSize();
	void Shuffle();
	Card GetTopCard();
	void Reinitialize();
private:
	std::vector<Card> m_cards;

};

