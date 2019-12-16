#include "CardNine.h"



CardNine::CardNine(const CellPosition & pos) : Card(pos)
{
	cardNumber = 9;
}
void CardNine::ReadCardParameters(Grid * pGrid) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardNine: Enter The CellNumber That You Need The Player To Go To If He Pass By This Card...");
	sCellNumber = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();

}

void CardNine::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	int currentcell = pPlayer->GetCell()->GetGameObject()->GetPosition().GetCellNum();
	int diffroll;
	if (currentcell > sCellNumber) {
		diffroll = currentcell - sCellNumber;
		CellPosition cp(currentcell - diffroll);
		pGrid->UpdatePlayerCell(pPlayer, cp);
	}
	else {
		diffroll = sCellNumber - currentcell;
		CellPosition cp(currentcell + diffroll);
		pGrid->UpdatePlayerCell(pPlayer, cp);
	}


}
CardNine::~CardNine()
{
}
