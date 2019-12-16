#include "CardEight.h"

#include "Grid.h"
#include "Player.h"



CardEight::CardEight(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (1 here)
	prevent[0] = 1;
	prevent[1] = 1;
	prevent[2] = 1;
	prevent[3] = 1;
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid * pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	//  Call Apply() of the base class Card to print the message that you reached this card number

	if (prevent[pGrid->GetcurrPlayerNumber()] == 1)
		Card::Apply(pGrid, pPlayer);

}
int CardEight::IsPrevented(int playernum)
{
	if (prevent[playernum] == 1)
		return prevent[playernum]--;

	if (prevent[playernum] == 0)
		return prevent[playernum]++;

}