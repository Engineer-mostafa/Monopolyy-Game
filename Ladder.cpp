#include "Ladder.h"
#include "Card.h"
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
	Num_Of_Laders++;

}



void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");
	pGrid->GetInput()->GetCellClicked();

	// 2- Apply the ladder's effect by moving the player to the endCellPos

	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	if (endCellPos.GetCellNum() == 99)
	{
		pGrid->SetEndGame(true);
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("Player " + to_string(pGrid->GetcurrPlayerNumber()) + " Has Won");
	}
	((pPlayer->GetCell())->GetGameObject())->Apply(pGrid, pPlayer);

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}
bool Ladder::IsOverlapping(GameObject * obj) {

	if (!(dynamic_cast<Card*>(obj)))
		if ((obj->GetPosition()).HCell() == endCellPos.HCell())
			if ((obj->GetPosition()).VCell() >= endCellPos.VCell() && (obj->GetPosition()).VCell() <= position.VCell())
				return true;


	return false;
}

void Ladder::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 0)
		OutFile << Num_Of_Laders << endl;

	if (Type == 0)
		OutFile << position.GetCellNum() << "  " << endCellPos.GetCellNum() << endl;
	return;
}
void Ladder::Load(ifstream &Infile) {
}
Ladder::~Ladder()
{
	--Num_Of_Laders;
}



