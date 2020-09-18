#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <string>

using std::string;


/*This function returns a validated integer choice from the user input.
It takes two strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int mainMenu(string, string);

#endif