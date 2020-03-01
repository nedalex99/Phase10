#include "Rules.h"
#include "Player.h"
#include "PlayedCards.h"

std::pair<int, int> Rules::GetNumberOfCardsForDecks()
{
	return m_numberOfCardsForDecks;
}

std::pair<int, int> Rules::SetNumberOfCardsForDecksByPhase(Player& player)
{
	std::pair<int, int> numberOfCardsForDecks;
	switch (player.GetPhase())
	{
	case 1:
	{
		numberOfCardsForDecks.first = 3;
		numberOfCardsForDecks.second = 3;
		break;
	}
	case 2:
	{
		numberOfCardsForDecks.first = 3;
		numberOfCardsForDecks.second = 4;
		break;
	}
	case 3:
	{
		numberOfCardsForDecks.first = 4;
		numberOfCardsForDecks.second = 4;
		break;
	}
	case 4:
	{
		numberOfCardsForDecks.first = 7;
		numberOfCardsForDecks.second = 0;
		break;
	}
	case 5:
	{
		numberOfCardsForDecks.first = 8;
		numberOfCardsForDecks.second = 0;
		break;
	}
	case 6:
	{
		numberOfCardsForDecks.first = 9;
		numberOfCardsForDecks.second = 0;
		break;
	}
	case 7:
	{
		numberOfCardsForDecks.first = 4;
		numberOfCardsForDecks.second = 4;
		break;
	}
	case 8:
	{
		numberOfCardsForDecks.first = 7;
		numberOfCardsForDecks.second = 0;
		break;
	}
	case 9:
	{
		numberOfCardsForDecks.first = 5;
		numberOfCardsForDecks.second = 2;
		break;
	}
	case 10:
	{
		numberOfCardsForDecks.first = 5;
		numberOfCardsForDecks.second = 3;
		break;
	}
	default: break;
	}
	return numberOfCardsForDecks;
}

void Rules::PhaseRequirement(Player& player)
{
	switch (player.GetPhase())
	{
	case 1:
	{
		std::cout << "\nYou have to put 2 sets of 3";
		break;
	}
	case 2:
	{
		std::cout << "\nYou have to put 1 set of 3 and 1 run of 4";
		break;
	}
	case 3:
	{
		std::cout << "\nYou have to put 1 set of 4 and 1 run of 4";
		break;
	}
	case 4:
	{
		std::cout << "\nYou have to put 1 run of 7";
		break;
	}
	case 5:
	{
		std::cout << "\nYou have to put 1 run of 8";
		break;
	}
	case 6:
	{
		std::cout << "\nYou have to put 1 run of 9";
		break;
	}
	case 7:
	{
		std::cout << "\nYou have to put 2 sets of 4";
		break;
	}
	case 8:
	{
		std::cout << "\nYou have to put 7 cards of a color";
		break;
	}
	case 9:
	{
		std::cout << "\nYou have to put 1 set of 5 and 1 set of 2";
		break;
	}
	case 10:
	{
		std::cout << "\nYou have to put 1 set of 5 and 1 set of 3";
		break;
	}
	default:break;
	}
}

