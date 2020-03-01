#pragma once
#include "Player.h"
#include"Deck.h"

//Template Class
//Contains the list of players who will play the game, an deck and the pile of the discarded cards
//Functions are mainly based on player's actions

template<class DeckType = Deck, class DiscardedCardsType = DiscardedCards>
class Game
{
public:
	Game() : m_nrOfPlayers(0)
	{
	}

public:
	void AddPlayer(const Player& player)
	{
		m_nrOfPlayers++;
		m_players.push_back(player);
	}

	Player& GetPlayer(std::string nume)
	{
		for (auto& player : m_players)
		{
			if (player.GetPlayerName() == nume)
				return player;
		}
		throw "Player not found";
	}

	Player& GetPlayer(int indexOfPlayer)
	{
		return m_players[indexOfPlayer - 1];
	}


	std::vector<Player>& GetPlayers()
	{
		return m_players;
	}

	uint16_t GetNrOfPlayers()
	{
		return m_nrOfPlayers;
	}

	void PrintPlayers()
	{
		for (auto& player : m_players)
		{
			std::cout << "Player: " << player << "\n";
		}
	}

	void PrintCardsFromPlayers()
	{
		for (int i = 0; i < m_nrOfPlayers; i++)
		{
			std::cout << "Player:" << m_players[i].GetPlayerName() << " cards are:\n ";
			for (int j = 0; j < m_players[i].GetCardsInHand().size(); j++)
			{
				std::cout << j + 1 << "." << m_players[i].GetCardsInHand()[j] << "\n";
			}
			std::cout << "\n";
		}
	}

	void PrintPlayedCardsFromPlayers()
	{
		for (auto& player : m_players)
		{
			std::cout << "\nPlayer " << player.GetPlayerName() << " played cards are: ";
			std::cout << player.GetPlayedCards() << "\n";
		}
	}

	Deck& GetDeck()
	{
		return m_deck;
	}

	DiscardedCards& GetDiscardedCards()
	{
		return m_discardedCards;
	}


	void DealCards()
	{
		m_deck.Shuffle();
		for (int indexOfCards = 0; indexOfCards < 10; indexOfCards++)
		{
			for (int indexOfPlayer = 0; indexOfPlayer < m_players.size(); indexOfPlayer++)
			{
				m_players[indexOfPlayer].GiveCard(m_deck);
			}
		}
		m_discardedCards.PutCardInDiscardedCards(m_deck.GetTopCard());
	}

	void Options()
	{
		for (auto& player : m_players)
		{
			player.OptionDraw(m_deck, m_discardedCards);
			player.PrintCardsInHand();
			player.OptionPut(m_discardedCards);
			player.PrintCardsInHand();
		}
	}

	void ResetRound()
	{
		m_deck.Reinitialize();
		m_discardedCards.Reintialize();
		for (Player& player : m_players)
		{
			if (player.GetHasCardsDown() == true)
				player.SetPhase(player.GetPhase() + 1);
			player.CalculatePoints();
			player.Reintialize();
		}

		DealCards();

		std::cout << "\n The round was reset! \n";
		PrintPlayers();
	}

private:

	DeckType m_deck;
	DiscardedCardsType m_discardedCards;
	int m_nrOfPlayers;
	std::vector<Player> m_players;
};
