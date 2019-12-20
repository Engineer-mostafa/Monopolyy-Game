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

}

void SaveGridAction::Execute() {

	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Are You Sure You Want To Save Grid ? Click 1 - 0 | YES = 1 || NO == 0");
	int i = pIn->GetInteger(pOut);
	if (i == 1) {
		pOut->PrintMessage("Please Enter Your Grid Name");

		string x = pIn->GetSrting(pOut);
		ofstream Out;

		Out.open(x + ".txt", ios::out);


		pGrid->SaveAll(Out, 0);


		pGrid->SaveAll(Out, 1);


		pGrid->SaveAll(Out, 2);

		Out.close();
		pOut->PrintMessage("You Just Saved The Grid Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
	}
	else {
		pOut->PrintMessage("You Just Cancelled The Save | Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}



}

SaveGridAction::~SaveGridAction()
{
}
