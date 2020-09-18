#include "Validation.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::istringstream;
using std::string;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

/*This defines the getline() function used to check the user
input.  If it can pull in data, convert to an int and there is
no remainder, it passes the data to the inputValidate function.
Citation: www.cplusplus.com/forum/beginner/170685/#msg851160*/
istream& getline(istream& ins, int& n)
{
	n = 0;  

	// Read a line from the user
	string s;
	if (getline(ins, s))
	{
		// Get rid of any following whitespace
		s.erase(s.find_last_not_of(" \f\n\r\t\v") + 1);

		// Convert it to integer
		istringstream ss(s);
		ss >> n;

		// Make sure nothing else is in the stream
		if (!ss.eof())
			ins.setstate(std::ios::failbit);
	}
	//Value is used by inputValidate()
	return ins;
}

/*This function returns a validated integer choice from the user input.
It takes two integers, representing the lower and upper bounds of the
allowed input and compares the user input to the allowed range.  If the
input is incorrect, it asks the user to try again. If getline() cannot
convert the user input to an integer, it also asks them to try again.*/
int inputValidate(int lower, int upper)
{
	int userInput = 0; //placeholder for user input
	int bottomRange = lower; //integer below acceptable range
	int topRange = upper; //integer above acceptable range

	while (!getline(cin, userInput) || (userInput < bottomRange) || (userInput > topRange))
	{
		cin.clear();
		cout << "That was invalid. Please enter an integer from " << bottomRange << " to " << topRange << ": ";
	}

	return userInput;
}