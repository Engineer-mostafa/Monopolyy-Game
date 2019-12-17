#include "Snake.h"
#include"Card.h"

Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
	Num_Of_Snakes++;
}


void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

bool Snake::IsOverlapping(GameObject * obj) {

	if (!(dynamic_cast<Card*>(obj)))
		if ((obj->GetPosition()).HCell() == endCellPos.HCell())
			if ((obj->GetPosition()).VCell() <= endCellPos.VCell() && (obj->GetPosition()).VCell() >= position.VCell())
				return true;


	return false;
}
void Snake::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 1)
		OutFile << Num_Of_Snakes << endl;

	if (Type == 1) {
		OutFile << position.GetCellNum() << "  " << endCellPos.GetCellNum() << endl;
	}
	return;


}
void Snake::Load(ifstream &Infile) {
}
Snake::~Snake()
{
	--Num_Of_Snakes;
}



