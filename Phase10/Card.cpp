#include "Card.h"

Card::Card(Number number, Color color) :
	m_number(number), m_color(color), m_type(Type::Normal) {}

Card::Card(Color color) :
	m_color(color), m_type(Type::Wild), m_number(Number::None) {}

Card::Card(Type type) :
	m_type(type), m_color(Color::Blue), m_number(Number::None) {}

Card::Card(const Card& card)
{
	*this = card;
}

Card& Card::operator=(const Card& card)
{
	m_type = card.m_type;
	m_number = card.m_number;
	m_color = card.m_color;
	return *this;
}

Card::Card(Card&& card) noexcept
{
	*this = std::move(card);
}

Card& Card::operator=(Card&& card) noexcept
{
	m_type = card.m_type;
	m_number = card.m_number;
	m_color = card.m_color;

	card.m_type = Card::Type::None;
	card.m_number = Card::Number::None;
	card.m_color = Card::Color::None;
	return *this;
}

Card::Type Card::GetType() const
{
	return m_type;
}

Card::Color Card::GetColor() const
{
	return m_color;
}

Card::Number Card::GetNumber() const
{
	return m_number;
}

bool Card::ComparatorNumber(Card card1, Card card2)
{
	return card1.GetNumber() < card2.GetNumber();
}

bool Card::ComparatorColor(Card card1, Card card2)
{
	return card1.GetColor() < card2.GetColor();
}

bool Card::ComparatorType(Card card1, Card card2)
{
	return card1.GetType() < card2.GetType();
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	switch (card.m_number)
	{
	case Card::Number::One: out << "One "; break;
	case Card::Number::Deuce: out << "Deuce "; break;
	case Card::Number::Three: out << "Three "; break;
	case Card::Number::Four: out << "Four "; break;
	case Card::Number::Five: out << "Five "; break;
	case Card::Number::Six: out << "Six "; break;
	case Card::Number::Seven: out << "Seven "; break;
	case Card::Number::Eight: out << "Eight "; break;
	case Card::Number::Nine: out << "Nine "; break;
	case Card::Number::Ten: out << "Ten "; break;
	case Card::Number::Eleven: out << "Eleven "; break;
	case Card::Number::Twelve: out << "Twelve "; break;
	}
	switch (card.m_color)
	{
	case Card::Color::Blue: out << "Blue "; break;
	case Card::Color::Green: out << "Green "; break;
	case Card::Color::Yellow: out << "Yellow "; break;
	case Card::Color::Red: out << "Red "; break;
	}
	switch (card.m_type)
	{
	case Card::Type::Normal: out << "Normal "; break;
	case Card::Type::Skip: out << "SkipCard "; break;
	case Card::Type::Wild: out << "WildCard "; break;
	}
	return out;
}

bool operator==(const Card& card1, const Card& card2)
{
	return card1.GetNumber() == card2.GetNumber() && card1.GetColor() == card2.GetColor() && card1.GetType() == card2.GetType();
}

bool operator<(const Card& card1, const Card& card2)
{
	if (card1.GetNumber() < card2.GetNumber()) return true;
	return false;
}

bool operator>(const Card& card1, const Card& card2)
{
	if (card1.GetNumber() > card2.GetNumber()) return true;
	return false;
}

Card::~Card()
{
}
