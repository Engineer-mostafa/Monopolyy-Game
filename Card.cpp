#include "Card.h"


Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
	Num_Of_Cardes++;
}

void Card::SetCardNumber(int cnum)
{
	if (cnum>0 && cnum<15)
		cardNumber = cnum; // needs validation

}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

bool Card::IsOverlapping(GameObject * obj) {

	if (dynamic_cast<Card*>(obj))
		if (((obj->GetPosition()).VCell()) == position.VCell() && ((obj->GetPosition()).HCell()) == position.HCell())
			return true;

	return false;
}

void Card::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 2)
		OutFile << Num_Of_Cardes << endl;

	if (Type == 2)
		OutFile << GetCardNumber() << "  " << position.GetCellNum() << endl;
	return;
}
void Card::Load(ifstream &Infile) {

}
Card::~Card()
{
	--Num_Of_Cardes;
}


