#include "Deck.h"

Deck::Deck()
{
	static const Card::Number nums[12] =
	{
		Card::Number::One,
		Card::Number::Deuce,
		Card::Number::Three,
		Card::Number::Four,
		Card::Number::Five,
		Card::Number::Six,
		Card::Number::Seven,
		Card::Number::Eight,
		Card::Number::Nine,
		Card::Number::Ten,
		Card::Number::Eleven,
		Card::Number::Twelve
	};
	static const Card::Color colors[4] =
	{
		Card::Color::Red,
		Card::Color::Blue,
		Card::Color::Green,
		Card::Color::Yellow
	};
	static const Card::Type types[3] =
	{
		Card::Type::Normal,
		Card::Type::Skip,
		Card::Type::Wild
	};

	for (int indexOfDeck = 0; indexOfDeck < 2; indexOfDeck++)
	{
		for (int indexOfNumber = 0; indexOfNumber < 12; indexOfNumber++)
		{
			for (int indexOfColor = 0; indexOfColor < 4; indexOfColor++)
			{
				m_cards.push_back(Card(nums[indexOfNumber], colors[indexOfColor]));
			}
		}
	}

	for (int indexOfSkipCard = 0; indexOfSkipCard < 4; indexOfSkipCard++)
	{
		m_cards.push_back(Card(Card::Type::Skip));
	}

	for (int indexOfWildCard = 0; indexOfWildCard < 2; indexOfWildCard++)
	{
		for (int indexOfColor = 0; indexOfColor < 4; indexOfColor++)
		{
			m_cards.push_back(Card(colors[indexOfColor]));
		}
	}
}

int Deck::GetSize()
{
	return m_cards.size();
}

void Deck::Shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_cards.begin(), m_cards.end(), g);
}

Card Deck::GetTopCard()
{
	Card card = m_cards.back();
	m_cards.pop_back();
	return card;
}

void Deck::Reinitialize()
{
	m_cards.clear();
	*this = *new Deck();
}

std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
	for (const auto& it : deck.m_cards)
	{
		out << it << "\n";
	}
	return out;
}
