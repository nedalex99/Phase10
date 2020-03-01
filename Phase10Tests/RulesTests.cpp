#include "pch.h"
#include "CppUnitTest.h"

#include "../Phase10/Card.h"
#include "../Phase10/PlayedCards.h"
#include "../Phase10/Rules.h"
#include "../Phase10/Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RulesTests
{
	TEST_CLASS(RulesTests)
	{
	public:
		TEST_METHOD(SetNumberOfCardsByPhase)
		{
			Rules rules;
			Player player("Player");
			std::pair<int, int> numberOfCardsForDecks;
			numberOfCardsForDecks.first = 3;
			numberOfCardsForDecks.second = 3;

			Assert::IsTrue(numberOfCardsForDecks == rules.SetNumberOfCardsForDecksByPhase(player));
		}
	};
}