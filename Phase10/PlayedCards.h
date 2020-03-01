#pragma once
#include "Card.h"

#include <deque>
#include <algorithm>

class PlayedCards
{
public:

	//Rule of 3 applied on the PlayedCards class
	PlayedCards();
	PlayedCards(const PlayedCards& playedCards);
	PlayedCards& operator=(const PlayedCards& playedCards);
	//Overrode the == operator
	bool operator==(const PlayedCards& playedCards);
	~PlayedCards();

	//Functions which let you add cards in the decks
	void PutCardInFirstDeck(const Card& card);
	void PutCardInSecondDeck(const Card& card);

	//Functions that check if the decks comply with the rules of the phases
	bool ItsASet(const std::deque<Card>& checkedDeck);
	bool ItsARun(std::deque<Card>& checkedDeck);
	bool ItsSameColor(const std::deque<Card>& checkedDeck);

	//Overrode the writing operator
	friend std::ostream& operator<<(std::ostream& out, const PlayedCards& playedCards);

	//Getters
	std::deque<Card>& GetFirstDeck();
	std::deque<Card>& GetSecondDeck();

	void Reinitialize();

private:
	std::deque<Card> m_firstDeck;
	std::deque<Card> m_secondDeck;
};