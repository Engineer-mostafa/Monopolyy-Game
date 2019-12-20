#pragma once
#include "Action.h"
#include <fstream>
class OpenGrid : public Action
{
	static bool isopen;
public:
	OpenGrid(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
	bool IsZero(int);
	~OpenGrid();
};

