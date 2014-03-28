#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include "calc.h"
using namespace std;

unsigned npos = 0xffffffffffffffff;   // for a 64 bit machine...
char valid_characters[NUMVALIDCHARS] = "0123456789-*/+ \t";
char space[3] = "\t ";
char number[11] = "0123456789";
char op[5] = "-+/*";



// first input character is a number, has at most 3 '-', has at most 1 '*','/', and '+'
bool isCorrectFormat(string input)
{
	if(std::count(input.begin(), input.end(), '-') > 3)	return(false);
	if(std::count(input.begin(), input.end(), '+') > 1)	return(false);
	if(std::count(input.begin(), input.end(), '*') > 1)	return(false);
	if(std::count(input.begin(), input.end(), '/') > 1)	return(false);
	if(std::count(input.begin(), input.end(), '-') > 3)	return(false);
	if(std::find_if(input.begin(), input.end(), bad_char) != input.end()) return(false);
	if(input.length() < 3) return(false);
	// TODO: operators not right next to each other
	// if operator is first, must be - of num
	return(true);
}

// form substring from input starting at pos and looking for pattern
// modifies, pos to position at end of substring
string formSubstring(string input, char* pattern, size_t* pos)
{
	// find operator
	size_t begin = input.find_first_not_of(space, *pos);
	size_t end = input.find_first_not_of(pattern, begin+1);		// move past - sign 
	string tmp = input.substr(begin, (end-begin));
	cout << "begin: " << begin << "   end: " << end << "   substring: " << tmp <<  '\n';
	*pos = end;
	return(tmp);
}

//TODO: check for overflow
int parseInput(string input)
{
	size_t pos = 0;
	string tmp = "";

	// get first number
	tmp = formSubstring(input, number, &pos);
	if(tmp.length() < 1) {
		errorMessage("no first number present", ERROR);
		return(-1);
	}
	int num1 = atoi(tmp.c_str());

	// get operator
	tmp = formSubstring(input, op, &pos);
	if(tmp.length() > 1) {		// should only be one operator
		errorMessage("more than one operator found", ERROR);
		return(-1);
	}
	string operation = tmp;

	// get second number
	tmp = formSubstring(input, number, &pos);
	int num2 = atoi(tmp.c_str());

	// first non-number from that point
	int t = performOperation(num1, num2, operation);
	return(t);
}


int performOperation(int num1, int num2, string operation)
{
	if(operation == "-")
		return(num1 - num2);
	else if(operation == "+")
		return(num1 + num2);
	else if(operation == "/")
		return(num1/num2);
	else if(operation == "*")
		return(num1 * num2);
	else {
		cout << "error in operation selection" << '\n';
		assert(0); 		// could throw exception here
	}
}


// return false if c is not a valid character
bool bad_char(char c)
{
	for(int i = 0; i < NUMVALIDCHARS; i++) {
		if(valid_characters[i] == c) 
			return(false);
	}
	return(true);
}

void introMessage()
{
	cout << "Welcome to Calculator" << '\n';
	errorMessage("", !ERROR);	
}

// print error message
void errorMessage(string msg, bool isError)
{
	// parsing, if input is not in form "### (operator) ###" will print help screens
	if(isError) {
		cout << "error: " << msg << "\n\n";
	}
	cout << "calculator use:\n"
		 << "- format must be '### (operator) ###'\n" 
		 << "- valid operators:\n"
		 << "	- multiplicaiton \t'*'\n"
		 << "	- division \t\t'/'\n"
		 << "	- addition \t\t'+'\n"
		 << "	- subtraction \t\t'-'\n"
		 << "- max length = 100 characters\n\n";
}