#include "CardNine.h"



CardNine::CardNine(const CellPosition & pos) : Card(pos)
{
	cardNumber = 9;
}
void CardNine::ReadCardParameters(Grid * pGrid) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardNine: Enter The CellNumber (: | That You Need The Player To Go To If He Pass By This Card...");
	sCellNumber = pIn->GetInteger(pOut);

	if (sCellNumber > 99 || sCellNumber < 0) {
		pOut->PrintMessage("I Think You Entered Invalid Cell Number | Please Enter Number Between 1 : 99 ...");
		while (true)
		{
			sCellNumber = pIn->GetInteger(pOut);
			if (sCellNumber > 99 || sCellNumber < 0) {
				pOut->PrintMessage("I Think You Entered Invalid Cell Number Again  | Please Enter Number Between 1 : 99 ...");
				continue;
			}
			break;
		}
	}
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
		if (pPlayer->GetCell()->GetGameObject()) {
			((pPlayer->GetCell())->GetGameObject())->Apply(pGrid, pPlayer);
		}
	}
	else {
		diffroll = sCellNumber - currentcell;
		CellPosition cp(currentcell + diffroll);
		pGrid->UpdatePlayerCell(pPlayer, cp);
		if (sCellNumber == 99) {
			Output* pOut = pGrid->GetOutput();
			pOut->PrintMessage("Player Number " + to_string(pGrid->GetcurrPlayerNumber()) + " Has Won");
			pGrid->SetEndGame(true);
		}
		if (pPlayer->GetCell()->GetGameObject()) {
			((pPlayer->GetCell())->GetGameObject())->Apply(pGrid, pPlayer);
		}
	}


}
void CardNine::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 2)
		OutFile << Num_Of_Cardes << endl;

	if (Type == 2)
		OutFile << GetCardNumber() << "  " << position.GetCellNum() << " " << sCellNumber << endl;
	return;

}
void  CardNine::Load(ifstream &Infile) {

}
CardNine::~CardNine()
{
}
