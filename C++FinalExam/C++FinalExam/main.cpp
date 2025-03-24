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

using namespace std;

#include "Player.h"



int main() {
	using namespace Game;
	
	PlayerBase* players[4]; // Array of pointers to base class
	int activePlayer = 0;
	int highestBet = 5;
	int currentPot = 20;
	players[0] = new User(string("four of hearts"), string("Ace of Diamonds"));

	string* ptr;
	ptr = players[0]->GetHand();

	cout << "Your hand is: " << ptr[0] << " and " << ptr[1];

	return 0;
}








