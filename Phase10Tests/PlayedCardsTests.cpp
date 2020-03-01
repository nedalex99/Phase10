#include "pch.h"
#include "CppUnitTest.h"

#include "../Phase10/PlayedCards.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayedCardsTests
{
	TEST_CLASS(PlayedCardsTests)
	{
	public:

		TEST_METHOD(CopyConstructor)
		{
			PlayedCards playedCards1;
			Card card1(Card::Number::Seven, Card::Color::Red);
			Card card2(Card::Number::Eight, Card::Color::Red);
			playedCards1.PutCardInFirstDeck(std::move(card1));
			playedCards1.PutCardInSecondDeck(std::move(card1));
			PlayedCards playedCards2(playedCards1);

			Assert::IsTrue(playedCards1.GetFirstDeck() == playedCards2.GetFirstDeck());
			Assert::IsTrue(playedCards1.GetSecondDeck() == playedCards2.GetSecondDeck());
		}

		TEST_METHOD(EqualOperator)
		{
			PlayedCards playedCards1;
			Card card1(Card::Number::Seven, Card::Color::Red);
			Card card2(Card::Number::Eight, Card::Color::Red);
			playedCards1.PutCardInFirstDeck(std::move(card1));
			playedCards1.PutCardInSecondDeck(std::move(card1));
			PlayedCards playedCards2 = playedCards1;

			Assert::IsTrue(playedCards1.GetFirstDeck() == playedCards2.GetFirstDeck());
			Assert::IsTrue(playedCards1.GetSecondDeck() == playedCards2.GetSecondDeck());
		}

		TEST_METHOD(ItsASet)
		{
			PlayedCards playedCards;
			Card card1(Card::Number::Seven, Card::Color::Red);
			Card card2(Card::Number::Seven, Card::Color::Blue);
			Card card3(Card::Number::Seven, Card::Color::Green);
			Card card4(Card::Number::Seven, Card::Color::Yellow);
			playedCards.PutCardInFirstDeck(std::move(card1));
			playedCards.PutCardInFirstDeck(std::move(card2));
			playedCards.PutCardInFirstDeck(std::move(card3));
			playedCards.PutCardInFirstDeck(std::move(card4));

			Assert::IsTrue(true == playedCards.ItsASet(playedCards.GetFirstDeck()));
		}

		TEST_METHOD(ItsARun)
		{
			PlayedCards playedCards;
			Card card1(Card::Number::Six, Card::Color::Red);
			Card card2(Card::Number::Seven, Card::Color::Blue);
			Card card3(Card::Number::Eight, Card::Color::Green);
			Card card4(Card::Number::Nine, Card::Color::Yellow);
			playedCards.PutCardInFirstDeck(std::move(card1));
			playedCards.PutCardInFirstDeck(std::move(card2));
			playedCards.PutCardInFirstDeck(std::move(card3));
			playedCards.PutCardInFirstDeck(std::move(card4));

			Assert::IsTrue(true == playedCards.ItsARun(playedCards.GetFirstDeck()));
		}

		TEST_METHOD(ItsSameColor)
		{
			PlayedCards playedCards;
			Card card1(Card::Number::Six, Card::Color::Red);
			Card card2(Card::Number::Seven, Card::Color::Red);
			Card card3(Card::Number::Eight, Card::Color::Red);
			Card card4(Card::Number::Nine, Card::Color::Red);
			playedCards.PutCardInFirstDeck(std::move(card1));
			playedCards.PutCardInFirstDeck(std::move(card2));
			playedCards.PutCardInFirstDeck(std::move(card3));
			playedCards.PutCardInFirstDeck(std::move(card4));

			Assert::IsTrue(true == playedCards.ItsSameColor(playedCards.GetFirstDeck()));
		}
	};
}