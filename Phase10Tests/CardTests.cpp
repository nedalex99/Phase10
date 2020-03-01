#include "pch.h"
#include "CppUnitTest.h"

#include "../Phase10/Card.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CardTests
{
	TEST_CLASS(CardTests)
	{
	public:

		TEST_METHOD(FirstConstructor)
		{
			Card card(Card::Number::Seven, Card::Color::Red);

			Assert::IsTrue(Card::Number::Seven == card.GetNumber());
			Assert::IsTrue(Card::Color::Red == card.GetColor());
			Assert::IsTrue(Card::Type::Normal == card.GetType());
		}

		TEST_METHOD(SecondConstructor)
		{
			Card card(Card::Color::Red);

			Assert::IsTrue(Card::Number::None == card.GetNumber());
			Assert::IsTrue(Card::Color::Red == card.GetColor());
			Assert::IsTrue(Card::Type::Wild == card.GetType());
		}

		TEST_METHOD(ThirdConstructor)
		{
			Card card(Card::Type::Skip);

			Assert::IsTrue(Card::Number::None == card.GetNumber());
			Assert::IsTrue(Card::Color::Blue == card.GetColor());
			Assert::IsTrue(Card::Type::Skip == card.GetType());
		}

		TEST_METHOD(Print)
		{
			Card card(Card::Number::Five, Card::Color::Green);

			std::stringstream stream;
			stream << card;
			Assert::AreEqual<std::string>("Five Green Normal ", stream.str(), L"If you see this message, card name is not the same");
		}

		TEST_METHOD(CopyConstructor)
		{
			Card card1(Card::Number::Three, Card::Color::Blue);
			Card card2(card1);

			Assert::IsTrue(card1 == card2);
		}

		TEST_METHOD(EqualOperator)
		{
			Card card1(Card::Number::Three, Card::Color::Blue);
			Card card2 = card1;

			Assert::IsTrue(card1 == card2);
		}

		TEST_METHOD(OperatorGreater)
		{
			Card card1(Card::Number::Ten, Card::Color::Green);
			Card card2(Card::Number::Five, Card::Color::Blue);

			Assert::IsTrue(true == card1 > card2);
		}

		TEST_METHOD(OperatorSmaller)
		{
			Card card1(Card::Number::Seven, Card::Color::Red);
			Card card2(Card::Number::Eleven, Card::Color::Blue);

			Assert::IsTrue(true == card1 < card2);
		}

		TEST_METHOD(OperatorEqualEqual)
		{
			Card card1(Card::Number::Deuce, Card::Color::Yellow);
			Card card2(Card::Number::Deuce, Card::Color::Yellow);

			Assert::IsTrue(true == (card1 == card2));
		}

		TEST_METHOD(GetType)
		{
			Card card(Card::Number::Eight, Card::Color::Red);

			Assert::IsTrue(Card::Type::Normal == card.GetType());
		}

		TEST_METHOD(GetColor)
		{
			Card card(Card::Number::One, Card::Color::Green);

			Assert::IsTrue(Card::Color::Green == card.GetColor());
		}

		TEST_METHOD(GetNumber)
		{
			Card card(Card::Number::Three, Card::Color::Blue);

			Assert::IsTrue(Card::Number::Three == card.GetNumber());
		}

		TEST_METHOD(ComparatorNumber)
		{
			Card card1(Card::Number::Five, Card::Color::Red);
			Card card2(Card::Number::Eight, Card::Color::Red);

			Assert::IsTrue(true == card1.ComparatorNumber(card1, card2));
		}

		TEST_METHOD(ComparatorColor)
		{
			Card card1(Card::Number::Deuce, Card::Color::Blue);
			Card card2(Card::Number::Ten, Card::Color::Green);

			Assert::IsTrue(true == card1.ComparatorColor(card1, card2));
		}

		TEST_METHOD(ComparatorType)
		{
			Card card1(Card::Color::Red);
			Card card2(Card::Type::Skip);

			Assert::IsTrue(true == card1.ComparatorType(card1, card2));
		}
	};
}
