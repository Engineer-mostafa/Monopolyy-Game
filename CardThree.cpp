#include "CardThree.h"
#include"Ladder.h"

#include"Cell.h"
#include"CellPosition.h"

CardThree::CardThree(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (3 here)
}
CardThree::CardThree()
{
	Num_Of_Cardes++;
}
CardThree::~CardThree(void)
{
	Num_Of_Cardes--;

}

void CardThree::ReadCardParameters(Grid * pGrid)
{



}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	//pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition())->GetPosition().GetCellNum();
	//pPlayer->GetCell()->GetCellPosition().GetCellNum();
	if (pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition()))
	{
		pGrid->UpdatePlayerCell(pPlayer, pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition())->GetPosition());
		((pPlayer->GetCell())->GetGameObject())->Apply(pGrid, pPlayer);
	}
	else
	{
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("There is No Ladders Forward");
	}
}

void CardThree::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 2)
		OutFile << Num_Of_Cardes << endl;

	if (Type == 2)
		OutFile << GetCardNumber() << "  " << position.GetCellNum() << endl;
	return;

}
