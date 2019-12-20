#include "Input_Dice_Action.h"
#include"Grid.h"
# include"Player.h"
# include<iostream>
using namespace std;




Input_Dice_Action::Input_Dice_Action(ApplicationManager* pap) : Action(pap)
{
}


Input_Dice_Action::~Input_Dice_Action()
{

}

void Input_Dice_Action::ReadActionParameters()
{
	Output* pout = (pManager->GetGrid())->GetOutput();
	pout->ClearStatusBar();
	pout->PrintMessage("Entre Your Dice Value : ");
	Input* Pin = (pManager->GetGrid())->GetInput();
	num = Pin->GetInteger(pout);
	pout->ClearStatusBar();
	Player*p = (pManager->GetGrid())->GetCurrentPlayer();
	pos = ((p->GetCell())->GetCellPosition());

}
void Input_Dice_Action::Execute()
{
	ReadActionParameters();
	Grid*pg = pManager->GetGrid();
	Output* pout = pg->GetOutput();
	if (pg->GetEndGame() == false)
	{
		while (num>6)
		{

			Player* p = pg->GetCurrentPlayer();
			pg->UpdatePlayerCell(p, pos);
			pout->PrintMessage("Sorry! Remember That You Should Enter Value Between 1-6 | So Now Enter Valid Number...");
			Input *Pin = pg->GetInput();
			num = Pin->GetInteger(pout);
			if (num < 6) {
				pout->ClearStatusBar();
				break;
			}

		}
	}

	bool l = pg->GetEndGame();
	if (l == false)
	{
		Player* p = pg->GetCurrentPlayer();
		p->Move(pg, num);
		pg->AdvanceCurrentPlayer();
	}


}


