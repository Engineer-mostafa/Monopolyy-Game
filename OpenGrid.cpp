#include "OpenGrid.h"
#include<string.h>
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include"CardEight.h"
#include "CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"
OpenGrid::OpenGrid(ApplicationManager *pApp) : Action(pApp)
{

}
void OpenGrid::ReadActionParameters() {

}
void OpenGrid::Execute() {
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Are You Sure You Want To Open Grid ? Click 1 - 0 | YES = 1 || NO == 0");
	int i = pIn->GetInteger(pOut);
	if (i == 1) {

		pOut->PrintMessage("Please Enter Your Grid Name");

		string x = pIn->GetSrting(pOut);
		ifstream In;
		In.open(x + ".txt");

		int y, r;
		In >> y;
		Snake *pSnake = NULL;
		Ladder *pLadder = NULL;
		Card *pCard = NULL;

		if (IsZero(y))
		{
			In >> y;
			if (IsZero(y))
			{
				In >> y;
				if (IsZero(y)) {}
				else
				{
					for (int i = 0; i < y; i++)
					{
						In >> r;
						switch (r)
						{
						case 1:
							pCard = new CardOne;
							pCard->Load(In, pGrid, r);
							break;
						case 2:
							pCard = new CardTwo;
							pCard->Load(In, pGrid, r);
							break;
						case 3:
							pCard = new CardThree;
							pCard->Load(In, pGrid, r);
							break;
						case 4:
							pCard = new CardFour;
							pCard->Load(In, pGrid, r);
							break;
						case 5:
							pCard = new CardFive;
							pCard->Load(In, pGrid, r);
							break;
						case 6:
							pCard = new CardSix;
							pCard->Load(In, pGrid, r);
							break;
						case 7:
							pCard = new CardSeven;
							pCard->Load(In, pGrid, r);
							break;
						case 8:
							pCard = new CardEight;
							pCard->Load(In, pGrid, r);
							break;
						case 9:
							pCard = new CardNine;
							pCard->Load(In, pGrid, r);
							break;
						case 10:
							pCard = new CardTen;
							pCard->Load(In, pGrid, r);
							break;
						case 11:
							pCard = new CardEleven;
							pCard->Load(In, pGrid, r);
							break;
						case 12:
							pCard = new CardTwelve;
							pCard->Load(In, pGrid, r);
							break;
						case 13:
							pCard = new CardThirteen;
							pCard->Load(In, pGrid, r);
							break;
						case 14:
							pCard = new CardFourteen;
							pCard->Load(In, pGrid, r);
							break;
						}
					}
				}
			}
			else
			{

				for (int i = 0; i < y; i++)
				{
					pSnake = new Snake;
					pSnake->Load(In, pGrid, 0);
					In >> y;
					if (IsZero(y)) {}
					else
					{
						In >> r;
						switch (r)
						{
						case 1:
							pCard = new CardOne;
							pCard->Load(In, pGrid, r);
							break;
						case 2:
							pCard = new CardTwo;
							pCard->Load(In, pGrid, r);
							break;
						case 3:
							pCard = new CardThree;
							pCard->Load(In, pGrid, r);
							break;
						case 4:
							pCard = new CardFour;
							pCard->Load(In, pGrid, r);
							break;
						case 5:
							pCard = new CardFive;
							pCard->Load(In, pGrid, r);
							break;
						case 6:
							pCard = new CardSix;
							pCard->Load(In, pGrid, r);
							break;
						case 7:
							pCard = new CardSeven;
							pCard->Load(In, pGrid, r);
							break;
						case 8:
							pCard = new CardEight;
							pCard->Load(In, pGrid, r);
							break;
						case 9:
							pCard = new CardNine;
							pCard->Load(In, pGrid, r);
							break;
						case 10:
							pCard = new CardTen;
							pCard->Load(In, pGrid, r);
							break;
						case 11:
							pCard = new CardEleven;
							pCard->Load(In, pGrid, r);
							break;
						case 12:
							pCard = new CardTwelve;
							pCard->Load(In, pGrid, r);
							break;
						case 13:
							pCard = new CardThirteen;
							pCard->Load(In, pGrid, r);
							break;
						case 14:
							pCard = new CardFourteen;
							pCard->Load(In, pGrid, r);
							break;
						}
					}

				}


			}
		}
		else
		{
			for (int i = 0; i < y; i++)
			{
				pLadder = new Ladder;
				pLadder->Load(In, pGrid, 0);

			}
			In >> y;
			if (IsZero(y)) {
				In >> y;
				if (IsZero(y)) {}
				else
				{
					for (int i = 0; i < y; i++)
					{
						In >> r;
						switch (r)
						{
						case 1:
							pCard = new CardOne;
							pCard->Load(In, pGrid, r);
							break;
						case 2:
							pCard = new CardTwo;
							pCard->Load(In, pGrid, r);
							break;
						case 3:
							pCard = new CardThree;
							pCard->Load(In, pGrid, r);
							break;
						case 4:
							pCard = new CardFour;
							pCard->Load(In, pGrid, r);
							break;
						case 5:
							pCard = new CardFive;
							pCard->Load(In, pGrid, r);
							break;
						case 6:
							pCard = new CardSix;
							pCard->Load(In, pGrid, r);
							break;
						case 7:
							pCard = new CardSeven;
							pCard->Load(In, pGrid, r);
							break;
						case 8:
							pCard = new CardEight;
							pCard->Load(In, pGrid, r);
							break;
						case 9:
							pCard = new CardNine;
							pCard->Load(In, pGrid, r);
							break;
						case 10:
							pCard = new CardTen;
							pCard->Load(In, pGrid, r);

							break;
						case 11:
							pCard = new CardEleven;
							pCard->Load(In, pGrid, r);
							break;
						case 12:
							pCard = new CardTwelve;
							pCard->Load(In, pGrid, r);
							break;
						case 13:
							pCard = new CardThirteen;
							pCard->Load(In, pGrid, r);
							break;
						case 14:
							pCard = new CardFourteen;
							pCard->Load(In, pGrid, r);
							break;
						}
					}

				}
			}
			else
			{
				for (int i = 0; i < y; i++)
				{
					pSnake = new Snake;
					pSnake->Load(In, pGrid, 0);
				}
				In >> y;
				if (IsZero(y)) {}
				else
				{
					for (int i = 0; i < y; i++)
					{
						In >> r;
						switch (r)
						{
						case 1:
							pCard = new CardOne;
							pCard->Load(In, pGrid, r);
							break;
						case 2:
							pCard = new CardTwo;
							pCard->Load(In, pGrid, r);
							break;
						case 3:
							pCard = new CardThree;
							pCard->Load(In, pGrid, r);
							break;
						case 4:
							pCard = new CardFour;
							pCard->Load(In, pGrid, r);
							break;
						case 5:
							pCard = new CardFive;
							pCard->Load(In, pGrid, r);
							break;
						case 6:
							pCard = new CardSix;
							pCard->Load(In, pGrid, r);
							break;
						case 7:
							pCard = new CardSeven;
							pCard->Load(In, pGrid, r);
							break;
						case 8:
							pCard = new CardEight;
							pCard->Load(In, pGrid, r);
							break;
						case 9:
							pCard = new CardNine;
							pCard->Load(In, pGrid, r);
							break;
						case 10:
							pCard = new CardTen;
							pCard->Load(In, pGrid, r);
							break;
						case 11:
							pCard = new CardEleven;
							pCard->Load(In, pGrid, r);
							break;
						case 12:
							pCard = new CardTwelve;
							pCard->Load(In, pGrid, r);
							break;
						case 13:
							pCard = new CardThirteen;
							pCard->Load(In, pGrid, r);
							break;
						case 14:
							pCard = new CardFourteen;
							pCard->Load(In, pGrid, r);
							break;

						}
					}
				}
			}
		}




		In.close();
		pOut->PrintMessage("You Just Open The Grid Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
	}
	else {
		pOut->PrintMessage("You Just Cancelled The Open | Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}




}
bool OpenGrid::IsZero(int x) {
	if (x == 0)
		return true;

	return false;
}

OpenGrid::~OpenGrid()
{
}
