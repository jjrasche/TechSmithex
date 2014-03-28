/*
had a bunch of trouble trying to use the regex libraries
	In file included from /usr/include/c++/4.6/regex:35:0,  from main.cpp:6:
		/usr/include/c++/4.6/bits/c++0x_warning.h:32:2: error: #error This file requires 
		compiler and library support for the upcoming ISO C++ standard, C++0x. 
		This support is currently experimental, and must be enabled with the -std=c++0x or -std=gnu++0x compiler options

gdb was not setting breakpoints
	Reading symbols from /home/jjrasche/TechSmith_exercise/calc...(no debugging symbols found)...done.
	(gdb) b 49 		--> No symbol table is loaded.  Use the "file" command.

	Solution: set compiler CPPFLAGS instead of CFLAGS

problem find_first_of is returning string::npos (32-bit -1)  and string::npos on this machine is (64-bit -1) 
	Could be b/c i'm using a VM

cin does not take spaces as input
	reason: cin does takes in input seperately based on spacing 
	solution: cin.getline(string, # characters);
	solution: do not check for spacing


*/


#include <iostream>
#include <string>
#include "calc.h"
using namespace std;



// main will run a loop that takes commands from terminal
// performs calcuation and returns result
// 'q' = quit, 
int main() 
{
	string input = "";
	introMessage();
	while(input != "q") {
		getline(cin,input);
		cout << input << '\n';
		if(!isCorrectFormat(input)) {
			errorMessage("incorrect format", ERROR);
			continue;
		}
		 cout << input << " = " << parseInput(input) << '\n';
	}

	return(0);
}
