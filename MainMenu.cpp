#include "Validation.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*This function returns a validated integer choice from the user input.
It takes two strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int mainMenu(string a, string b)
{
	cout << "Please select an option:" << endl;
	cout << "1. " << a << " (Enter 1 to select)" << endl;
	cout << "2. " << b << " (Enter 2 to select)" << endl;

	int choice = inputValidate(1, 2);

	return choice;	
}