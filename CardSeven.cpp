#include "CardSeven.h"
#include "Grid.h"
#include "Player.h"

#include <time.h>


CardSeven::CardSeven(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (1 here)
}
CardSeven::CardSeven()
{
	Num_Of_Cardes++;
}

CardSeven::~CardSeven(void)
{
	Num_Of_Cardes--;

}

void CardSeven::ReadCardParameters(Grid * pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	//  Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Output* pOut = pGrid->GetOutput();
	if (pGrid->GetEndGame())
	{
		return;
	}
	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

									 // 3- Get the "current" player from pGrid

									 // 4- Move the currentPlayer using function Move of class player
	pPlayer->Move(pGrid, diceNumber);
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).


}
void CardSeven::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 2)
		OutFile << Num_Of_Cardes << endl;

	if (Type == 2)
		OutFile << GetCardNumber() << "  " << position.GetCellNum() << endl;
	return;

}
