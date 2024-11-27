//реализация функций и классов для вычисления арифметических выражений
#include "../include/arithmetic.h"

bool SurchChar(char arr[], char ch, int size) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == ch) {
			return 1; // Символ найден
		}
	}
	return 0; // Символ не найден
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


Arithmetic::Arithmetic(string str) : infix(str) // конструктор
{
	priority = { {'+',1}, {'-',1}, {'*',2}, {'/',2} , {'(',0} };
	CheckCharacters();
	Parse();
	Check();
	ToPostfix();
}
void Arithmetic::Parse() {
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
				if (infix[index] == '.')
					token += ',';
				else
					token += infix[index];
		}
		prevType = x; index++;
	}
	if (!token.empty()) {
		input.push_back(Lexema(token, prevType));
	}
	}
void Arithmetic::ToPostfix() {
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
					Vpostfix.push_back(stackItem);
					stackItem = st.Pop();
				}
				break;
			case '+':case '-':case '*':case '/':
				while (!st.IsEmpty())
				{
					stackItem = st.Pop();
					if (priority[item[0]] <= priority[stackItem.GetStr()[0]])
					{
						postfix += stackItem.GetStr();
						Vpostfix.push_back(stackItem);
					}
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
			Vpostfix.push_back(Lexema(item, 1));
		}
	}
	while (!st.IsEmpty())
	{
		stackItem = st.Pop();
		postfix += stackItem.GetStr();
		Vpostfix.push_back(stackItem);
	}
}
void Arithmetic::CheckCharacters() const {
	if (infix.length() < 2)
		throw "too short input";
	for (int i = 0; i < infix.length(); i++)
	{
		if ((GetType(infix[i]) == -1) && (infix[i] != ' '))
			throw "invalid character";
	}
}
void Arithmetic::Check() const {
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
vector <Lexema> Arithmetic::GetInfixLexems() const//(получаем vector <Lexema> input)
{
	return input;
}
vector <Lexema> Arithmetic::GetPostfixLexems() const//(получаем vector <Lexema> Vpostfix)
{
	return Vpostfix;
}
string Arithmetic::GetInfix() const//(получаем string infix)
{
	return infix;
}
string Arithmetic::GetPostfix() const//(получаем string postfix)
{
	return postfix;
}
void Arithmetic::PrintInfixLexems()
{
	cout << "|";
	for (int i = 0; i < input.size(); i++) {
		cout << input[i].GetStr() << "|";
	}
	cout << endl;
}
void Arithmetic::PrintPostfixLexems()
{
	cout << "|";
	for (int i = 0; i < Vpostfix.size(); i++) {
		cout << Vpostfix[i].GetStr() << "|";
	}
	cout << endl;
}
double Arithmetic::Calculate(const map <string, double>& values) //по постфиксной записи вычисляем выражение
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
vector <string> Arithmetic::GetOperands()
{
	vector <string> op;
	for (const auto& element : operands) {
		op.push_back(element.first);
	}
	return op;
}
