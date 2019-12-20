#pragma once
#include "Action.h"
#include <fstream>
class OpenGrid : public Action
{
public:
	OpenGrid(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
	bool IsZero(int);
	~OpenGrid();
};

