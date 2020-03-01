#include "pch.h"
#include "CppUnitTest.h"

#include "../Phase10/DiscardedCards.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DiscardedCardsTests
{
	TEST_CLASS(DiscardedCardsTests)
	{
	public:
		TEST_METHOD(PutCardInDiscardedCards)
		{
			DiscardedCards discardedCards;
			Card card(Card::Number::Seven, Card::Color::Red);
			Card copyCard = card;
			discardedCards.PutCardInDiscardedCards(std::move(card));

			Assert::IsTrue(copyCard == discardedCards.ShowDiscardedCardFromTop());
		}

		TEST_METHOD(EqualOperator)
		{
			DiscardedCards discardedCards1;
			Card card(Card::Number::Seven, Card::Color::Red);
			discardedCards1.PutCardInDiscardedCards(std::move(card));
			DiscardedCards discardedCards2 = discardedCards1;

			Assert::IsTrue(discardedCards2.ShowDiscardedCardFromTop() == discardedCards1.ShowDiscardedCardFromTop());
		}

		TEST_METHOD(CopyConstructor)
		{
			DiscardedCards discardedCards1;
			Card card(Card::Number::Seven, Card::Color::Red);
			discardedCards1.PutCardInDiscardedCards(std::move(card));
			DiscardedCards discardedCards2(discardedCards1);

			Assert::IsTrue(discardedCards2.ShowDiscardedCardFromTop() == discardedCards1.ShowDiscardedCardFromTop());
		}

		TEST_METHOD(GetDiscardedCardFromTop)
		{
			DiscardedCards discardedCards;
			Card card(Card::Number::Seven, Card::Color::Red);
			Card copyCard = card;
			discardedCards.PutCardInDiscardedCards(std::move(card));
			Card card2 = discardedCards.GetDiscardedCardFromTop();
			Assert::IsTrue(copyCard == card2);
		}

		TEST_METHOD(Reinitialize)
		{
			DiscardedCards discardedCards;
			Card card(Card::Number::Seven, Card::Color::Red);
			discardedCards.PutCardInDiscardedCards(std::move(card));
			int expectedSizeOfDC = discardedCards.GetSize();

			Assert::IsTrue(expectedSizeOfDC == discardedCards.GetSize());
		}

		TEST_METHOD(GetSize)
		{
			DiscardedCards firstDiscardedCards;
			DiscardedCards secondDiscardedCards;

			Card card1(Card::Number::Eleven, Card::Color::Red);
			Card card2(Card::Number::Four, Card::Color::Blue);
			firstDiscardedCards.PutCardInDiscardedCards(std::move(card1));
			secondDiscardedCards.PutCardInDiscardedCards(std::move(card2));

			Assert::IsTrue(firstDiscardedCards.GetSize() == secondDiscardedCards.GetSize());
		}
	};
}
