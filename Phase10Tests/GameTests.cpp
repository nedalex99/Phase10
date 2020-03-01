#include "pch.h"
#include "CppUnitTest.h"

#include "../Phase10/Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTests
{
	TEST_CLASS(GameTests)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Game<Deck, DiscardedCards> game;

			Assert::IsTrue(game.GetNrOfPlayers() == 0);
		}

		TEST_METHOD(AddPlayer)
		{
			Game<Deck, DiscardedCards> game;
			Player player("player1");
			game.AddPlayer(player);

			Assert::IsTrue(game.GetNrOfPlayers() == 1);
		}

		TEST_METHOD(GetPlayer)
		{
			Game<Deck, DiscardedCards> game;
			Player player("player1");
			game.AddPlayer(player);
			Player player2 = game.GetPlayer("player1");

			Assert::IsTrue(player2.GetPlayerName() == player.GetPlayerName());
			Assert::IsTrue(player2.GetPhase() == player.GetPhase());
			Assert::IsTrue(player2.GetPoints() == player.GetPoints());
		}

		TEST_METHOD(GetPlayers)
		{
			Game<Deck, DiscardedCards> game;
			Player player1("player1");
			Player player2("player2");
			game.AddPlayer(player1);
			game.AddPlayer(player2);
			std::vector<Player> players;
			players.push_back(player1);
			players.push_back(player2);
			std::vector<Player> players2 = game.GetPlayers();

			for (int i = 0; i < 2; i++)
				Assert::IsTrue(players[i].GetPlayerName() == players2[i].GetPlayerName());
		}

		TEST_METHOD(DealCards)
		{
			Game<Deck, DiscardedCards> game;
			Player player("player1");
			game.AddPlayer(player);
			game.DealCards();

			Assert::IsTrue(game.GetPlayers()[0].GetCardsInHand().size() == 10);
		}

		TEST_METHOD(GetNrOfPlayers)
		{
			Game<Deck, DiscardedCards> game;
			Player player("player1");
			Player player2("player2");
			game.AddPlayer(player);
			game.AddPlayer(player2);

			Assert::IsTrue(game.GetNrOfPlayers() == 2);
		}
	};
}