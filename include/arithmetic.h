// объявление функций и классов для вычисления арифметических выражений
#pragma once
#include "stack.h"
#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

bool SurchChar(char arr[], char ch, int size);
int GetType(char c);
int GetType(string c);

class Lexema {
	string str;
	int type;
public:
	Lexema() : str(""), type(0) {}
	Lexema(string s, int t) {
		str = s;
		type = GetType(str);
	}
	string GetStr() const { return str; }
	int GetT() const { return type; }
	void SetStr(string name) { str = name; }
	void SetType(int i) { type = i; }
	void PrintStr() const {
		cout << str;
	}
	bool operator ==(const Lexema& v) const
	{
		if ((str == v.str) && (type == v.type))
			return true;
		else return false;
	}
};

class Arithmetic {
	string infix;
	string postfix;
	vector <Lexema> input;
	vector <Lexema> Vpostfix;
	map <char, int> priority;
	map <string, double> operands;
	void Parse();
	void ToPostfix();
public:
	Arithmetic(string str); 
  void CheckCharacters() const;
	void Check() const;
	vector <Lexema> GetInfixLexems() const;
	vector <Lexema> GetPostfixLexems() const;
	string GetInfix() const;
	string GetPostfix() const;
	void PrintInfixLexems();
	void PrintPostfixLexems();
	double Calculate(const map <string, double>& values);
	vector <string> GetOperands();
};
