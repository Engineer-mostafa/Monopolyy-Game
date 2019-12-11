#pragma once
#include "Action.h"
class DeleteGameObject : public Action
{
	CellPosition pos;

public:


	DeleteGameObject(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)

	virtual void Execute();


	virtual ~DeleteGameObject(); // Virtual Destructor




};