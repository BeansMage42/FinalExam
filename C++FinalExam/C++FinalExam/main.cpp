//I, Jonah Gibson, affirm that all work submitted for this midterm is my own.I have not collaborated with
//others, received unauthorized assistance, or used AI tools without proper acknowledgment.Any authorized resources,
//including reference materials and Large Language Models(LLMs), have been explicitly credited.
//If I included code or text from others or LLMs, I have clearly documented the source, including the prompt, LLM
//name, and version.My submission represents my own understanding and effort; AI tools have only been used as a
//supplementary aid, not to generate entire answers.
//I understand that failure to credit sources, unauthorized collaboration, or reliance on LLMs for complete answers
//constitutes academic misconduct.I have not and will not share or distribute any part of this midterm during or after
//the exam.
//I consent to plagiarism detection measures and acknowledge that violations may result in penalties, including a grade
//of zero or disciplinary action.By typing my name above, I commit to academic integrity and accept full responsibility
//for my work




//This system is meant to simulate a single turn cycle of my poker game using the inheritence structure to create user and bot classes


using namespace std;

#include "Player.h"
#include <algorithm>    // std::random_shuffle
#include <memory>
#include <random>
//Assume deck order goes as 0 = club, 1 = spade, 2 = diamond, 3 = heart
// rank is a number between 0 and 11 (add 2 for the actual number on card because cards start at 2 and end at 13 for aces)
// card = suit * 13 + rank
 string EvaluateCard(int cardnum);
int main() {
	using namespace Game;
	
	
	int deck[52];
	int activePlayer = 0;
	int highestBet = 5;
	int currentPot = 20;
	int commCards[5];
	int deckDepth = 0;
	
	for (int i = 0;  i < 51; i++)
	{
		deck[i] = i;
	}
	//the ability to shuffle the deck was found here https://stackoverflow.com/questions/14720134/is-it-possible-to-random-shuffle-an-array-of-int-elements
	std::random_device rd;   //when i couldnt figure out why the deck would have duplicate cards using the stack overflow method, I asked chatgpt for help https://chatgpt.com/share/67e20dfb-68ac-8006-b542-35dc1d2be754
	std::mt19937 rng(rd());

	std::shuffle(std::begin(deck), std::end(deck), rng);
	
	for (deckDepth; deckDepth < 4; deckDepth++)
	{
		commCards[deckDepth] = deck[deckDepth];
	}
	
	//this reddit comment helped me figure out how to make an array using unique pointers https://www.reddit.com/r/learnprogramming/comments/lp15tn/comment/go8rtdg/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
	std::unique_ptr< PlayerBase> players[4];

	players[0] = std::make_unique<User>(deck[5], deck[6]);
	players[1] = std::make_unique<Bot>(1, deck[7], deck[8]);
	players[2] = std::make_unique<Bot>(2, deck[9], deck[10]);
	players[3] = std::make_unique<Bot>(3, deck[11], deck[12]);
	
	int* ptr;
	for (activePlayer; activePlayer < 4; activePlayer++) 
	{
		ptr = players[activePlayer]->GetHand();
		std::cout << "\n it is " << players[activePlayer]->name << "'s turn";
		std::cout << "\n Current pot = " << currentPot;
		std::cout << "\n Revealed cards are: ";
		for (int card: commCards)
		{
			std::cout << EvaluateCard(card) << " , ";
		}
		std::cout << "\n Your hand is: " << EvaluateCard(ptr[0]) << " and " << EvaluateCard(ptr[1]);
		std::cout << "\n the highest bet this round is " << highestBet << "\n";

		int bet = players[activePlayer]->PlayerTurn(highestBet);
		if (bet > highestBet) highestBet = bet;
		int temp = 0;
		for (int a = 0; a < 4; a++ )
		{
			
			temp += players[a]->chipBetThisRound;
		}
		currentPot = temp;
		
	}
	std::cout << "the ending pot is " << currentPot << endl;

	return 0;
}


//i found the card formulas here: https://cowboyprogramming.com/2007/01/04/programming-poker-ai/
//I did not use anything else

string EvaluateCard(int cardNum)
{
	int rank = (cardNum % 13);

	int suit = std::floor(cardNum / 13);
	string suitName;
	string rankName;

	switch (rank)
	{
	
	case 9:
		rankName = "Jack";
		break;
	case 10:
		rankName = "Queen";
		break;
	case 11:
		rankName = "King";
		break;
	case 12:
		rankName = "Ace";
		break;
	default:
		rankName = std::to_string((rank + 2));
		break;
	}

	switch (suit)
	{
	
	case 1:
		suitName = "Spades";
		break;
	case 2:
		suitName = "Diamonds";
		break;
	case 3:
		suitName = "Hearts";
		break;
	default:
		suitName = "Clubs";
		break;
	}
	return rankName + " of " + suitName;
}







