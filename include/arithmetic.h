// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#pragma once
#ifndef _Arifm_H_
#define _Arifm_H_

#include <stack.h>
#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;
bool SurchChar(char arr[], char ch, int size) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == ch) {
			return 1; // —имвол найден
		}
	}
	return 0; // —имвол не найден
}
//Type: -1 - space, 1 - variable, 2 - number, 3 - operation
char signs[] = { '(',')','+','-','*','/' };
int GetType(char c) {
	if (isalpha(c)) return 1;
	else if ((isdigit(c)) || (c == '.') || (c == ',')) return 2;
	else if (SurchChar(signs, c, 6)) return 3;
	else return -1;
}
int GetType(string c) {
	if (isalpha(c[0])) return 1;
	else if ((isdigit(c[0]))) return 2;
	else if (SurchChar(signs, c[0], 6)) return 3;
	else return -1;
}
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
	void Parse() {
		int prevType = GetType(infix[0]);
		int kol = 0, index = 1;
		string token(1, infix[0]);
		for (int i = 1; i <= infix.length(); i++)
		{
			if (prevType != -1)
				break;
			prevType = GetType(infix[i]);
			index = i + 1; kol = i;
			token = (1, infix[i]);
		}
		while (index < infix.length())
		{
			int x = GetType(infix[index]);
			if (((x != -1) && (prevType != x)) || ((prevType == 3) && (x == 3)))
			{
				input.push_back(Lexema(token, prevType));
				token = string(1, infix[index]);
				kol++;
			}
			else {
				if (x != -1)
					token += infix[index];
			}
			prevType = x; index++;
		}
		if (!token.empty()) {
			input.push_back(Lexema(token, prevType));
		}
	}
	void ParsePostfix() {
		int prevType = GetType(postfix[0]);
		int index = 1;
		string token(1, postfix[0]);
		while (index < postfix.length())
		{
			int x = GetType(postfix[index]);
			int flag = 0;
			for (const auto& element : operands) {
				if (element.first == token)
					flag = 1;
			}
			if ((prevType != x) || ((prevType == 3) && (x == 3)) || (flag == 1))
			{
				Vpostfix.push_back(Lexema(token, prevType));
				token = string(1, postfix[index]);
			}
			else {
				token += postfix[index];
			}
			prevType = x; index++;
		}
		if (!token.empty()) {
			Vpostfix.push_back(Lexema(token, prevType));
		}
	}
	void ToPostfix() {
		TVectorStack<Lexema> st;
		Lexema stackItem;
		for (int i = 0; i < input.size(); i++)
		{
			string item = input[i].GetStr();
			if (GetType(item[0]) == 3)
				switch (item[0])
				{
				case '(':
					st.Push(input[i]);
					break;
				case ')':
					stackItem = st.Pop();
					while (stackItem.GetStr() != "(")
					{
						postfix += stackItem.GetStr();
						stackItem = st.Pop();
					}
					break;
				case '+':case '-':case '*':case '/':
					while (!st.IsEmpty())
					{
						stackItem = st.Pop();
						if (priority[item[0]] <= priority[stackItem.GetStr()[0]])
							postfix += stackItem.GetStr();
						else {
							st.Push(stackItem);
							break;
						}
					}
					st.Push(input[i]);
					break;
				}
			else {
				operands.insert({ item,0.0 });
				postfix += item;
			}
		}
		while (!st.IsEmpty())
		{
			stackItem = st.Pop();
			postfix += stackItem.GetStr();
		}
	}
