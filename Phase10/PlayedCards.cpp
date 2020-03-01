#include "PlayedCards.h"

PlayedCards::PlayedCards()
{
}

PlayedCards::PlayedCards(const PlayedCards& playedCards)
{
	*this = playedCards;
}

PlayedCards& PlayedCards::operator=(const PlayedCards& playedCards)
{
	for (auto& card : playedCards.m_firstDeck)
	{
		m_firstDeck.push_back(card);
	}
	for (auto& card : playedCards.m_secondDeck)
	{
		m_secondDeck.push_back(card);
	}
	return *this;
}

bool PlayedCards::operator==(const PlayedCards& playedCards)
{
	if (this->m_firstDeck == playedCards.m_firstDeck && this->m_secondDeck == playedCards.m_secondDeck)
		return true;
	return false;
}

PlayedCards::~PlayedCards()
{
	m_firstDeck.clear();
	m_secondDeck.clear();
}

void PlayedCards::PutCardInFirstDeck(const Card& card)
{
	m_firstDeck.push_back(card);
}

void PlayedCards::PutCardInSecondDeck(const Card& card)
{
	m_secondDeck.push_back(card);
}

bool PlayedCards::ItsASet(const std::deque<Card>& checkedDeck)
{
	Card card = checkedDeck[0];
	for (int i = 0; i < checkedDeck.size(); i++)
		if (checkedDeck[i].GetType() == Card::Type::Skip)
			return false;
	for (int i = 1; i < checkedDeck.size(); i++)
	{
		if (card.GetType() != Card::Type::Wild)
		{
			if ((card.GetNumber() != checkedDeck[i].GetNumber()) && (checkedDeck[i].GetType() != Card::Type::Wild))
			{
				return false;
			}
		}
		else
			card = checkedDeck[i];
	}
	return true;
}

bool PlayedCards::ItsARun(std::deque<Card>& checkedDeck)
{
	for (int i = 0; i < checkedDeck.size(); i++)
		if (checkedDeck[i].GetType() == Card::Type::Skip)
			return false;
	Card card = checkedDeck[0];
	for (int i = 1; i < checkedDeck.size(); i++)
	{
		if (card.GetType() != Card::Type::Wild)
		{
			if ((((int)checkedDeck[i].GetNumber() - (int)card.GetNumber()) != 1 || ((int)checkedDeck[i].GetNumber() - (int)card.GetNumber()) == -1) && (checkedDeck[i].GetType() != Card::Type::Wild))
			{
				return false;
			}
		}
		card = checkedDeck[i];
	}
	return true;

}

bool PlayedCards::ItsSameColor(const std::deque<Card>& checkedDeck)
{
	Card card = checkedDeck[0];
	for (int i = 0; i < checkedDeck.size(); i++)
		if (checkedDeck[i].GetType() == Card::Type::Skip)
			return false;
	for (int i = 1; i < checkedDeck.size(); i++)
	{
		if (card.GetType() != Card::Type::Wild)
		{
			if ((card.GetColor() != checkedDeck[i].GetColor()) && (checkedDeck[i].GetType() != Card::Type::Wild))
			{
				return false;
			}
		}
		else
			card = checkedDeck[i];
	}
	return true;
}

std::deque<Card>& PlayedCards::GetFirstDeck()
{
	return m_firstDeck;
}

std::deque<Card>& PlayedCards::GetSecondDeck()
{
	return m_secondDeck;
}

void PlayedCards::Reinitialize()
{
	m_firstDeck.clear();
	m_secondDeck.clear();
}

std::ostream& operator<<(std::ostream& out, const PlayedCards& playedCards)
{
	if (playedCards.m_firstDeck.empty() && playedCards.m_secondDeck.empty())
	{
		out << "\nFirst deck: empty";
		out << "\nSecond deck: empty";
	}
	else
	{
		out << "\nFirst deck:\n ";
		for (auto& it : playedCards.m_firstDeck)
		{
			out << it << ", ";
		}
		out << "\nSecond deck:\n ";
		for (auto& it : playedCards.m_secondDeck)
		{
			out << it << ", ";
		}
	}
	return out;
}
