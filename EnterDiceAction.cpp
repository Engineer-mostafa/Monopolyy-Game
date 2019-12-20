#include "EnterDiceAction.h"


#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

EnterDiceAction::EnterDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void EnterDiceAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Enter The DiceNumber");
	while (true) {
		diceNumber = pIn->GetInteger(pOut);
		if (diceNumber<7 && diceNumber>0)
			break;
		pOut->PrintMessage("Please Enter a Valid DiceNumber (It has to be between [1,6])");
	}
}

void EnterDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	ReadActionParameters();
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pGrid->GetEndGame())
	{
		pOut->PrintMessage("The Game Has Ended");
		return;
	}
	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	// time is for different seed each run
	// from 1 to 6 --> should change seed

	// 3- Get the "current" player from pGrid
	Player*pPlayer = pGrid->GetCurrentPlayer();
	// 4- Move the currentPlayer using function Move of class player
	pPlayer->Move(pGrid, diceNumber);
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

EnterDiceAction::~EnterDiceAction()
{
}