public:
	Arithmetic(string str) : infix(str)//конструктор
	{
		priority = { {'+',1}, {'-',1}, {'*',2}, {'/',2} , {'(',0} };
		CheckCharacters();
		Parse();
		Check();
		ToPostfix();
		ParsePostfix();
	}
	void CheckCharacters() const{
		if (infix.length() < 2)
			throw "too short input";
		for (int i = 0; i < infix.length(); i++)
		{
			if ((GetType(infix[i])==-1) && (infix[i]!=' '))
				throw "invalid character";
		}
	}
	void Check() const{
		Lexema past = input[0];
		int index = 1, br = 0;
		if (past.GetStr() == "(")
			br++;
		else {
			if (past.GetT() == 3)
				throw "operation cant be first";
		}
		while (index < input.size())
		{
			Lexema item = input[index];
			if (item.GetStr() == "(")
				br++;
			if (item.GetStr() == ")")
				br--;
			if ((past.GetT() == 2) && (item.GetT() == 1) || (past.GetT() == 1) && (item.GetT() == 2))
				throw "no operation between operands";
			if ((past.GetT() == 3) && (item.GetT() == 3))
				if ((item.GetStr() != "(") && (past.GetStr() != ")") && ((past.GetStr() != "(") && (item.GetStr() != ")")))
				throw "no  operand between operations";
			if ((past.GetStr() == "(") && (item.GetStr() == ")"))
				throw "empty brackets";
			past = input[index];
			index++;
		}
		if (br != 0)
			throw "issues with brackets";
	}
	vector <Lexema> GetInfixLexems() const//(получаем vector <Lexema> input)
	{
		return input;
	}
	vector <Lexema> GetPostfixLexems() const//(получаем vector <Lexema> Vpostfix)
	{
		return Vpostfix;
	}
	string GetInfix() const//(получаем string infix)
	{
		return infix;
	}
	string GetPostfix() const//(получаем string postfix)
	{
		return postfix;
	}
	void PrintInfixLexems() 
	{
		cout << "|";
		for (int i = 0; i < input.size(); i++) {
			cout << input[i].GetStr() << "|";
		}
		cout << endl;
	}
	void PrintPostfixLexems()
	{
		cout << "|";
		for (int i = 0; i < Vpostfix.size(); i++) {
			cout << Vpostfix[i].GetStr() << "|";
		}
		cout << endl;
	}
	double Calculate(const map <string, double>& values) //по постфиксной записи вычисл€ем выражение
	{
		for (auto& val : values)
		{
			try
			{
				operands.at(val.first) = val.second;
			}
			catch (out_of_range& e) {}
		}
		TVectorStack<double> st;
		double left, right;
		for (Lexema l : Vpostfix)
		{
			string element = l.GetStr();
			if (GetType(element) == 3)
				switch (element[0])
				{
				case '+':
					right = st.Pop();
					left = st.Pop();
					st.Push(left + right);
					break;
				case '-':
					right = st.Pop();
					left = st.Pop();
					st.Push(left - right);
					break;
				case '*':
					right = st.Pop();
					left = st.Pop();
					st.Push(left * right);
					break;
				case '/':
					right = st.Pop();
					left = st.Pop();
					if (right == 0.0)
						throw "division by 0 is not possible";
					st.Push(left / right);
					break;
				}
			else
			{
				st.Push(operands[element]);
			}
		}
		return st.Pop();
	}
	vector <string> GetOperands()
	{
		vector <string> op;
		for (const auto& element : operands) {
			op.push_back(element.first);
		}
		return op;
	}
};
//class Arithmetic {
//	string infix;
//	string postfix;
//	vector <Lexema> input;
//	vector <Lexema> Vpostfix;
//	map <char, int> priority;
//	map <string, double> operands;
//	void Parse();
//	void ParsePostfix();
//	void ToPostfix();
//public:
//	Arithmetic(string str); // конструктор
//  void CheckCharacters() const;
//	void Check() const;
//	vector <Lexema> GetInfixLexems() const;
//	vector <Lexema> GetPostfixLexems() const;
//	string GetInfix() const;
//	string GetPostfix() const;
//	void PrintInfixLexems();
//	void PrintPostfixLexems();
//	double Calculate(const map <string, double>& values);
//	vector <string> GetOperands();
//};
#endif