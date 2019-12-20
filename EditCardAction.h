#pragma once
#include "action.h"
class EditCardAction :
	public Action
{
	CellPosition cardPosition;
	Card * pCard;
public:
	EditCardAction(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~EditCardAction(); // A Virtual Destructor
};