#include "arithmetic.h"



bool Check(char *s) { //�������� ������

	TStack<char> St;
	int i=0;
	while (s[i] != '\0'){
		if (s[i] =='(')
			St.push('(');
		if (s[i] == ')')
		{
			if (St.isEmpty())
				return false;
			else 
				St.put();
		}
		i++;
	}

	return (St.isEmpty());
}
int DType(char s) //1-�����; 2-����� 3-����� ��������;
{
	char operand[]="+-*/";
	int flag=0;

	if (isdigit(s))
		return 1;
	else if (isalpha(s))
		return 2;
	else 
	{
		for(int i=0;i<4;i++)
			if (s==operand[i])
			{
				flag=1;
				break;
			}
			if(flag==1)
				return 3;
			else 
			{
				cout << "throw" <<endl;
				return 0;
			}
	}
}
int prior (char a){ //��������� ��������
	switch(a){
	case '=' : return(1);
	case ')' : return(0);
	case '-' :
	case '+' : return(2);
	case '*' :
	case '/' : return(3);
	}
}
bool CheckOperands(char* s)// �������� �� ���������� ���������
{
	char operat[]="-+*/";
	int flag=0;
	for (int i=1;i<4;i++)
	{
		if (s[0]==operat[i])
		{
			cout<< "���� ���������" << endl;
			flag=1;
			break;

		}
	}
	for (int i=0;i<4;i++)
	{
		if (s[strlen(s)-1]==operat[i])
		{
			cout<< "���� ���������" << endl;
			flag=1;
			break;
		}
	}
	if (flag==1)
		return false;
	else
		return true;
}
bool CheckOper(char *s)//�������� �� ���������� �������� ������
{
	char operat[]="-+*/";
	int flag=0;
	for (int i=0;i<strlen(s);i++)
	{
		for(int j=0;j<4;j++)
			if (s[i]==operat[j])
			{
				for(int j=0;j<4;j++)
					if (s[i+1]==operat[j])
					{
						cout<< "��� ����� �������� ������"<< endl;
						flag=1;
						break;
					}
					if (flag==1)
						break;
			}
			if (flag==1)
				break;
	}
	if (flag==1)
		return false;
	else
		return true;
}


