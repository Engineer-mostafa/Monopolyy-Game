#include "CardSix.h"


CardSix::CardSix(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (1 here)
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid * pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	CellPosition cp((pPlayer->GetCell())->GetCellPosition().GetCellNum() - pPlayer->GetjustRolledDiceNum());
	pGrid->UpdatePlayerCell(pPlayer, cp);
}
