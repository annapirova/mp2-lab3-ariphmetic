#include "stack.h"
#include "arithmetic.h"

const int MaxSize=256;


class TParser
{
private:
	char inf[MaxSize];
	char postf[MaxSize];
	TStack<char> St_c;
	TStack<double> St_d;

public:
	TParser (char * c);
	char GetPostf(int i) {return (postf[i]);}
	bool IsNumber(char a);
	bool IsOper(char a);
	double calc ();
	void Convert();

};

TParser::TParser (char * c) {
	int i=0;
	while (c[i]!='\0')
	{
		inf[i]=c[i];
		i++;
	}
	inf[i]='\0';
}
bool TParser:: IsNumber(char a){
	if (isdigit(a))
		return true;
	else
		return false;
}
bool TParser:: IsOper(char s){
	char operand[]="+-/*";
	int flag=0;
	for(int i=0;i<4;i++)
		if (s==operand[i])
		{
			flag=1;
			break;
		}
		if(flag==1)
			return true;
		else 
			return false;		
}
void TParser::Convert()
{   // i - ������� inf[], j - ������� postf[]
	int j = 0;
	int i=0;
	St_c.push('=');
	for(int i = 0; inf[i] != '\0'; ++i) // ���� �� ����� ������ ������������ ��������� ������

	{
		if( inf[i] == '(' ) // ���� ����������� ������, ��������� � ����
			St_c.push('(');

		if ( IsNumber(inf[i]) )
		{
			if ((DType(inf[i+1])==1)||(DType(inf[i+1])==4))
			{
				postf[j]=inf[i];
				j++;
			}
			else
			{
				postf[j]=inf[i];
				j++;
				postf[j]=' ';
				j++;
			}
		}
		if (DType(inf[i])==4)
		{
			postf[j]=inf[i];
			j++;
		}

		if( IsOper(inf[i]) ) // ���� ��������
		{
			char temp = St_c.put();
			while( prior(inf[i]) <= prior(temp) ) // ���� ��������� inf[i] < �������� �� ������� �����
			{
				postf[j++] = temp;// ��������� �������� �� ����� � ����������� ������
				temp = St_c.put();					
			}
			St_c.push(temp);
			St_c.push(inf[i]); // ��������� �������� � ����
		}

		if( inf[i] == ')' )
		{
			char temp = St_c.put();
			while(temp != '(')
			{
				postf[j++] = temp;
				temp = St_c.put();
			}
		}

	}
	while( !(St_c.isEmpty()))
		postf[j++] = St_c.put();
	postf[j] = '\0';
	//for(j=0;j<15;j++)
	//	cout<<postf[j];
}
double TParser:: calc () { //������ ��� � inf[]
	int i=0;
	int z=0;
	int l=0;
	while (postf[i]!='\0') 
	{
		if (DType(postf[i])==1){
			int k=0;
			char s[MaxSize];
			double number;	
			z=i;
			while(postf[z]!=' ')
			{
				s[k]=postf[z];
				z++;
				k++;
			}
			s[k]='\0';
			l=z-i+1;
			number=atof(s);
			St_d.push(number);
			i=i+l-1;	
		}

		if (IsOper(postf[i]))
		{
			double R,op1,op2;
			op2=St_d.put();
			op1=St_d.put();
			switch (postf[i])
			{
			case '+':
				R=op1+op2;
				break;
			case '-':
				R=op1-op2;
				break;
			case '*':
				R=op1*op2;
				break;
			case '/':
				R=op1/op2;
				break;
			}			
			St_d.push(R);	
		}
		i++;
	}
	return (St_d.put());
}
