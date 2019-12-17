#include "CardTwo.h"



CardTwo::CardTwo(const CellPosition & pos) : Card(pos)
{
	cardNumber = 2;
}
void CardTwo::ReadCardParameters(Grid * pGrid) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardTwo: Enter The Value That You Need To Increase The Wallet Of Passing Player...");
	vofincreament = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer) {

	Card::Apply(pGrid, pPlayer);
	pPlayer->SetWallet(pPlayer->GetWallet() + vofincreament);
}

CardTwo::~CardTwo()
{
}
void CardTwo::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 2)
		OutFile << Num_Of_Cardes << endl;

	if (Type == 2)
		OutFile << GetCardNumber() << "  " << position.GetCellNum() << " " << vofincreament << endl;
	return;

}
void CardTwo::Load(ifstream &Infile) {

}