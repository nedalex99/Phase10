#include "pch.h"
#include "CppUnitTest.h"

#include "../Phase10/Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayerTests
{
	TEST_CLASS(PlayerTests)
	{
	public:
		TEST_METHOD(Constructor)
		{
			std::string name = "Player1";
			Player player(name);

			Assert::IsTrue(name == player.GetPlayerName());
		}

		TEST_METHOD(Print)
		{
			std::string name = "Player1";
			Player player(name);

			std::stringstream stream;
			stream << player.GetPlayerName();
			Assert::AreEqual<std::string>(name, stream.str(), L"If you see this message, player name is not the same");
		}

		TEST_METHOD(CopyConstructor)
		{
			std::string name = "Player1";
			Player player1(name);
			Player player2(player1);
			Assert::IsTrue(player1.GetPlayerName() == player2.GetPlayerName());
		}

		TEST_METHOD(EqualOperator)
		{
			std::string name = "Player1";
			Player player1(name);
			Player player2 = player1;
			Assert::IsTrue(player1.GetPlayerName() == player2.GetPlayerName());
		}

		TEST_METHOD(GetPlayerName)
		{
			std::string name = "Player1";
			Player player(name);

			Assert::IsTrue(name == player.GetPlayerName());
		}

		TEST_METHOD(SetPlayerName)
		{
			std::string name = "Player1";
			Player player(name);
			std::string name2 = "Player2";
			player.SetPlayerName(name2);

			Assert::IsTrue(name != player.GetPlayerName());
		}

		TEST_METHOD(GetPhase)
		{
			std::string name = "Player1";
			Player player(name);

			Assert::IsTrue(player.GetPhase() == 1);
		}

		TEST_METHOD(SetPhase)
		{
			std::string name = "Player1";
			Player player(name);
			player.SetPhase(2);
			Assert::IsTrue(player.GetPhase() != 1);
		}

		TEST_METHOD(GetPoints)
		{
			std::string name = "Player1";
			Player player(name);

			Assert::IsTrue(player.GetPoints() == 0);
		}

		TEST_METHOD(SetPoints)
		{
			std::string name = "Player1";
			Player player(name);
			player.SetPoints(1);
			Assert::IsTrue(player.GetPoints() != 0);
		}

		TEST_METHOD(GetIsSkipped)
		{
			std::string name = "Player1";
			Player player(name);

			Assert::IsTrue(player.GetIsSkipped() == false);
		}

		TEST_METHOD(SetIsSkipped)
		{
			std::string name = "Player1";
			Player player(name);
			player.SetIsSkipped(false);
			Assert::IsTrue(player.GetIsSkipped() == false);
		}

		TEST_METHOD(SortCardsByNumber)
		{
			int ok = 0;
			Player player("player1");
			Deck deck;
			deck.Shuffle();
			Deck deck2 = deck;
			Card card = deck.GetTopCard();
			player.GiveCard(deck);
			card = deck2.GetTopCard();
			card = deck2.GetTopCard();
			std::vector<Card> hand;
			while (ok == 0)
			{
				card = deck.GetTopCard();
				if (player.GetCardsInHand()[0].GetNumber() > card.GetNumber())
				{
					player.GiveCard(deck2);
					ok = 1;
				}
				else
					card = deck2.GetTopCard();
			}
			player.SortCardsByNumber();
			hand = player.GetCardsInHand();
			Assert::IsTrue(hand[0].GetNumber() < hand[1].GetNumber());
		}

		TEST_METHOD(SortCardsByColor)
		{
			int ok = 0;
			Player player("player1");
			Deck deck;
			deck.Shuffle();
			Deck deck2 = deck;
			Card card = deck.GetTopCard();
			player.GiveCard(deck);
			card = deck2.GetTopCard();
			card = deck2.GetTopCard();
			std::vector<Card> hand;
			while (ok == 0)
			{
				card = deck.GetTopCard();
				if (player.GetCardsInHand()[0].GetColor() > card.GetColor())
				{
					player.GiveCard(deck2);
					ok = 1;
				}
				else
					card = deck2.GetTopCard();
			}
			player.SortCardsByColor();
			hand = player.GetCardsInHand();
			Assert::IsTrue(hand[0].GetColor() < hand[1].GetColor());
		}

		TEST_METHOD(SortCardsByType)
		{
			int ok = 0;
			Player player("player1");
			Deck deck;
			deck.Shuffle();
			Deck deck2 = deck;
			Card card = deck.GetTopCard();
			player.GiveCard(deck);
			card = deck2.GetTopCard();
			card = deck2.GetTopCard();
			std::vector<Card> hand;
			while (ok == 0)
			{
				card = deck.GetTopCard();
				if (player.GetCardsInHand()[0].GetType() > card.GetType())
				{
					player.GiveCard(deck2);
					ok = 1;
				}
				else
					card = deck2.GetTopCard();
			}
			player.SortCardsByType();
			hand = player.GetCardsInHand();
			Assert::IsTrue(hand[0].GetType() < hand[1].GetType());
		}

		TEST_METHOD(DrawCardFromDeck)
		{
			Deck deck1;
			deck1.Shuffle();
			Deck deck2 = deck1;
			Player player("player1");
			player.DrawCardFromDeck(deck1);
			Card card = deck2.GetTopCard();
			Assert::IsTrue(player.GetCardsInHand()[0].GetColor() == card.GetColor());
			Assert::IsTrue(player.GetCardsInHand()[0].GetNumber() == card.GetNumber());
			Assert::IsTrue(player.GetCardsInHand()[0].GetType() == card.GetType());
		}

		TEST_METHOD(GiveCard)
		{
			Deck deck1;
			deck1.Shuffle();
			Deck deck2 = deck1;
			Player player("player1");
			player.GiveCard(deck1);
			Card card = deck2.GetTopCard();
			Assert::IsTrue(player.GetCardsInHand()[0].GetColor() == card.GetColor());
			Assert::IsTrue(player.GetCardsInHand()[0].GetNumber() == card.GetNumber());
			Assert::IsTrue(player.GetCardsInHand()[0].GetType() == card.GetType());
		}

		TEST_METHOD(DrawCardFromStack)
		{
			Player player("player1");
			Deck deck;
			deck.Shuffle();
			Card card = deck.GetTopCard();
			Card copyCard = card;
			DiscardedCards discardedCards;
			discardedCards.PutCardInDiscardedCards(std::move(card));
			player.DrawCardFromStack(discardedCards);
			Assert::IsTrue(player.GetCardsInHand()[0].GetColor() == copyCard.GetColor());
			Assert::IsTrue(player.GetCardsInHand()[0].GetNumber() == copyCard.GetNumber());
			Assert::IsTrue(player.GetCardsInHand()[0].GetType() == copyCard.GetType());
		}

		TEST_METHOD(PutCardInStack)
		{
			Player player("player1");
			Deck deck;
			deck.Shuffle();
			DiscardedCards discardedCards;
			player.DrawCardFromDeck(deck);
			Card card = player.GetCardsInHand()[0];
			player.PutCardInStack(0, discardedCards);
			Assert::IsTrue(card.GetColor() == discardedCards.ShowDiscardedCardFromTop().GetColor());
			Assert::IsTrue(card.GetNumber() == discardedCards.ShowDiscardedCardFromTop().GetNumber());
			Assert::IsTrue(card.GetType() == discardedCards.ShowDiscardedCardFromTop().GetType());
			Assert::IsTrue(player.GetCardsInHand().size() == 0);
		}

		TEST_METHOD(notEqualOperator)
		{
			Player player1("player"), player2("player");

			player1.SetPhase(3);
			player2.SetPhase(3);
			player1.SetPoints(90);
			player2.SetPoints(70);

			Card card1(Card::Number::Eleven, Card::Color::Green);
			Card card2(Card::Number::Eleven, Card::Color::Green);

			Assert::IsTrue(player1 != player2);
		}

		TEST_METHOD(Reinitialize)
		{
			Player player("Player");
			Deck deck;
			player.DrawCardFromDeck(deck);
			player.DrawCardFromDeck(deck);
			player.SetIsSkipped(true);
			player.SetHasCardsDown(true);
			player.GetPlayedCards().PutCardInFirstDeck(std::move(player.GetCardsInHand().front()));
			player.Reintialize();
			Assert::IsTrue(player.GetCardsInHand().size() == 0);
			Assert::IsTrue(player.GetIsSkipped() == false);
			Assert::IsTrue(player.GetHasCardsDown() == false);
			Assert::IsTrue(player.GetPlayedCards().GetFirstDeck().size() == 0);
			Assert::IsTrue(player.GetPlayedCards().GetSecondDeck().size() == 0);
		}
	};
}