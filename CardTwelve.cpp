#include "CardTwelve.h"


CardTwelve::CardTwelve(const CellPosition & pos) : Card(pos)
{
	cardNumber = 12;
}

bool CardTwelve::card_bought = false;
bool CardTwelve::created_before = false;
int CardTwelve::cardprice = 0;
int CardTwelve::fees = 0;

CardTwelve::CardTwelve() {
	Num_Of_Cardes++;
}

CardTwelve::~CardTwelve(void)
{
	Num_Of_Cardes--;
	IsSaved = false;
	IsLoaded = false;

}

void CardTwelve::ReadCardParameters(Grid * pGrid)
{
	if (created_before == false)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Plesae Entre Card 12 Fees :");
		fees = pIn->GetInteger(pOut);
		pOut->PrintMessage("Please Entre Card 12 Price :");
		cardprice = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
		Card::Draw(pOut);
		created_before = true;
	}
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (card_bought == true)
	{
		if (pPlayer->get_card12_owner() == false)
		{
			pOut->PrintMessage("Sorry! You Will Pay Card 12 Fees To Pass | Click To Continue...");
			pIn->GetCellClicked();
			pOut->ClearStatusBar();
			pPlayer->SetWallet((pPlayer->GetWallet()) - fees);
		}

	}
	else
	{
		Card::Apply(pGrid, pPlayer);
		pOut->ClearStatusBar();
		pOut->PrintMessage("Now You On Card 12 And No One Bought This Card Do You Want To Buy This Card ? Click 1 - 0 | YES = 1 || NO == 0");
		int i = pIn->GetInteger(pOut);
		if (i == 1) 
		{
			pPlayer->SetWallet((pPlayer->GetWallet()) - cardprice);
			pOut->PrintMessage("Congratulations | You Have Just Bought card 12 | Click To Continue... ");
			pPlayer->set_card12_owner(true);
			card_bought = true;
			pIn->GetCellClicked();
			pOut->ClearStatusBar();
		}
	}
}

void CardTwelve::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 2)
		OutFile << Num_Of_Cardes << endl;

	if (Type == 2) {
		OutFile << GetCardNumber() << " " << position.GetCellNum() << " ";
		if (IsSaved) { OutFile << endl; }
		else
		{
			OutFile << cardprice << " " << fees << endl;
			IsSaved = true;
		}

	}
	return;

}
void CardTwelve::Load(ifstream &Infile, Grid *g, int r) {
	cardNumber = r;
	int cellnumber;
	CellPosition *c = new CellPosition;
	Infile >> cellnumber;
	position = c->GetCellPositionFromNum(cellnumber);
	if (IsLoaded) {}
	else
	{
		Infile >> cardprice;
		Infile >> fees;
		IsLoaded = true;
	}

	g->AddObjectToCell(this);
	Draw(g->GetOutput());
}
bool CardTwelve::IsSaved = false;
bool CardTwelve::IsLoaded = false;

