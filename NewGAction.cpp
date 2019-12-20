#include "NewGAction.h"
#include "Grid.h"
#include "Player.h"


NewGAction::NewGAction(ApplicationManager* pap) :Action(pap)
{
}


NewGAction::~NewGAction()
{
}

void NewGAction::ReadActionParameters()
{

}

void NewGAction::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	pOut->PrintMessage("Are You Sure You Want Create New Game ? Click 1 - 0 | YES = 1 || NO == 0");
	int i = pIn->GetInteger(pOut);
	if (i == 1) {
		// no need for calling ReadActionParameters()
		Grid * pg = pManager->GetGrid();
		Output* pOut = pg->GetOutput();
		pOut->ClearStatusBar();

		bool l = pg->GetEndGame();
		if (l == false)
		{
			for (int i = 0; i < MaxPlayerCount; i++)
			{
				Player* p = pg->GetCurrentPlayer();
				CellPosition cellPosistion(8, 0);
				p->SetWallet(100);
				pg->UpdatePlayerCell(p, cellPosistion);
				p->set_turncount(0);
				pg->AdvanceCurrentPlayer();

			}
			while ((pg->GetCurrentPlayer())->get_curr_player_num() != 0)
			{
				pg->AdvanceCurrentPlayer();
			}


		}
	}
	else
	{
		pOut->PrintMessage("You Just Cancelled The New Game | Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}



}
