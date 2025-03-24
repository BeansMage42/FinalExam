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
#include "Player.h"

namespace Game
{
	int PlayerBase::activePlayers = 0;
	
	PlayerBase::PlayerBase(string card1, string card2)
	{
		hand[0] = card1; 
		hand[1] = card2;
		checked = false;
		hasFolded = false;
		chipBetThisRound = 0;
		currentChipPool = 100;
		highestBidThisRound = 0;
		activePlayers++;
		cout << "Player " << activePlayers <<  " Initialized";
	}

	string* PlayerBase:: GetHand()
	{
		return hand;
	}

	int PlayerBase::Check() 
	{
		checked = true;
		return 0;
	}

	int PlayerBase::Raise(int raiseAmount)
	{
		if ((highestBidThisRound + raiseAmount) > currentChipPool) 
		{
			cout << "you dont have enough chips to raise that much, try a different action!";
			return PlayerTurn(highestBidThisRound);
		}
		else
		{
			chipBetThisRound = highestBidThisRound + raiseAmount;
			return chipBetThisRound;
		}
	}

	int PlayerBase::Call() 
	{
		//checks if the player has enough chips left to call
		if (highestBidThisRound > currentChipPool) 
		{
			cout << "you dont have enough chips to call, try a different action!";
			 return PlayerTurn(highestBidThisRound);
		}
		else 
		{
			chipBetThisRound = highestBidThisRound;


			return chipBetThisRound;
		}
	}

	int PlayerBase::Fold()
	{
		hasFolded = true;
		return -1;
	}

	void PlayerBase::WonAmount(int amount) 
	{
		currentChipPool = amount - chipBetThisRound;
		chipBetThisRound = 0;
	}
	void PlayerBase::lostAmount() 
	{
		currentChipPool -= chipBetThisRound;
		//do something to indicate the player is out this round
	}
	PlayerBase::~PlayerBase() 
	{
		activePlayers--;
		cout << "Player destroyed";
	}
	
	int User::PlayerTurn(int highestBid)
	{
		if (hasFolded) return -1;
		highestBidThisRound = highestBid;
		cout << "Your turn! You currently have: " << (currentChipPool - chipBetThisRound) << " chips left and have bid " << currentChipPool << " chips this round.";
		cout << "Chose your action: \n 1: Check \n 2: Call \n 3: Raise \n 4: fold";
		int action;
		int amountOfChipsToAddToPot;
		cin >> action;

		switch (action)
		{
		default:
			cout << "You Checked.";
			amountOfChipsToAddToPot = Check();
			break;
		case 2:
			cout << "You Called!";
			amountOfChipsToAddToPot = Call();
			break;

		case 3:
			cout << "You would like to raise. How many chips above " << highestBid << " would you like to bid?";
			int amountBid;
			cin >> amountBid;
			amountOfChipsToAddToPot = Raise(amountBid);
			break;

		case 4:
			cout << "you have folded, your turn will be skipped until end of round";
			amountOfChipsToAddToPot = Fold();
			break;
		}
		return amountOfChipsToAddToPot;
		
	}

	User::User(string card1, string card2) : PlayerBase(card1,card2)
	{
		cout << "User Initialized";
	}

	Bot::Bot(int personalityType, string card1, string card2) : PlayerBase(card1, card2) 
	{
		personality = personalityType;
	}

	int Bot::PlayerTurn(int highestBid) 
	{
		switch (personality)
		{
		default:

			break;
		}

	}

}