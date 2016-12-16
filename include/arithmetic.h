#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

const int MAX_NUMBER_VARIABLES = 30;

class TArithmetic
{
protected:
	string aStr;									//�������� ���������
	string aTok;									//������ ������
	double aVariables[MAX_NUMBER_VARIABLES];		//�������� ����������
	char nameVariables[MAX_NUMBER_VARIABLES];		//����� ����������
	double aResult;									//���������
	TStack<char> aStack;							//���� �������������� ������
public:
	TArithmetic(string aStr = " ");
	~TArithmetic();
	void ReadStr() {getline(cin, aStr);};			//���������� ������
	void SplitIntoTokens();							//��������� �� �������
	string GetTokens() {return aTok;}				//������� ������ ������
	void SetString(string str) {aStr = str;}
	void SetTokens(string str) {aTok = str;}
};

TArithmetic::TArithmetic(string str)
{
	aStr = str;
}

TArithmetic::~TArithmetic()
{}

void TArithmetic::SplitIntoTokens()
{
	string temp;
	int i = 0;	
	while (i < aStr.length())
	{
		if (((char)aStr[i]>=48)&&((char)aStr[i]<=57))
			{
				while ((i < aStr.length())&&((char)aStr[i]>=48)&&((char)aStr[i]<=57))
				{
					temp = temp + aStr[i];
					i++;
				}
				i--;
				temp = temp + " ";
			}
		else
			if (((char)aStr[i]>=97)&&((char)aStr[i]<=122))
			{
				temp = temp + aStr[i] + " ";
			}
			else
		switch (aStr[i])
		{
		case (char)40:									// (
		{
			temp = temp + aStr[i] + " ";
			break;
		}
		case (char)41:									// )
		{
			temp = temp + aStr[i] + " ";
			break;
		}
		case (char)42:									// * 
		{
			temp = temp + aStr[i] + " ";
			break;
		}
		case (char)43:									// + 
		{
			temp = temp + aStr[i] + " ";
			break;
		}
		case (char)45:									// - 
		{
			temp = temp + aStr[i] + " ";
			break;
		}
		case (char)47:									// / 
		{
			temp = temp + aStr[i] + " ";
			break;
		}
		default:
			break;
		} 
		i++;
	}
	aTok = temp;
}
