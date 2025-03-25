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
	
	PlayerBase::PlayerBase(int card1, int card2)
	{
		hand[0] = card1; 
		hand[1] = card2;
		checked = false;
		hasFolded = false;
		chipBetThisRound = 5;
		currentChipPool = 100;
		highestBidThisRound = 5;
		activePlayers++;

		cout << "Player " << activePlayers <<  " Initialized \n";
	}

	int* PlayerBase:: GetHand()
	{
		return hand;
	}

	int PlayerBase::Check() 
	{
		cout << name << " Checked! \n";
		checked = true;
		return 0;
	}

	int PlayerBase::Raise(int raiseAmount)
	{
		
		if ((highestBidThisRound + raiseAmount) > currentChipPool) 
		{
			cout << "you dont have enough chips to raise that much, try a different action! \n";
			return PlayerTurn(highestBidThisRound);
		}
		else
		{
			
			chipBetThisRound += raiseAmount;
			cout << name << " Raised by " << raiseAmount << " to " << raiseAmount << endl;
			return chipBetThisRound;
		}
	}

	int PlayerBase::Call() 
	{
		cout << name << " called! \n";
		//checks if the player has enough chips left to call
		if (highestBidThisRound > currentChipPool) 
		{
			cout << "\n you dont have enough chips to call, try a different action! \n";
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
		cout << name << " has folded! \n";
		hasFolded = true;
		return 0;
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
		cout << "Player destroyed \n";
	}
	
	int User::PlayerTurn(int highestBid)
	{
		if (hasFolded) return -1;
		highestBidThisRound = highestBid;
		cout << "\n Your turn! You currently have: " << (currentChipPool - chipBetThisRound) << " chips left and have bid " << chipBetThisRound << " chips this round. \n";
		cout << "\n Chose your action: \n 1: Check \n 2: Call \n 3: Raise \n 4: fold \n";
		int action;
		int amountOfChipsToAddToPot;
		cin >> action;

		switch (action)
		{
		default:
			
			amountOfChipsToAddToPot = Check();
			break;
		case 2:
			
			amountOfChipsToAddToPot = Call();
			break;

		case 3:
			cout << "You would like to raise. How many chips above " << highestBid << " would you like to bid? \n";
			int amountBid;
			cin >> amountBid;
			amountOfChipsToAddToPot = Raise(amountBid);
			break;

		case 4:
			
			amountOfChipsToAddToPot = Fold();
			break;
		}
		return amountOfChipsToAddToPot;
		
	}

	User::User(int card1, int card2) : PlayerBase(card1,card2)
	{
		name = "Player 1";
		cout << "User Initialized \n";
	}
	User::~User() 
	{
		cout << "Player 1 destroyed\n";
	}
	Bot::Bot(int personalityType, int card1, int card2) : PlayerBase(card1, card2) 
	{
		botNum = activePlayers;
		currentChipPool = 120;
		name = "bot " + std::to_string( botNum -1);
		personality = personalityType;
	}

	int Bot::PlayerTurn(int highestBid)
	{
		//cout << "\n Bot " << botNum << " turn \n ";
		highestBidThisRound = highestBid;
		int betAmount;
		switch (personality)
		{
		default:
			
			betAmount = Call();
			break;
		case 1:
			betAmount = Check();
			break;
		case 2:
			betAmount = Raise((highestBid +10) - chipBetThisRound);
			break;
		}

		return betAmount;
	}

	Bot::~Bot() 
	{
		cout << name << " destroyed\n";
	}
}