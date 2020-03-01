#include "Player.h"

Player::Player(std::string playerName) :
	m_name(playerName), m_phase(1), m_points(0), m_isSkipped(false), m_hasCardsPutDown(false) {}

Player::Player(const Player& player)
{
	m_name = player.m_name;
	m_phase = player.m_phase;
	m_points = player.m_points;
	m_isSkipped = player.m_isSkipped;
	m_phase = player.m_phase;
	m_hasCardsPutDown = player.m_hasCardsPutDown;
	for (auto& card : player.m_cardsInHand)
	{
		m_cardsInHand.push_back(card);
	}
	m_playedCards = player.m_playedCards;
}

Player Player::operator=(const Player& player)
{
	m_name = player.m_name;
	m_phase = player.m_phase;
	m_points = player.m_points;
	m_isSkipped = player.m_isSkipped;
	m_phase = player.m_phase;
	m_hasCardsPutDown = player.m_hasCardsPutDown;
	for (auto& card : player.m_cardsInHand)
	{
		m_cardsInHand.push_back(card);
	}
	m_playedCards = player.m_playedCards;
	return *this;
}

Player::Player(Player&& other)

{
	*this = std::move(other);
}

Player& Player::operator=(Player&& other)
{
	m_cardsInHand = other.m_cardsInHand;
	return *this;
}

bool Player::operator!=(const Player& player)
{
	if (this->m_name == player.m_name && this->m_cardsInHand == player.m_cardsInHand &&
		this->m_hasCardsPutDown == player.m_hasCardsPutDown && this->m_isSkipped == player.m_isSkipped
		&& this->m_phase == player.m_phase && this->m_playedCards == player.m_playedCards &&
		this->m_points == player.m_points)
		return false;
	return true;
}

bool Player::operator==(const Player& player)
{
	if (this->m_name == player.m_name && this->m_cardsInHand == player.m_cardsInHand &&
		this->m_hasCardsPutDown == player.m_hasCardsPutDown && this->m_isSkipped == player.m_isSkipped
		&& this->m_phase == player.m_phase && this->m_playedCards == player.m_playedCards &&
		this->m_points == player.m_points)
		return true;
	return false;
}

bool Player::operator<(const Player& player)
{
	return m_points < player.m_points;
}

std::string Player::GetPlayerName() const
{
	return m_name;
}

int Player::GetPhase() const
{
	return m_phase;
}

void Player::SetPhase(const int& phase)
{
	m_phase = phase;
}

int Player::GetPoints()
{
	return m_points;
}

void Player::SetPoints(const int& points)
{
	m_points = points;
}

void Player::CalculatePoints()
{
	[this]() {
		for (auto& card : m_cardsInHand)
		{
			if (card.GetNumber() <= Card::Number::Nine && card.GetType() != Card::Type::Skip && card.GetType() != Card::Type::Wild)
				m_points += 5;
			if (card.GetNumber() >= Card::Number::Ten && card.GetNumber() <= Card::Number::Twelve &&
				card.GetType() != Card::Type::Skip && card.GetType() != Card::Type::Wild)
				m_points += 10;
			if (card.GetType() == Card::Type::Skip)
				m_points += 15;
			if (card.GetType() == Card::Type::Wild)
				m_points += 25;
		}
	};

	/*for (auto& card : m_cardsInHand)
	{
		if (card.GetNumber() <= Card::Number::Nine && card.GetType() != Card::Type::Skip && card.GetType() != Card::Type::Wild)
			m_points += 5;
		if (card.GetNumber() >= Card::Number::Ten && card.GetNumber() <= Card::Number::Twelve &&
			card.GetType() != Card::Type::Skip && card.GetType() != Card::Type::Wild)
			m_points += 10;
		if (card.GetType() == Card::Type::Skip)
			m_points += 15;
		if (card.GetType() == Card::Type::Wild)
			m_points += 25;
	}*/
	std::cout << "The player " << m_name << " current points are:" << m_points << "\n";
}

