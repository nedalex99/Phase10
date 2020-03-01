#pragma once
#include<vector>

class Player;
class PlayedCards;

class Rules
{
public:

	//Getter
	std::pair<int, int> GetNumberOfCardsForDecks();

	//Function who establishes the number of cards required to be placed in the current phase
	std::pair<int, int> SetNumberOfCardsForDecksByPhase(Player& player);

	//Function who show the player the phase requirements
	void PhaseRequirement(Player& player);

	//Functions who check if the phase requirements are met
	bool IsValidRuleFirstDeckForPhase(PlayedCards& playedCards, int phase);
	bool IsValidRuleSecondDeckForPhase(PlayedCards& playedCards, int phase);

	//Function who check if someone won the game
	bool CheckWinner(Player player);

	//Function for tutorial
	void Tutorial();

private:
	std::pair<int, int> m_numberOfCardsForDecks;
};

