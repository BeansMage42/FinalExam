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



#ifndef PLAYER_H
#define PLAYER_H



using namespace std;
#include <string>
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
		string hand[2];
		PlayerBase(string card1, string card2);
		virtual int PlayerTurn(int highestBid) = 0;
		string* GetHand();
		int Check();
		int Raise(int raiseAmount);
		int Call();
		int Fold();
		void WonAmount(int amount);
		void lostAmount();
		~PlayerBase();

	};

	class User : public PlayerBase 
	{
	public:
		User(string card1, string card2);
		int PlayerTurn(int highestBid) override;
		//~User();
	};

	class Bot final : public PlayerBase 
	{
	public:
		int personality;// 1 = greedy, 2 = conservative, 3 = wildcard
		
		Bot(int personalityType, string card1, string card2);
		int PlayerTurn(int highestBid) override final;
		//~Bot();
	};

	
	

	
}
#endif //PLAYER_H