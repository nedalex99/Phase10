#include "Phase10Game.h"
#include "Deck.h"
#include "DiscardedCards.h"
#include "Player.h"
#include "Game.h"
#include "Rules.h"
#include <fstream>
//#include "../Logging/Logger.h"

void Phase10Game::Run()
{
	// Logger functionality

	//Logger logger(std::cout);
	//logger.Log(__FUNCTION__, Logger::Level::Info);
	//std::cout << "\n\nThe game started at: ";
	//logger.Log("", Logger::Level::Info);

	//Tutorial of the game

	std::string answerTutorial;
	Game<Deck, DiscardedCards> game;
	Rules rules;

	bool tutorialWasPassed = false;
	do
	{
		std::cout << "\n\nYou want to read the tutorial of the game ?(1/Yes)-(0/No):";
		std::cin >> answerTutorial;
		if (answerTutorial != "0" && answerTutorial != "1")
		{
			std::cout << "Wrong option! Try again.";
		}

	} while (answerTutorial != "0" && answerTutorial != "1");
	if (answerTutorial == "1")
	{
		rules.Tutorial();
		system("pause");
	}
	//Asking how many players will play the game

	system("cls");
	std::string name;
	std::cout << "How many players will play?:";
	std::string nrPlayers;

	while (true)
	{
		try
		{
			std::cin >> nrPlayers;
			if (nrPlayers > "1" && nrPlayers < "5")
			{
				for (int indexOfPlayer = 0; indexOfPlayer < std::stoi(nrPlayers); indexOfPlayer++)
				{
					std::cout << "Player " << indexOfPlayer + 1 << " name is: ";
					std::cin >> name;
					game.AddPlayer(Player(name));
				}
				std::cout << "\n";
				break;
			}
			throw "Incorrect value. Introduce another value: ";
			break;
		}
		catch (const char* message)
		{
			std::cout << message;
		}
	}
	//Dealing cards to all the players.

	game.DealCards();
	bool firstCArdIsSkip = false;

	while (true)
	{
		for (auto& player : game.GetPlayers())
		{
			system("cls");
			game.PrintPlayedCardsFromPlayers();

			std::cout << "\nNow it's " << player.GetPlayerName() << "'s turn at phase " << player.GetPhase() << ".\n";
			//std::cout << "Player " << player.GetPlayerName() << " ";
			//logger.Log("at: ", Logger::Level::Info);
			std::cout << "\n\n";

			//Check if the first card in DiscardedCards is a skip card and skip the first player if so.

			if (game.GetDiscardedCards().ShowDiscardedCardFromTop().GetType() == Card::Type::Skip && firstCArdIsSkip == false)
			{
				player.SetIsSkipped(true);
				std::cout << "You were skipped because the first card from the Discarded cards was a skip card!";
				firstCArdIsSkip = true;
				system("pause");
			}
			else
			{
				firstCArdIsSkip = true;
			}

			if (player.GetIsSkipped() == false)
			{
				player.PrintCardsInHand();

				//Asking if you want to sort your cards.

				std::string sortCardsChoice;
				std::cout << "\nSort cards?(1-Yes)/(0-No):";
				while (true)
				{
					try
					{
						std::cin >> sortCardsChoice;
						if (sortCardsChoice == "1")
						{
							player.SortCardsByChoice();
							player.PrintCardsInHand();
							break;
						}
						if (sortCardsChoice == "0")
						{
							break;
						}
						throw "Incorrect. Introduce another value: ";
					}
					catch (const char* errorMessage)
					{
						std::cout << errorMessage;
					}
				}

				system("cls");
				game.PrintPlayedCardsFromPlayers();

				//The player is asked to draw a card from the deck or from the DiscardedCards pile.
				while (true)
				{
					try
					{
						player.PrintCardsInHand();
						player.OptionDraw(game.GetDeck(), game.GetDiscardedCards());
						break;
					}
					catch (const char* message)
					{
						std::cout << message << std::endl;
					}
				}
				system("cls");

				//Player is asked if he wants to put cards down. This will happen only if the player
				//didn't put cards down already.

				if (player.GetHasCardsDown() == false)
				{
					std::string cardsDownAnswer;
					rules.PhaseRequirement(player);
					std::cout << "\nDo you want to put cards down?\n";
					player.PrintCardsInHand();
					std::cout << "\n(1-Yes/0-No): ";

					while (true)
					{
						try
						{
							std::cin >> cardsDownAnswer;
							if (cardsDownAnswer == "1")
							{
								system("cls");
								player.PrintCardsInHand();
								player.PutCardsInPlayedCards();
								player.PrintCardsInPlayedCards();
								break;
							}
							if (cardsDownAnswer == "0")
							{
								break;
							}
							throw "Incorrect value. Introduce another value: ";
						}
						catch (const char* message)
						{
							std::cout << message;
						}
					}
				}
				else
				{
					//Player is asked if he wants to put more cards in his own deck or in other player's decks

					game.PrintPlayedCardsFromPlayers();
					std::cout << "\n";
					player.PrintCardsInHand();

					std::string cardsInOtherPlayerDeckAnswer;
					do
					{
						std::cout << "\n\nDo you want to put more cards in your deck or in other player's decks?(1-Yes)/(0-No):";
						std::cin >> cardsInOtherPlayerDeckAnswer;
						if (cardsInOtherPlayerDeckAnswer != "1" && cardsInOtherPlayerDeckAnswer != "0")
							std::cout << "Wrong option! Try again.";
					} while (cardsInOtherPlayerDeckAnswer != "1" && cardsInOtherPlayerDeckAnswer != "0");
					if (cardsInOtherPlayerDeckAnswer == "1")
					{
						int indexOfPlayer = 1;
						int playerAnswer;
						std::cout << "The players are:\n";
						game.PrintPlayedCardsFromPlayers();
						std::cout << "\n";

						//The player is asked to choose the player in which decks he want to place cards
						//The player can place cards in his own decks

						std::string howManyTimes;

						do
						{
							system("cls");
							game.PrintPlayedCardsFromPlayers();
							std::cout << "\n";
							player.PrintCardsInHand();
							howManyTimes = '2';
							std::cout << "\n\nWrite the index of player in which decks you want to place cards:";
							std::cin >> playerAnswer;
							int ok = 1;
							while (ok)
							{
								system("cls");
								if (playerAnswer > game.GetPlayers().size() || playerAnswer < 1)
								{
									std::cout << "\nIncorrect value. Please introduce another player: ";
									std::cin >> playerAnswer;
								}
								else
									ok = 0;
							}
							bool correctPlayer = true;
							do
							{
								if (game.GetPlayer(playerAnswer).GetHasCardsDown() == false)
								{
									std::cout << " You can't put cards in these player's deck because he didn't place cards down yet. Select other player:";
									std::cin >> playerAnswer;
									correctPlayer = true;
								}
							} while (correctPlayer != true);

							system("cls");
							std::cout << "\nYou have choosen to place cards in " << game.GetPlayer(playerAnswer) << "'s decks.\n";
							std::cout << game.GetPlayer(playerAnswer) << "'s played cards are:\n";
							game.GetPlayer(playerAnswer).PrintCardsInPlayedCards();
							std::cout << "\n\n";
							player.PrintCardsInHand();
							player.PutCardsInOtherPlayerDeck(game.GetPlayer(playerAnswer));

							do
							{
								system("cls");
								game.PrintPlayedCardsFromPlayers();
								std::cout << "\n\n";
								player.PrintCardsInHand();
								std::cout << "\nYou want to place any other cards in other players decks ?(1-Yes/0-No):";
								std::cin >> howManyTimes;
								if (howManyTimes != "1" && howManyTimes != "0")
									std::cout << "Wrong option! Try again.";
							} while (howManyTimes != "0" && howManyTimes != "1");
						} while (howManyTimes == "1");
					}
				}

				//The player is asked to place a card down.

				system("cls");
				game.PrintPlayedCardsFromPlayers();
				player.OptionPut(game.GetDiscardedCards());

				//If the player placed down a skip card, he can choose a player to be skiped.

				if (game.GetDiscardedCards().ShowDiscardedCardFromTop().GetType() == Card::Type::Skip)
				{
					std::cout << "You have choosed to skip a player.\n";
					int indexOfPlayer = 1;
					int playerAnswer;
					std::cout << "The players are:\n";
					for (Player& player : game.GetPlayers())
					{
						std::cout << indexOfPlayer << "." << player.GetPlayerName() << ";\n";
						indexOfPlayer++;
					}
					do
					{
						std::cout << "\nWrite the index of player you want to skip:";
						std::cin >> playerAnswer;
						int ok = 1;
						while (ok)
						{
							if (playerAnswer > game.GetPlayers().size() || playerAnswer < 1)
							{
								std::cout << "\nIncorrect value. Please introduce another player: ";
								std::cin >> playerAnswer;
							}
							else
								ok = 0;
						}
						if (player == game.GetPlayer(playerAnswer))
							std::cout << "You can't skip yourself(That will be hilarious!).";

					} while (player == game.GetPlayer(playerAnswer));

					game.GetPlayer(playerAnswer).SetIsSkipped(true);
				}

				//Print the cards player has at the end of the round.

				player.PrintCardsInHand();
			}

			//The player skipped status is changed to false after his turn if he was previously skipped.

			player.SetIsSkipped(false);

			//Check if the player has finished the phase. If this is true, the round will reset.

			if (player.GetCardsInHand().size() == 0)
			{
				std::cout << "\nPlayer " << player.GetPlayerName() << " has finished this round!\n";
				std::cout << "The round will now reset!Points will be calculated below:\n";
				game.ResetRound();
			}

			//Check if the player has finished the game. If this is true , all the players will be placed
			//in a ranking

			if (rules.CheckWinner(player))
			{
				for (Player& player : game.GetPlayers())
					player.CalculatePoints();
				std::cout << "\nPlayer " << player.GetPlayerName() << " has finished this game!!!\n";
				int indexOfPlayer = 1;
				std::sort(game.GetPlayers().begin(), game.GetPlayers().end());
				std::cout << "The ranking is :";
				std::cout << indexOfPlayer << "." << player.GetPlayerName() << " with " << player.GetPoints() << " points. (WINNER)\n";
				indexOfPlayer++;
				for (Player finalPlayer : game.GetPlayers())
				{
					if (player != finalPlayer)
					{
						std::cout << indexOfPlayer << "." << finalPlayer.GetPlayerName() << " with " << finalPlayer.GetPoints() << " points.\n";
						indexOfPlayer++;
					}
				}
				return;
			}
		}
	}
}
