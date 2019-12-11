#include "SaveGridAction.h"
#include<string.h>
#include "Input.h"
#include "Output.h"
#include "Grid.h"

SaveGridAction::SaveGridAction(ApplicationManager *pApp) : Action(pApp)
{

}
void SaveGridAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You Will Save The Grid");


	// Clear messages
	pOut->ClearStatusBar();
}

void SaveGridAction::Execute() {

	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Enter Your Grid Name");

	string x = pIn->GetSrting(pOut);
	ofstream Out;

	Out.open(x + ".txt");


	pGrid->SaveAll(Out, 0);


	pGrid->SaveAll(Out, 1);


	pGrid->SaveAll(Out, 2);

	Out.close();
}

SaveGridAction::~SaveGridAction()
{
}
