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






//Due to the limited scope of our final project, the only logical choice to create this system was to make the players and bots. The players and bots already had pseudo code in them
//in our last submission. I did not use any of this pseudocode as a reference, nor did I copy any of it. Everything here is my original thoughts unless citing an outside article
// Function and variables may have the same names, but this is due to my team and I designing the outline of each class collectively on the first project submission
// because I like to have consistent formatting across projects
 


#ifndef PLAYER_H
#define PLAYER_H



using namespace std;
#include <string>
#include <algorithm>
#include <iostream>


namespace Game 
{
	class PlayerBase
	{
	public:
		static int activePlayers;
		int currentChipPool;
		int chipBetThisRound;
		int highestBidThisRound;
		bool checked;
		bool hasFolded;
		int hand[2];
		string name;
		PlayerBase(int card1, int card2);
		virtual int PlayerTurn(int highestBid) = 0;
		int* GetHand();
		int Check();
		int Raise(int raiseAmount);
		int Call();
		int Fold();
		void WonAmount(int amount);
		void lostAmount();
		
		virtual ~PlayerBase();

	};

	class User : public PlayerBase 
	{
	public:
		User(int card1, int card2);
		int PlayerTurn(int highestBid) override;
		~User();
	};

	class Bot final : public PlayerBase 
	{
	public:
		int personality;
		int botNum;
		Bot(int personalityType, int card1, int card2);
		int PlayerTurn(int highestBid) override final;
		~Bot();
	};
}
#endif //PLAYER_H