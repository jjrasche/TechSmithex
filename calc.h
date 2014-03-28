#ifndef CALC_H
#define CALC_H

#include <string>
using namespace std;

#define MAXINPUTLENGTH 100
#define NUMVALIDCHARS  17
#define ERROR true

void errorMessage(string, bool);
void introMessage();
int parseInput(string);
int parseSegment(string, string, const char*, size_t);
bool bad_char(char);
bool isCorrectFormat(string);
int performOperation(int ,int ,string);

#endif