#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters



	pOut->ClearStatusBar();
}


void AddLadderAction::Execute()
{

	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	
	bool added = pGrid->AddObjectToCell(pLadder);
	
	Input* pIn = pGrid->GetInput();
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->AddObjectToCell(pLadder);
		pGrid->PrintErrorMessage("Error: End Cell And Start Cell Are Not In The Same Column | Click To Continue...");
		pIn->GetCellClicked();
		pGrid->RemoveObjectFromCell(startPos);
	}
	if (startPos.GetCellNum() > endPos.GetCellNum()) {
		pGrid->AddObjectToCell(pLadder);
		pGrid->PrintErrorMessage("Error: End Cell Cannot Be Smaller Than Start Cell | Click To Continue...");
		pIn->GetCellClicked();
		pGrid->RemoveObjectFromCell(startPos);
	}
	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		pIn->GetCellClicked();
		pGrid->RemoveObjectFromCell(startPos);

	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}

	


