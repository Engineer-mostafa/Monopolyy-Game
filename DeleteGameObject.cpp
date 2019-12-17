#include"DeleteGameObject.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"

DeleteGameObject::DeleteGameObject(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

DeleteGameObject::~DeleteGameObject()
{
}

void DeleteGameObject::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("Delete Game Object: Click on its Start Cell ...");
	pos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}

void DeleteGameObject::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Are You Sure You Need To Delete Game Object ? Click 1 - 0 | YES = 1 || NO == 0");
	int i = pIn->GetInteger(pOut);
	if (i == 1) {
		ReadActionParameters();

		Grid * pGrid = pManager->GetGrid();

		pGrid->RemoveObjectFromCell(pos);
	}
	else
	{
		pOut->PrintMessage("You Just Cancelled The Delete Game Object | Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}



}