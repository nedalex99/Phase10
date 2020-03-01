#include "pch.h"
#include"CppUnitTest.h"

#include"../Phase10/Deck.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace DeckTests
{
	TEST_CLASS(DeckTests)
	{
	public:
		TEST_METHOD(GetSize)
		{
			Deck deck;
			int expcetedSize = 108;
			Assert::IsTrue(expcetedSize == deck.GetSize());
		}
		TEST_METHOD(Reinitialize) /*reset the round after a player finished his cards*/
		{
			Deck deck;
			deck.Reinitialize();
			int expectedDeckSize = 108;

			Assert::IsTrue(expectedDeckSize == deck.GetSize());
		}
	};
}