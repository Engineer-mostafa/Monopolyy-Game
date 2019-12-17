#include "to_design_mode.h"
# include "Grid.h"
# include"Player.h"




to_design_mode::to_design_mode(ApplicationManager* pap) : Action(pap)
{
}


to_design_mode::~to_design_mode(void)
{
}

void to_design_mode::ReadActionParameters()
{

}

void to_design_mode::Execute()
{
	// no need for calling  ReadActionParameters()
	Output* pout = pManager->get_Pout();
	pout->ClearStatusBar();
	pout->CreateDesignModeToolBar();
	Grid* pg = pManager->GetGrid();
	pg->SetEndGame(true);
	for (int i = 0; i<MaxPlayerCount; i++)
	{
		Player* p = pg->GetCurrentPlayer();
		CellPosition cellPosistion(8, 0);
		pg->UpdatePlayerCell(p, cellPosistion);
		pg->AdvanceCurrentPlayer();

	}

}