bool Player::GetIsSkipped()
{
	return m_isSkipped;
}

void Player::SetIsSkipped(bool skip)
{
	m_isSkipped = skip;
}

bool Player::GetHasCardsDown()
{
	return m_hasCardsPutDown;
}

void Player::SetHasCardsDown(bool hasCardsDown)
{
	m_hasCardsPutDown = hasCardsDown;
}

std::vector<Card>& Player::GetCardsInHand()
{
	return m_cardsInHand;
}

PlayedCards& Player::GetPlayedCards()
{
	return m_playedCards;
}

void Player::GiveCard(Deck& deck)
{
	m_cardsInHand.push_back(std::move(deck.GetTopCard()));
}

void Player::DrawCardFromDeck(Deck& deck)
{
	m_cardsInHand.push_back(std::move(deck.GetTopCard()));
}

void Player::SetPlayerName(const std::string& playerName)
{
	m_name = playerName;
}

void Player::PrintCardsInHand()
{
	int counter = 1;
	for (const auto& it : m_cardsInHand)
	{
		std::cout << counter++ << "." << it << "\n";
	}
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << player.m_name << " at phase " << player.m_phase;
	return out;

}

void Player::DrawCardFromStack(DiscardedCards& discardedCards)
{
	m_cardsInHand.push_back(std::move(discardedCards.GetDiscardedCardFromTop()));
}

void Player::PutCardInStack(const int& indexOfCard, DiscardedCards& discardedCards)
{
	discardedCards.PutCardInDiscardedCards(std::move(m_cardsInHand[indexOfCard]));
	m_cardsInHand.erase(std::move(m_cardsInHand.begin() + indexOfCard));
}

void Player::SortCardsByNumber()
{
	std::sort(m_cardsInHand.begin(), m_cardsInHand.end(), [](const auto& card1, const auto& card2)
		{
			return card1.GetNumber() < card2.GetNumber();
		});
}

void Player::SortCardsByColor()
{
	std::sort(m_cardsInHand.begin(), m_cardsInHand.end(), [](const auto& card1, const auto& card2)
		{
			return card1.GetColor() < card2.GetColor();
		});
}

void Player::SortCardsByType()
{
	std::sort(m_cardsInHand.begin(), m_cardsInHand.end(), [](const auto& card1, const auto& card2)
		{
			return card1.GetType() < card2.GetType();
		});
}

