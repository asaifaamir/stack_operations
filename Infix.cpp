#include <iostream>
#include "stack.h"


//*********************************************************************************************
//*********************************************************************************************
//	Infix . C P P

/********************************************************************************************

Name:Asaif A Butt           Z#: Z23295634
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 3.04.16         Due Time: 11:30 PM
Total Points: 100
Assignment 5B: Infix Operations

Description: This assignment asks the user to input a postfix expression and converts the postfix to 
infix expression and prints it. 
*********************************************************************************************/

int main()
{
	stack S;
	char rerun = 'y';
	string expression;

	while (rerun == 'Y' || rerun == 'y') 
	{
		cout << "\n\nPlease enter the postfix expression: ";
		getline(cin, expression);
		cout << S.readExpression(expression);
		cout << endl;
		cout << "Would you like to do another conversion?(Y/N) : ";
		cin >> rerun;
		S.clearStack();
		cin.get();
	}

	return 0;
}
