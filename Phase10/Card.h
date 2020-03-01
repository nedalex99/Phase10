#pragma once
#include <iostream>

class Card
{
public:

	//Enums which define the 3 parameters of the cards
	enum class Color
	{
		None,
		Red,
		Blue,
		Green,
		Yellow
	};

	enum class Number
	{
		None,
		One = 1,
		Deuce = 2,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		Seven = 7,
		Eight = 8,
		Nine = 9,
		Ten = 10,
		Eleven = 11,
		Twelve = 12
	};

	enum class Type
	{
		None,
		Wild,
		Skip,
		Normal
	};

public:

	//Constructors for all the card types 
	Card(Number number, Color color);
	Card(Color color);
	Card(Type type);

	//Rule of 5 applied on the card Class
	Card(const Card& card);
	Card& operator=(const Card& card);
	Card(Card&& card) noexcept;
	Card& operator=(Card&& card) noexcept;
	~Card();

public:

	//Overrode the writing operator
	friend std::ostream& operator<<(std::ostream& out, const Card& card);
	//Overrode the relational operators which are used to compare cards by their number
	friend bool operator==(const Card& card1, const Card& card2);
	friend bool operator<(const Card& card1, const Card& card2);
	friend bool operator>(const Card& card1, const Card& card2);

public:

	//Getters 
	Type GetType() const;
	Color GetColor() const;
	Number GetNumber() const;

public:

	//Additional functions used to compare the cards by color,number or type 
	bool ComparatorNumber(Card card1, Card card2);
	bool ComparatorColor(Card card1, Card card2);
	bool ComparatorType(Card card1, Card card2);

private:
	Color m_color;
	Number m_number;
	Type m_type;

};

