#include "New_game.h"
#include "Grid.h"
#include "Player.h"


New_game::New_game(ApplicationManager* pap) :Action(pap)
{
}


New_game::~New_game()
{
}

void New_game::ReadActionParameters()
{

}

void New_game::Execute()
{
	// no need for calling ReadActionParameters()
	Grid * pg = pManager->GetGrid();
	Output* pOut = pg->GetOutput();
	pOut->ClearStatusBar();

	bool l = pg->GetEndGame();
	if (l == false)
	{
		for (int i = 0; i<MaxPlayerCount; i++)
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


