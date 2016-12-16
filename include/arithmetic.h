#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

#include "stack.h"
#include <iostream>
#include <cstring>

using namespace std;

class Check
{
public:
	char *s;
	int len;

	Check(char* s); 
	bool CheckBrackets();
	bool CheckOperands();
	int Prioritet(char s);
	char* ChangeExpression(char *res);
	bool IsOperation(char s);
	void UnarMinus(char *res);
	bool IsUnarMinus();
	double Calculation ();
	double GetNumber();
	~Check();
	void Input(char *res);
	void FindVars(int *res);
	bool AreVars();
};
#endif