#include "CardFive.h"

CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}

CardFive::~CardFive(void)
{
	Num_Of_Cardes--;

}
CardFive::CardFive()
{
	Num_Of_Cardes++;

}
void CardFive::ReadCardParameters(Grid * pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	CellPosition cp((pPlayer->GetCell())->GetCellPosition().GetCellNum() + pPlayer->GetjustRolledDiceNum());
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	//
	if (!cp.IsValidCell() || cp.GetCellNum() == 99)
	{
		CellPosition cf(99);
		pGrid->UpdatePlayerCell(pPlayer, cf);
		pGrid->SetEndGame(true);
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("Player Number " + to_string(pGrid->GetcurrPlayerNumber()) + " Has Won");
	}
	else

		pGrid->UpdatePlayerCell(pPlayer, cp);


}
void CardFive::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 2)
		OutFile << Num_Of_Cardes << endl;

	if (Type == 2)
		OutFile << GetCardNumber() << "  " << position.GetCellNum() << endl;
	return;

}


