#pragma once
#include <stack>
#include "Card.h"

class DiscardedCards
{
public:

	//Constructor and rule of 3 applied on the DiscardedCards class
	DiscardedCards();
	DiscardedCards(const DiscardedCards& discardedCards);
	DiscardedCards& operator=(const DiscardedCards& discardedCards);
	~DiscardedCards();

public:

	//Functions that ensure class functionality
	Card GetDiscardedCardFromTop();
	Card ShowDiscardedCardFromTop() const;
	void PutCardInDiscardedCards(Card&& card);
	void Reintialize();
	int GetSize();

private:
	std::stack<Card> m_discardedCards;
};

