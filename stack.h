#pragma once
#include <iostream>
#include <string>


//*********************************************************
//Stack.h
//*********************************************************

using namespace std;

typedef string stack_element;

class stack_node
{
public:
	string data;
	stack_node *next;
};

class stack
{
public:
	stack(); //Default Constructor
	~stack();	//Destructor
	void clearStack();	//Clears the stack
	string pop();		//pops the top element from the stack
	void push(string);	//pushes a string to the top of the stack
	string readExpression(string expression);	//reads a postfix expression and converts it to infix

private:
	int size;
	stack_node *s_top;
	bool sizeIsTwoOrMore(); //Checks for the size of the expression
};