void Player::SortCardsByChoice()
{
	std::cout << "\nYou wish to sort your cards for a better view ? Choose one of the following options:\n";
	std::cout << "(1)Sort your cards in ascending order.\n";
	std::cout << "(2)Sort your cards by color.\n";
	std::cout << "(3)Sort your cards by type.\n";
	std::cout << "(0)Dont sort your cards.\n";
	std::string choice;
	while (true)
	{
		try
		{
			std::cin >> choice;
			if (choice == "1")
			{
				SortCardsByNumber();
				break;
			}

			if (choice == "2")
			{
				SortCardsByColor();
				break;
			}

			if (choice == "3")
			{
				SortCardsByType();
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



void Player::PutCardsInPlayedCards()
{
	Rules rules;
	std::pair<int, int> numberOfCardsForDecks = rules.SetNumberOfCardsForDecksByPhase(*this);
	std::string indexCard;
	int answerQuit = 0;
	if (m_phase == 4 || m_phase == 5 || m_phase == 6 || m_phase == 8)
	{
		std::cout << "\nAt this phase, you will need to place cards in just one deck!\n";
		std::cout << "Put the corresponding number of cards in the deck! The number of cards needed to be put is:"
			<< numberOfCardsForDecks.first << ";";
		for (int i = 0; i < numberOfCardsForDecks.first; i++)
		{
			system("cls");
			std::cout << "\nWhat card do you want to put down? ";

			while (true)
			{
				try
				{
					std::cin >> indexCard;
					int x = m_cardsInHand.size();
					if (indexCard > "/" && indexCard < ":")
					{
						if (indexCard > "0" && std::stoi(indexCard) <= x)
							break;
					}
					throw "Incorrect value. Introduce another value: ";
				}
				catch (const char* message)
				{
					std::cout << message;
				}
			}


			if (!rules.IsValidRuleFirstDeckForPhase(m_playedCards, m_phase))
			{
				do
				{
					std::cout << "\nIncorrect card.";
					m_playedCards.GetFirstDeck().pop_back();
					std::cout << "\nDo you want to quit? (1-Yes / 0-No) "; std::cin >> answerQuit;
					if (answerQuit)
					{
						while (!m_playedCards.GetFirstDeck().empty())
						{
							m_cardsInHand.push_back(std::move(m_playedCards.GetFirstDeck().back()));
							m_playedCards.GetFirstDeck().pop_back();
						}
						std::cout << "\nCards added back.";
						SetHasCardsDown(false);
						break;
					}
					std::cout << "\nIntroduce another card. ";
					std::cin >> indexCard;
					while (true)
					{
						try
						{
							std::cin >> indexCard;
							int x = m_cardsInHand.size();
							if (indexCard > "/" && indexCard < ":")
							{
								if (indexCard > "0" && std::stoi(indexCard) <= x)
									break;
							}
							throw "Incorrect value. Introduce another value: ";
						}
						catch (const char* message)
						{
							std::cout << message;
						}
					}
					m_playedCards.PutCardInFirstDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
				} while (!rules.IsValidRuleFirstDeckForPhase(m_playedCards, m_phase));
				if (answerQuit)
				{
					break;
				}
			}
			m_cardsInHand.erase(m_cardsInHand.begin() + std::stoi(indexCard) - 1);
			PrintCardsInHand();
		}
		PrintCardsInPlayedCards();
		PrintCardsInHand();
		if (m_playedCards.GetFirstDeck().size() != 0)
			SetHasCardsDown(true);
		return;
	}

	std::cout << "\nPut the corresponding number of cards in the first deck! The number of cards needed to be put is:"
		<< numberOfCardsForDecks.first << ";";

	for (int i = 0; i < numberOfCardsForDecks.first; i++)
	{
		system("cls");
		PrintCardsInPlayedCards();
		std::cout << "\n";
		PrintCardsInHand();
		std::cout << "\nWhat card do you want to put down? ";
		while (true)
		{
			try
			{
				std::cin >> indexCard;
				int x = m_cardsInHand.size();
				if (indexCard > "/" && indexCard < ":")
				{
					if (indexCard > "0" && std::stoi(indexCard) <= x)
						break;
				}
				throw "Incorrect value. Introduce another value: ";
			}
			catch (const char* message)
			{
				std::cout << message;
			}
		}
		m_playedCards.PutCardInFirstDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
		if (!rules.IsValidRuleFirstDeckForPhase(m_playedCards, m_phase))
		{
			do
			{
				std::cout << "\nIncorrect card.";
				m_playedCards.GetFirstDeck().pop_back();
				std::cout << "\nDo you want to quit? (1-Yes / 0-No) "; std::cin >> answerQuit;

				if (answerQuit)
				{
					while (!m_playedCards.GetFirstDeck().empty())
					{
						m_cardsInHand.push_back(std::move(m_playedCards.GetFirstDeck().back()));
						m_playedCards.GetFirstDeck().pop_back();
					}
					SetHasCardsDown(false);
					break;
				}
				system("cls");
				std::cout << "\nCards added back.\n";
				PrintCardsInPlayedCards();
				PrintCardsInHand();
				std::cout << "\nIntroduce another card. ";
				while (true)
				{
					try
					{
						std::cin >> indexCard;
						int x = m_cardsInHand.size();
						if (indexCard > "/" && indexCard < ":")
						{
							if (indexCard > "0" && std::stoi(indexCard) <= x)
								break;
						}
						throw "Incorrect value. Introduce another value: ";
					}
					catch (const char* message)
					{
						std::cout << message;
					}
				}
				m_playedCards.PutCardInFirstDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
			} while (!rules.IsValidRuleFirstDeckForPhase(m_playedCards, m_phase));
			if (answerQuit)
			{
				break;
			}
		}
		m_cardsInHand.erase(std::move(m_cardsInHand.begin() + std::stoi(indexCard) - 1));
	}

	if (answerQuit == 0)
	{
		system("cls");
		std::cout << "\nPut the corresponding number of cards in the second deck! The number of cards needed to be put is:"
			<< numberOfCardsForDecks.second << ";";
		for (int i = 0; i < numberOfCardsForDecks.second; i++)
		{
			PrintCardsInPlayedCards();
			std::cout << "\n";
			PrintCardsInHand();
			std::cout << "\n\nWhat card do you want to put down? ";
			while (true)
			{
				try
				{
					std::cin >> indexCard;
					int x = m_cardsInHand.size();
					if (indexCard > "/" && indexCard < ":")
					{
						if (indexCard > "0" && std::stoi(indexCard) <= x)
							break;
					}
					throw "Incorrect value. Introduce another value: ";
				}
				catch (const char* message)
				{
					std::cout << message;
				}
			}
			m_playedCards.PutCardInSecondDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
			if (!rules.IsValidRuleSecondDeckForPhase(m_playedCards, m_phase))
			{
				do
				{
					std::cout << "\nIncorrect card.";
					m_playedCards.GetSecondDeck().pop_back();
					std::cout << "\nDo you want to quit? (1-Yes / 0-No) "; std::cin >> answerQuit;
					if (answerQuit)
					{
						while (!m_playedCards.GetFirstDeck().empty())
						{
							m_cardsInHand.push_back(std::move(m_playedCards.GetFirstDeck().back()));
							m_playedCards.GetFirstDeck().pop_back();
						}
						while (!m_playedCards.GetSecondDeck().empty())
						{
							m_cardsInHand.push_back(std::move(m_playedCards.GetSecondDeck().back()));
							m_playedCards.GetSecondDeck().pop_back();
						}
						SetHasCardsDown(false);
						break;
					}
					system("cls");
					std::cout << "\nCards added back.\n";
					PrintCardsInPlayedCards();
					PrintCardsInHand();
					std::cout << "\nIntroduce another card. ";
					std::cin >> indexCard;
					while (true)
					{
						try
						{
							std::cin >> indexCard;
							int x = m_cardsInHand.size();
							if (indexCard > "/" && indexCard < ":")
							{
								if (indexCard > "0" && std::stoi(indexCard) <= x)
									break;
							}
							throw "Incorrect value. Introduce another value: ";
						}
						catch (const char* message)
						{
							std::cout << message;
						}
					}
					m_playedCards.PutCardInSecondDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
				} while (!rules.IsValidRuleSecondDeckForPhase(m_playedCards, m_phase));
				if (answerQuit)
				{
					break;
				}
			}
			m_cardsInHand.erase(std::move(m_cardsInHand.begin() + std::stoi(indexCard) - 1));
		}
	}
	if (m_playedCards.GetFirstDeck().size() != 0 && m_playedCards.GetSecondDeck().size() != 0)
	{
		SetHasCardsDown(true);
	}

	if (answerQuit)
	{
		system("cls");
		int quitAnswer;
		std::cout << "\nDo you want to put cards down again?\n";
		PrintCardsInHand();
		std::cout << "\nAnswer(1-Yes/0-No): ";
		std::cin >> quitAnswer;
		if (quitAnswer)
		{
			system("cls");
			PrintCardsInHand();
			PutCardsInPlayedCards();
		}
	}
}

void Player::PrintCardsInPlayedCards() const
{
	std::cout << m_playedCards;
}

void Player::PutCardsInOtherPlayerDeck(Player& player)
{
	int nrOfCards;
	int option;
	Rules rules;
	std::string indexCard;
	int nrOfCardsPutDown = 0;
	bool quit = false;
	if (player.GetPhase() == 4 || player.GetPhase() == 5 || player.GetPhase() == 6 || player.GetPhase() == 8)
	{
		{
			do
			{
				std::cout << "\nHow many cards do you want to place down in the player's deck?:";
				std::cin >> nrOfCards;
				if (nrOfCards > player.GetCardsInHand().size())
				{
					std::cout << "You dont have that many cards!Type another answer:";
				}

			} while (nrOfCards > player.GetCardsInHand().size());
			for (int i = 0; i < nrOfCards; i++)
			{
				std::cout << "\nWhat card do you want to put down? ";
				while (true)
				{
					try
					{
						std::cin >> indexCard;
						int x = m_cardsInHand.size();
						if (indexCard > "/" && indexCard < ":")
						{
							if (indexCard > "0" && std::stoi(indexCard) <= x)
								break;
						}
						throw "Incorrect value. Introduce another value: ";
					}
					catch (const char* message)
					{
						std::cout << message;
					}
				}
				player.GetPlayedCards().PutCardInFirstDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
				nrOfCardsPutDown++;
				if (!rules.IsValidRuleFirstDeckForPhase(player.m_playedCards, player.m_phase))
				{
					do
					{
						std::cout << "This card doesnt fit in the player's deck!\n";
						player.GetPlayedCards().GetFirstDeck().pop_back();
						std::cout << "Do you want to quit this operation ?(1-Yes)/(0-No):";
						int optionQuit;
						std::cin >> optionQuit;
						if (optionQuit == 1)
						{
							for (int index = 0; index < nrOfCardsPutDown; index++)
							{
								m_cardsInHand.push_back(player.GetPlayedCards().GetFirstDeck().back());
								player.GetPlayedCards().GetFirstDeck().pop_back();
							}
							quit = true;
							break;
						}
						else
						{
							std::cout << "\nSelect other card to put in the deck: ";
							while (true)
							{
								try
								{
									std::cin >> indexCard;
									int x = m_cardsInHand.size();
									if (indexCard > "/" && indexCard < ":")
									{
										if (indexCard > "0" && std::stoi(indexCard) <= x)
											break;
									}
									throw "Incorrect value. Introduce another value: ";
								}
								catch (const char* message)
								{
									std::cout << message;
								}
							}
							player.GetPlayedCards().PutCardInFirstDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
						}
					} while (!rules.IsValidRuleFirstDeckForPhase(player.m_playedCards, player.m_phase) && quit != true);
				}
				m_cardsInHand.erase(m_cardsInHand.begin() + std::stoi(indexCard) - 1);
				PrintCardsInHand();
				nrOfCardsPutDown++;
			}
		}
		return;
	}
	do {
		std::cout << "\nIn which deck do you want to put cards?(1(First)/2(Second)/3(Both)): ";
		std::cin >> option;
	} while (option != 1 && option != 2 && option != 3);
	if (option == 1)
	{
		system("cls");
		player.PrintCardsInPlayedCards();
		std::cout << "\n\n";
		PrintCardsInHand();
		do
		{
			std::cout << "\nHow many cards do you want to place down in the player's deck?:";
			std::cin >> nrOfCards;
			if (nrOfCards > player.GetCardsInHand().size())
			{
				std::cout << "You dont have that many cards!Type another answer:";
			}

		} while (nrOfCards > player.GetCardsInHand().size());
		for (int i = 0; i < nrOfCards; i++)
		{
			system("cls");
			player.PrintCardsInPlayedCards();
			std::cout << "\n\n";
			PrintCardsInHand();
			std::cout << "\n\nWhat card do you want to put down? ";
			while (true)
			{
				try
				{
					std::cin >> indexCard;
					int x = m_cardsInHand.size();
					if (indexCard > "/" && indexCard < ":")
					{
						if (indexCard > "0" && std::stoi(indexCard) <= x)
							break;
					}
					throw "Incorrect value. Introduce another value: ";
				}
				catch (const char* message)
				{
					std::cout << message;
				}
			}
			player.GetPlayedCards().PutCardInFirstDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
			if (!rules.IsValidRuleFirstDeckForPhase(player.m_playedCards, player.m_phase))
			{
				do
				{
					std::cout << "This card doesnt fit in the player's deck!";
					player.GetPlayedCards().GetFirstDeck().pop_back();
					std::cout << "Do you want to quit this operation ?(1-Yes)/(0-No):";
					int optionQuit;
					std::cin >> optionQuit;
					if (optionQuit == 1)
					{
						for (int index = 0; index < nrOfCardsPutDown; index++)
						{
							m_cardsInHand.push_back(player.GetPlayedCards().GetFirstDeck().back());
							player.GetPlayedCards().GetFirstDeck().pop_back();
						}
						quit = true;
						break;
					}
					else
					{
						std::cout << "\nSelect other card to put in the deck: "; while (true)
						{
							try
							{
								std::cin >> indexCard;
								int x = m_cardsInHand.size();
								if (indexCard > "/" && indexCard < ":")
								{
									if (indexCard > "0" && std::stoi(indexCard) <= x)
										break;
								}
								throw "Incorrect value. Introduce another value: ";
							}
							catch (const char* message)
							{
								std::cout << message;
							}
						}
						player.GetPlayedCards().PutCardInFirstDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
					}
				} while (!rules.IsValidRuleFirstDeckForPhase(player.m_playedCards, player.m_phase) && quit != true);
			}
			if (quit)
			{
				break;
			}
			m_cardsInHand.erase(m_cardsInHand.begin() + std::stoi(indexCard) - 1);
			nrOfCardsPutDown++;
			PrintCardsInHand();
		}
	}
	else
		if (option == 2)
		{
			do
			{
				std::cout << "\nHow many cards do you want to place down in the player's deck?:";
				std::cin >> nrOfCards;
				if (nrOfCards > player.GetCardsInHand().size())
				{
					std::cout << "You dont have that many cards!Type another answer:";
				}

			} while (nrOfCards > player.GetCardsInHand().size());
			for (int i = 0; i < nrOfCards; i++)
			{
				std::cout << "\nWhat card do you want to put down? ";
				while (true)
				{
					try
					{
						std::cin >> indexCard;
						int x = m_cardsInHand.size();
						if (indexCard > "/" && indexCard < ":")
						{
							if (indexCard > "0" && std::stoi(indexCard) <= x)
								break;
						}
						throw "Incorrect value. Introduce another value: ";
					}
					catch (const char* message)
					{
						std::cout << message;
					}
				}
				player.GetPlayedCards().PutCardInSecondDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
				if (!rules.IsValidRuleSecondDeckForPhase(player.m_playedCards, player.m_phase))
				{
					do
					{
						std::cout << "This card doesnt fit in the player's deck!";
						player.GetPlayedCards().GetSecondDeck().pop_back();
						std::cout << "Do you want to quit this operation ?(1-Yes)/(0-No):";
						int optionQuit;
						std::cin >> optionQuit;
						if (optionQuit == 1)
						{
							for (int index = 0; index < nrOfCardsPutDown; index++)
							{
								m_cardsInHand.push_back(player.GetPlayedCards().GetSecondDeck().back());
								player.GetPlayedCards().GetSecondDeck().pop_back();
							}
							quit = true;
							break;
						}
						else
						{
							std::cout << "\nSelect other card to put in the deck: ";
							while (true)
							{
								try
								{
									std::cin >> indexCard;
									int x = m_cardsInHand.size();
									if (indexCard > "/" && indexCard < ":")
									{
										if (indexCard > "0" && std::stoi(indexCard) <= x)
											break;
									}
									throw "Incorrect value. Introduce another value: ";
								}
								catch (const char* message)
								{
									std::cout << message;
								}
							}
							player.GetPlayedCards().PutCardInSecondDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
						}
					} while (!rules.IsValidRuleSecondDeckForPhase(player.m_playedCards, player.m_phase) && quit != true);
				}
				if (quit)
				{
					break;
				}
				m_cardsInHand.erase(m_cardsInHand.begin() + std::stoi(indexCard) - 1);
				nrOfCardsPutDown++;
				PrintCardsInHand();
			}
		}
		else if (option == 3)
		{
			int nrOfCardsPutInFirstDeck = 0;
			int nrOfCardsPutInSecondDeck = 0;
			do
			{
				std::cout << "\nHow many cards do you want to place down in the player's deck?:";
				std::cin >> nrOfCards;
				if (nrOfCards > player.GetCardsInHand().size())
				{
					std::cout << "You dont have that many cards!Type another answer:";
				}

			} while (nrOfCards > player.GetCardsInHand().size());
			for (int i = 0; i < nrOfCards; i++)
			{
				std::cout << "\nWhat card do you want to put down? ";
				while (true)
				{
					try
					{
						std::cin >> indexCard;
						int x = m_cardsInHand.size();
						if (indexCard > "/" && indexCard < ":")
						{
							if (indexCard > "0" && std::stoi(indexCard) <= x)
								break;
						}
						throw "Incorrect value. Introduce another value: ";
					}
					catch (const char* message)
					{
						std::cout << message;
					}
				}
				player.GetPlayedCards().PutCardInFirstDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
				if (!rules.IsValidRuleFirstDeckForPhase(player.m_playedCards, player.m_phase))
				{
					do
					{
						std::cout << "This card doesnt fit in the player's deck!";
						player.GetPlayedCards().GetFirstDeck().pop_back();
						std::cout << "Do you want to quit this operation ?(1-Yes)/(0-No):";
						int optionQuit;
						std::cin >> optionQuit;
						if (optionQuit == 1)
						{
							for (int index = 0; index < nrOfCardsPutInFirstDeck; index++)
							{
								m_cardsInHand.push_back(player.GetPlayedCards().GetFirstDeck().back());
								player.GetPlayedCards().GetFirstDeck().pop_back();
							}
							quit = true;
							break;
						}
						else
						{
							std::cout << "\nSelect other card to put in the deck: ";
							while (true)
							{
								try
								{
									std::cin >> indexCard;
									int x = m_cardsInHand.size();
									if (indexCard > "/" && indexCard < ":")
									{
										if (indexCard > "0" && std::stoi(indexCard) <= x)
											break;
									}
									throw "Incorrect value. Introduce another value: ";
								}
								catch (const char* message)
								{
									std::cout << message;
								}
							}
							player.GetPlayedCards().PutCardInFirstDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
						}
					} while (!rules.IsValidRuleFirstDeckForPhase(player.m_playedCards, player.m_phase) && quit != true);
				}

				if (quit)
				{
					break;
				}
				m_cardsInHand.erase(m_cardsInHand.begin() + std::stoi(indexCard) - 1);
				nrOfCardsPutInFirstDeck++;
				PrintCardsInHand();
			}
			if (!quit)
			{
				do
				{
					std::cout << "\nHow many cards do you want to place down in the player's deck?:";
					std::cin >> nrOfCards;
					if (nrOfCards > player.GetCardsInHand().size())
					{
						std::cout << "You dont have that many cards!Type another answer:";
					}

				} while (nrOfCards > player.GetCardsInHand().size());
				for (int i = 0; i < nrOfCards; i++)
				{
					if (quit)
					{
						break;
					}
					std::cout << "\nWhat card do you want to put down? ";
					while (true)
					{
						try
						{
							std::cin >> indexCard;
							int x = m_cardsInHand.size();
							if (indexCard > "/" && indexCard < ":")
							{
								if (indexCard > "0" && std::stoi(indexCard) <= x)
									break;
							}
							throw "Incorrect value. Introduce another value: ";
						}
						catch (const char* message)
						{
							std::cout << message;
						}
					}
					player.GetPlayedCards().PutCardInSecondDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
					if (!rules.IsValidRuleSecondDeckForPhase(player.m_playedCards, player.m_phase))
					{
						do
						{
							std::cout << "This card doesnt fit in the player's deck!";
							player.GetPlayedCards().GetSecondDeck().pop_back();
							std::cout << "Do you want to quit this operation ?(1-Yes)/(0-No):";
							int optionQuit;
							std::cin >> optionQuit;
							if (optionQuit == 1)
							{
								for (int index = 0; index < nrOfCardsPutInFirstDeck; index++)
								{
									m_cardsInHand.push_back(player.GetPlayedCards().GetFirstDeck().back());
									player.GetPlayedCards().GetFirstDeck().pop_back();
								}
								for (int index = 0; index < nrOfCardsPutInSecondDeck; index++)
								{
									m_cardsInHand.push_back(player.GetPlayedCards().GetSecondDeck().back());
									player.GetPlayedCards().GetSecondDeck().pop_back();
								}
								quit = true;
								break;
							}
							else
							{
								std::cout << "\nSelect other card to put in the deck: ";
								while (true)
								{
									try
									{
										std::cin >> indexCard;
										int x = m_cardsInHand.size();
										if (indexCard > "/" && indexCard < ":")
										{
											if (indexCard > "0" && std::stoi(indexCard) <= x)
												break;
										}
										throw "Incorrect value. Introduce another value: ";
									}
									catch (const char* message)
									{
										std::cout << message;
									}
								}
								player.GetPlayedCards().PutCardInSecondDeck(std::move(m_cardsInHand[std::stoi(indexCard) - 1]));
							}
						} while (!rules.IsValidRuleSecondDeckForPhase(player.m_playedCards, player.m_phase) && quit != true);
					}

					if (quit)
					{
						break;
					}
					m_cardsInHand.erase(m_cardsInHand.begin() + std::stoi(indexCard) - 1);
					nrOfCardsPutInSecondDeck++;
					PrintCardsInHand();
				}
			}
		}
}

void Player::OptionDraw(Deck& deck, DiscardedCards& discardedCards)
{
	std::cout << "\nPlayer " << m_name << " options for draw are:\n";
	std::cout << "Option 1:Draw from Deck\n";
	if (discardedCards.ShowDiscardedCardFromTop() == Card::Type::Skip)
	{
		std::cout << "Option 2:Draw from DiscardedCards: ";
		std::cout << discardedCards.ShowDiscardedCardFromTop() << "- You can't draw this card. You have to draw from the deck!" << std::endl;
	}
	else
	{
		std::cout << "Option 2:Draw from DiscardedCards: ";
		std::cout << discardedCards.ShowDiscardedCardFromTop() << std::endl;
	}
	std::string option;
	std::cout << "What is your option?(1/2): ";

	while (true)
	{
		try
		{
			std::cin >> option;
			if (option == "1")
			{
				DrawCardFromDeck(deck);
				break;
			}
			if (option == "2")
			{
				if (discardedCards.ShowDiscardedCardFromTop() == Card::Type::Skip)
				{
					std::cout << "\nYou can't draw this card. You have to draw from the deck! ";
					DrawCardFromDeck(deck);
				}
				else
				{
					DrawCardFromStack(discardedCards);
				}
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

void Player::OptionPut(DiscardedCards& discardedCards)
{
	std::cout << "\n\nWhich card do you wish to put in discarded cards pile?\n";
	PrintCardsInHand();
	std::string indexCard;
	std::cout << "\nAnswer: ";

	while (true)
	{
		try
		{
			std::cin >> indexCard;
			int x = m_cardsInHand.size();
			if (indexCard > "/" && indexCard < ":")
			{
				if (indexCard > "0" && std::stoi(indexCard) <= x)
					break;
			}
			throw "Incorrect value. Introduce another value: ";
		}
		catch (const char* message)
		{
			std::cout << message;
		}
	}
	PutCardInStack(std::stoi(indexCard) - 1, discardedCards);
	std::cout << "\n";
}

void Player::Reintialize()
{
	m_cardsInHand.clear();
	m_playedCards.Reinitialize();
	m_isSkipped = false;
	m_hasCardsPutDown = false;
}


