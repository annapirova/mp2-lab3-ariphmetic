#include "stack.h"
#include "arithmetic.h"
#include "parser.h"

#include <locale>
#include <iostream>
using namespace std;



void main()
{
	setlocale(LC_CTYPE, "Russian");

	char a[MaxSize];
	cout << "������� ���������:";
	gets(a);
	InPoint(a);
	cout<<endl;

	if(!CheckAll(a))
		cout << "������������ ���������!" <<endl;
	else
	{
		TParser x(a);
		x.Convert();
		double res=x.calc();
		cout<<"Result="<<res<<endl;
	}

}
