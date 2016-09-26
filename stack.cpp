# include <iostream>
# include "stack.h"


//*************************************************************************************
//Name:  stack
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to size = s_top = 0
//Description:  This is the default constructor which will be called automatically when 
//an object is declared.  It will initialize the state of the class
//*************************************************************************************

stack::stack()
{
	cout << "Inside Default Constructor";
	size = 0;
	s_top = 0;
}


//*************************************************************************************
//Name: ~stack
//Precondition: None
//Postcondition: Deletes all the memory allocted to the object 
//Description: This is a destructor. It is deletes any memeory associated with the object.
//*************************************************************************************

stack::~stack()
{
//	cout << "Inside !stack \n";
	while (s_top != 0)
	{
		pop();
	}
}


//*************************************************************************************
//Name: clearStack()
//Precondition: Check to see if s_top != 0. 
//Postcondition:  pops everything from the stack
//Description: The function pops everything from the stack until s_top is 0
//*************************************************************************************


void stack::clearStack()
{
	while (s_top != 0) 
	{
		pop();
	}
	
}


//*************************************************************************************
//Name: pop()
//Precondition: Check to see if s_top != 0. 
//Postcondition:  returns the top element of the stack
//Description: The function returns the top element from the stack
//*************************************************************************************

string stack::pop()
{
//	cout << "Inside pop \n";
	stack_node *p;
	string charToReturn;

	if (s_top != 0)
	{
		p = s_top;
		charToReturn = s_top->data;
		s_top = s_top->next;
		delete p;
		size--;
	}

	return charToReturn;

}


//*************************************************************************************
//Name: push()
//Precondition: Takes string as a parameter 
//Postcondition:  Adds an element to the top of the stack and increments the size of the stack
//Description: The function takes a string as a parameter and adds the string to the top of the stack, and increments the 
//size of the stack
//*************************************************************************************

void stack::push(string character)
{
//	cout << "Inside push \n";
	stack_node *p = new stack_node;

	p->data = character;
	p->next = s_top;
	s_top = p;
	size++;
}


//*************************************************************************************
//Name: readExpression()
//Precondition: Takes a string as a parameter. 
//Postcondition:  Returns the string converted to infix expression
//Description: The function takes in a string as a parameter and converts it into infix expression, and returns the 
//converted infix operation.
//*************************************************************************************


string stack::readExpression(string expression) {
	string operand1, operand2;

	
	for(int i = 0; i < expression.length(); i++) {
		if(expression[i] == ' ')
			continue;
		else {
			if(expression[i] == '+') {
				if(sizeIsTwoOrMore()) {
					operand2 = pop();
					operand1 = pop();
					push("(" + operand1 + " + " + operand2 + ")");
				} else
					return "Too many operators and not enough operands";
			}
			else if(expression[i] == '-') {
				if(sizeIsTwoOrMore()) {
					operand2 = pop();
					operand1 = pop();
					push("(" + operand1 + " - " + operand2 + ")");
				} else
					return "too many operators and not enough operands";
			}
			else if(expression[i] == '*') {
				if(sizeIsTwoOrMore()) {
					operand2 = pop();
					operand1 = pop();
					push("(" + operand1 + " * " + operand2 + ")");
				} else
					return "too many operators and not enough operands";
			}
			else if(expression[i] == '/') {
				if(sizeIsTwoOrMore()) {
					operand2 = pop();
					operand1 = pop();
					push("(" + operand1 + " / " + operand2 + ")");
				} else
					return "too many operators and not enough operands";
			}
			
			else if (expression.length() == 1) {
				string value(1, expression[i]);
				push("(" + value+ ")");
			}
			
			else {
				string value(1, expression[i]);
				push(value);
			}
		}
		
		if((i == expression.length() - 1) && size != 1) {
			return "Too many operands and not enough operators";
		}
	}

	if ((expression.empty()) || (expression == " "))
	{
		push(" ");
	}

	return s_top->data;
}

//*************************************************************************************
//Name: sizeIsTwoOrMore()
//Precondition: Checks for the size of stack 
//Postcondition:  Returns true if size is more than 2
//Description: The functions returns true if the size of the stack is more than two, else returns false
//*************************************************************************************

bool stack::sizeIsTwoOrMore() {
	if(size >= 2)
		return true;
	else
		return false;
}