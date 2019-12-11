#pragma once
#include "action.h"
class CopyCardAction :
	public Action
{
	int cardNumber;            // 1- the card number
	CellPosition cardPosition;

public:
	CopyCardAction(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~CopyCardAction(); // A Virtual Destructor

};