bool Rules::IsValidRuleFirstDeckForPhase(PlayedCards& playedCards, int phase)
{
	bool isValid = false;
	switch (phase)
	{
	case 1:
	{
		if (playedCards.ItsASet(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 2:
	{
		if (playedCards.ItsASet(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 3:
	{
		if (playedCards.ItsASet(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 4:
	{
		if (playedCards.ItsARun(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 5:
	{
		if (playedCards.ItsARun(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 6:
	{
		if (playedCards.ItsARun(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 7:
	{
		if (playedCards.ItsASet(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 8:
	{
		if (playedCards.ItsSameColor(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 9:
	{
		if (playedCards.ItsASet(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 10:
	{
		if (playedCards.ItsASet(playedCards.GetFirstDeck()))
		{
			isValid = true;
		}
		break;
	}
	default:
		break;
	}
	return isValid;
}

bool Rules::IsValidRuleSecondDeckForPhase(PlayedCards& playedCards, int phase)
{
	bool isValid = false;

	switch (phase)
	{
	case 1:
	{
		if (playedCards.ItsASet(playedCards.GetSecondDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 2:
	{
		if (playedCards.ItsARun(playedCards.GetSecondDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 3:
	{
		if (playedCards.ItsARun(playedCards.GetSecondDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 4: break;
	case 5: break;
	case 6: break;
	case 7:
	{
		if (playedCards.ItsASet(playedCards.GetSecondDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 8: break;
	case 9:
	{
		if (playedCards.ItsASet(playedCards.GetSecondDeck()))
		{
			isValid = true;
		}
		break;
	}
	case 10:
	{
		if (playedCards.ItsASet(playedCards.GetSecondDeck()))
		{
			isValid = true;
		}
		break;
	}
	default:
		break;
	}
	return isValid;
}


bool Rules::CheckWinner(Player player)
{
	if (player.GetPhase() == 10 && player.GetCardsInHand().size() == 0)
		return true;
	return false;
}

void Rules::Tutorial()
{
	std::cout << "	Phase 10 is another popular card game by Mattel, the makers of Uno. This card game resembles Rummy, but the " << std::endl
		<< "main difference is that you have to complete 10 different types of match-ups or Phases, in order to win the game. " << std::endl
		<< "The first player to complete all 10 Phases wins the game. It was originally created in 1982 by a man named" << std::endl
		<< "Kenneth R Johnson and marketed by a company called Fundex, who sold their rights to Mattel in 2010." << std::endl;
	std::cout << "\n	Phase 10 is a bit like Uno, in that you are always trying to get rid of all the cards in your hand and be the " << std::endl
		<< "first to do it for all hands. But unlike Uno, getting rid of your cards is not your main goal; the goal is to construct "
		<< "and complete your Phases (also called melds), from Phase 1 all the way to Phase 10. Discarding all your cards in hand " << std::endl
		<< "for each round is the secondary objective (but important as well, as we shall see)." << std::endl;
	std::cout << "\n	Introduction" << std::endl;
	std::cout << "\n	Phase 10 seems simpler than Uno since there are less types of cards, but don’t be fooled. The game can be quite " << std::endl
		<< "challenging to win, especially since you need to constantly slow down your opponents, e.g. those who are have already " << std::endl
		<< "advanced up the Phases ahead of you, and you always find yourself trying to guess which cards the person after your " << std::endl
		<< "needs; and not provide him/her these cards (by discarding them) if you can help it. A fair amount of luck is involved; " << std::endl
		<< "if you’ve been dealt a favorable hand of cards, it ensures a speedy Phase completion." << std::endl;
	std::cout << "\n	Each box of Phase 10 comes with 108 cards. There are 24 x 4 numbered cards of Red, Blue, Green, and Yellow " << std::endl
		<< "cards respectively (each color in two sets of numbers 1 to 12). Besides them, you have 4 Skip cards, and 8 Wild cards. " << std::endl
		<< "These symbol cards are very important to the game, as we shall see." << std::endl;
	std::cout << "\n	Skip Card: This card enables you to force someone to skip or lose a turn for that particular rotation/round." << std::endl
		<< "Once you discard or play it down, you can choose anyone to lose their turn. The Skip card may not be picked up from the " << std::endl
		<< "Discard Pile, only from the Draw Pile. If it’s the first card to be turned up at the start of the game, the first " << std::endl
		<< "player to start will lose a turn." << std::endl;
	std::cout << "\n	Wild Card: This is the most powerful card of all, and a life saver. You can use a Wild card to replace any card " << std::endl
		<< "in your Phase, even though you lack that number or color. Any number of Wild cards can be played down on your turn if " << std::endl
		<< "you have them, as long as you have a single normal card to lay down when you form your Phase. Once a Wild card is laid " << std::endl
		<< "down as part of a Phase, it cannot be picked up and reused elsewhere. If turned up at the beginning (to form the " << std::endl
		<< "Discard pile), the first player to start can pick it up." << std::endl;
	std::cout << "\n	What is a Phase?" << std::endl;
	std::cout << "	A Phase is a combination of cards that fulfils the Phase criteria for the particular player, which the player " << std::endl
		<< "lays down in front of them in view of the other players. Each player has to complete all 10 Phases of the game and if " << std::endl
		<< "they fail to complete a certain Phase in a hand, he/she must try again in the next hand. A hand ends when someone " << std::endl
		<< "manages to form a Phase and discard all his/her cards in hand. According to Phase 10 rules, the official 10 Phases are:" << std::endl;
	std::cout << "	* Phase 1 - 2 sets of 3" << std::endl;
	std::cout << "	* Phase 2 - 1 set of 3 and 1 run of 4" << std::endl;
	std::cout << "	* Phase 3 - 1 set of 4 and 1 run of 4" << std::endl;
	std::cout << "	* Phase 4 - 1 run of 7" << std::endl;
	std::cout << "	* Phase 5 - 1 run of 8" << std::endl;
	std::cout << "	* Phase 6 - 1 run of 9" << std::endl;
	std::cout << "	* Phase 7 - 2 sets of 4" << std::endl;
	std::cout << "	* Phase 8 - 7 cards of a color" << std::endl;
	std::cout << "	* Phase 9 - 1 set of 5 and 1 set of 2" << std::endl;
	std::cout << "	* Phase 10 - 1 set of 5 and 1 set of 3" << std::endl;
	std::cout << "	For those Phases which require more than 2 combinations, e.g. Phase 1, you must have all the cards in hand " << std::endl
		<< "ready to form BOTH combinations, before you lay them down; one combination is not enough, neither are any partial " << std::endl
		<< "Phases acceptable." << std::endl;
	std::cout << "	A Set is defined as two or more cards with the SAME number. Color is unimportant here. For example, if you " << std::endl
		<< "have three 9s and three 2s and three 5s, you have enough cards to complete Phase 1 during your turn. Choose two of " << std::endl
		<< "the sets and lay them down, while getting rid of the rest by discarding them." << std::endl;
	std::cout << "	A Run is defined as four or more numbered cards that are sequential. For example, you might have the cards " << std::endl
		<< "1, 3, 4, 5, 6, 8, 10, 10, a Wild, and a Skip. Your task is to build Phase 2. You can select 3, 4, 5, and 6 as a Run of" << std::endl
		<< "4. Color is irrelevant here. Meanwhile, the 10, 10, and Wild, can complete a Set of 3." << std::endl;
	std::cout << "	A group of one color (as in Phase 8), is simply defined as all cards being of the same color. Numbers are " << std::endl
		<< "irrelevant here, including repetitive numbers. It can be all seven green cards, or seven blue cards, or seven red cards." << std::endl;
	std::cout << "\n	Gameplay" << std::endl;
	std::cout << "	Phase 10 can be played by 2 to 4 players. Choose a dealer to shuffle and deal out 10 cards face down, to each " << std::endl
		<< "player. Players should not show their cards to one another. The remaining cards are placed in the center of the group " << std::endl
		<< "to form the Draw Pile. A card is then turned over and placed next to it. This is the Discard Pile." << std::endl;
	std::cout << "	Like Uno, the player to the dealer’s left typically starts first and then play proceeds in a clockwise " << std::endl
		<< "direction. Draw a card from either the Draw Pile or the Discard Pile, and add it to your hand. And then, discard any " << std::endl
		<< "card that you want onto the Discard Pile." << std::endl;
	std::cout << "	During your turn, if you can make a Phase, make sure you have all the required cards to form the Phase before " << std::endl
		<< "laying them down face up in front of you. If not, after drawing and discarding your cards, play moves on to the next " << std::endl
		<< "person in turn." << std::endl;
	std::cout << "	Each round is played in a clockwise direction, until finally, someone completes their Phase and goes out. " << std::endl
		<< "The first player to go out wins the hand. Scores are recorded (please see below), and the player to the left of the " << std::endl
		<< "dealer becomes the new dealer for the new hand. All cards are gathered back in the deck (after scores are tallied), " << std::endl
		<< "shuffled, and dealt again to all the players by the dealer." << std::endl;
	std::cout << "	A new hand now begins. If you have been working on a Phase but couldn’t complete it in time before the hand was " << std::endl
		<< "over, you now need to work on that Phase again." << std::endl;
	std::cout << "\n	What is Hitting?" << std::endl;
	std::cout << "	Hitting is the only way to get rid of 2 or more cards in hand during a player’s turn (immediately after laying " << std::endl
		<< "down their Phase). Otherwise, you would always be picking up one cardand then discarding one card during your turn; of " << std::endl
		<< "course, the net result is this would not reduce the amount of cards in your hand." << std::endl;
	std::cout << "	Hitting is discarding any suitable cards in your hand by adding them to your Phase or to another player’s " << std::endl
		<< "completed Phase. Let’s say, you already completed Phase 4, which is a Run of 7. You already laid down a full set of " << std::endl
		<< "numbers: 5, 6, 7, 8, 9, 10, and 11. You have a few cards left in hand, a number 1, 3, a Wildand another 7. Another " << std::endl
		<< "player has also finished building their Phase, which was 2 Sets of 3, and they have laid down 3 cards of number 1 and " << std::endl
		<< "number 3. Immediately after completing your Phase, you can discard your 1 and 3 by adding them to your opponent’s " << std::endl
		<< "Phase, and then adding the Wild card to either your opponent’s Phase or your own (since Wild cards are so versatile). " << std::endl
		<< "You are now left with a sole 7 card which you can discard onto the Discard Pile, and thus be the first player to get " << std::endl
		<< "rid of all your cards and go out of the round." << std::endl;
	std::cout << "\n	Being the first to go out" << std::endl;
	std::cout << "	The first player to go out of the round (also described as winning the hand), advances to the next Phase /" << std::endl
		<< "hand along with all the players who have also completed their existing Phases. Finishing first has its benefits. All " << std::endl
		<< "the others who did not finish discarding all their cards ahead of you for that hand, must now count or total up their " << std::endl
		<< "remaining cards in hand." << std::endl;
	std::cout << "	The fewer remaining cards one has at the end of each hand, the better it will be. Obviously, the winner of the " << std::endl
		<< "hand will not have to count any cards, since he/she will have none (zero). The scoring is as follows:" << std::endl;
	std::cout << "	* Each numbered card from 1-9 scores 5 points each" << std::endl;
	std::cout << "	* Each numbered card from 10-12 scores 10 points each" << std::endl;
	std::cout << "	* Each Skip card scores 15 points each" << std::endl;
	std::cout << "	* Each Wild card scores 25 points each" << std::endl;
	std::cout << "	The points scored for each hand are not a positive thing for any player. The more points someone has, the worse " << std::endl
		<< "it is for that player, because in Phase 10, the player with the lowest score is always the winner!" << std::endl;
	std::cout << "\n	Winning the Game" << std::endl;
	std::cout << "	The winner is the first person who completes Phase 10 at the end of a hand. The first player to complete Phase " << std::endl
		<< "10 will always have the lowest score. In the event of a tie (when two or more players have completed Phase 10), the " << std::endl
		<< "winner is also the player with the lowest score. If the scores are the same and it’s still a tie, the tied players " << std::endl
		<< "replay a hand and try to complete Phase 10 again. The first player to go out is declared the winner." << std::endl;

}
