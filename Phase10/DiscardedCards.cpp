#include "DiscardedCards.h"

DiscardedCards::DiscardedCards()
{
}

DiscardedCards::DiscardedCards(const DiscardedCards& discardedCards)
{
	*this = discardedCards;
}

DiscardedCards& DiscardedCards::operator=(const DiscardedCards& discardedCards)
{
	m_discardedCards = discardedCards.m_discardedCards;
	return *this;
}

DiscardedCards::~DiscardedCards()
{
	while (!m_discardedCards.empty())
	{
		m_discardedCards.pop();
	}
}

Card DiscardedCards::GetDiscardedCardFromTop()
{
	Card card = m_discardedCards.top();
	m_discardedCards.pop();
	return std::move(card);
}

Card DiscardedCards::ShowDiscardedCardFromTop() const
{
	return m_discardedCards.top();
}

void DiscardedCards::PutCardInDiscardedCards(Card&& card)
{
	m_discardedCards.push(std::move(card));
}

void DiscardedCards::Reintialize()
{
	while (!m_discardedCards.empty())
		m_discardedCards.pop();
}

int DiscardedCards::GetSize()
{
	return m_discardedCards.size();
}
