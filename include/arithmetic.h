// ���������� ������� � ������� ��� ���������� �������������� ���������
#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__
#include <iostream>
#include <string>
using namespace std;

class Tlexeme
{ protected:
	int Size;
	string* mLexeme; //������ ����� ������� �� �������
	int* priority; //��������� ������
	int Flag = 0; // ������� ������
    public:
	//������������ � �����������
	Tlexeme(string a);
	~Tlexeme();
	//��������
	bool Split(); //�������� ������� �� ������ �� �������
	void Divide(); //������� �� �������
	void Check_correct(); //�������� �� ������������ �������� ������
	void Pol(); //���������� �������� ������
	private:
	int Check_brack();//�������� ������
	int  Check_sign(); //�������� ������ ��������
	int  Check_point(); //�������� ����� � ������� ������
	int  Check_variable();//�������� ����������
	int  Check_function();//�������� �������
	
	
};




/*
// ������� � �������� ������
string POL(string s)
{
	int i;
	string a;
	for (int i = 0; i < a.length(); i++)
	{ switch (a[i])
	  { case '+-':
			   break;
		case '(':
			   break;
		case ')':
			break;
		case '0123456789':
			break;
		}
	}
	return a;
}

//�������� �� ������������
bool RIG(string s)
{ string a=s;
  bool flag = 1;
  TStack <char> S1; //������
  TStack <char> S2; //����� ���������
  TStack <char> S3; //�����
  TStack <char> S4; //�����
  for (int i = 0; i < a.length(); i++) //while
  {
	  switch (a[i])
	  {
	  case '(': S1.Push('('); break;
	  case ')': if (S1.Empty()) { flag = 0; cout << "Bracket error in place � " << i << endl; }
			  else { S1.Pop(); S2.Clear(); S3.Clear(); S4.Clear(); } break;
	  case '+' || '*' || '/': if (S4.Empty()) { flag = 0; cout << "Sign error in place � " << i << endl; }
							else { S2.Push(a[i]); } break;
	  case '-':  S2.Push(a[i]); break;
	  case '.':  S2.Push(a[i]); break;

	  }
  }

}
*/

/*
//������� �� �������
string Lec(string s)
{ int n = s.length();
  string* s;


	for (int i = 0; i < a.length(); i++)
	{
		switch (a[i])
		{
		case '+-':
			break;
		case '(':
			break;
		case ')':
			break;
		case '0123456789':
			break;
		}
	}
	return a;
} */
#endif