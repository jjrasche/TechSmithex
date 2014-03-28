#include <iostream>
#include <string>
#include <cstdlib>
#include "calc.h"
using namespace std;

void unit_test();

int main()
{
	unit_test();
	return(0);
}

int test_string(string input)
{
	cout << input << '\n';
	int answer = -1;
	if(!isCorrectFormat(input)) {
		cout << "format error";
		errorMessage(" in testing", ERROR);
	}
	else {
		answer = parseInput(input);
		cout << answer;
	}
	cout << "\n\n";
	return(answer);
}

void error(string input)
{
	cout << "error on input '" << input << "'" << '\n';
	exit(1);
}

void unit_test()
{
	//good
	int b = test_string("10 - 5");

	if(test_string("10 - 5") != 5)	error("10 - 5");			// normal
	if(test_string("-10 - 5") != -15) error("-10 - 5");			// one negative
	if(test_string("10 - -5") != 15) error("10 - -5");			
	if(test_string("-10 - -5") != -5) error("-10 - -5");			// both negative
	if(test_string("10-5") != 5) error("10-5");					// no spaces
	if(test_string("10-5") != 5) error("10-5");					// no spaces
	if(test_string("10 	-	5") != 5) error("10 	-	5");	// tabs
	if(test_string("10 + 5") != 15) error("10 + 5");			// operations
	if(test_string("10 * 5") != 50) error("10 * 5");
	if(test_string("10 / 5") != 2) error("10 / 5");


	//bad
	if(test_string("-10 - -5-") != -1)	error("-10 - -5-");		// too many "-"
	if(test_string("flasdjfoi") != -1) error("flasdjfoi");		// invalid characters
	if(test_string("-10 - 5     a") != -1) error("-10 - 5     a");	

	if(test_string("10 * 5   *") != -1) error("10 * 5   *");	// too many "*"		
	if(test_string("10*5   *") != -1) error("10*5   *");		
	if(test_string("10 *-5   *") != -1) error("10 *-5   *");	// spacing 		
	if(test_string("-10+-5") != 5) error("-10+-5");		
	
}


