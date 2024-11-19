// реализация функций и классов для вычисления арифметических выражений
//#include "arithmetic.h"
//#include "stack.h"
//
//void Arithmetic::Parse() {
//    int prevType = GetType(infix[0]);
//    int kol = 0, index = 1;
//    string token(1, infix[0]);
//    for (int i = 1; i <= infix.length(); i++)
//    {
//        if (prevType != -1)
//            break;
//        prevType = GetType(infix[i]);
//        index = i + 1; kol = i;
//        token = (1, infix[i]);
//    }
//    while (index <= infix.length())
//    {
//        int x = GetType(infix[index]);
//        if (((x != -1) && (prevType != x)) || ((prevType == 3) && (x == 3)))
//        {
//            input.push_back(Lexema(token, prevType));
//            token = string(1, infix[index]);
//            kol++;
//        }
//        else {
//            if (x != -1)
//                token += infix[index];
//        }
//        prevType = x; index++;
//    }
//    if (!token.empty()) {
//        input.push_back(Lexema(token, prevType));
//    }
//}
//
//void Arithmetic::ParsePostfix() {
//    int prevType = GetType(postfix[0]);
//    int index = 1;
//    string token(1, postfix[0]);
//    while (index < postfix.length())
//    {
//        int x = GetType(postfix[index]);
//        int flag = 0;
//        for (const auto& element : operands) {
//            if (element.first == token)
//                flag = 1;
//        }
//        if ((prevType != x) || ((prevType == 3) && (x == 3)) || (flag == 1))
//        {
//            Vpostfix.push_back(Lexema(token, prevType));
//            token = string(1, postfix[index]);
//        }
//        else {
//            token += postfix[index];
//        }
//        prevType = x; index++;
//    }
//    if (!token.empty()) {
//        Vpostfix.push_back(Lexema(token, prevType));
//    }
//}
//
//void Arithmetic::ToPostfix() {
//    TVectorStack<Lexema> st;
//    Lexema stackItem;
//    for (int i = 0; i < input.size(); i++)
//    {
//        string item = input[i].GetStr();
//        if (GetType(item[0]) == 3)
//            switch (item[0])
//            {
//            case '(':
//                st.Push(input[i]);
//                break;
//            case ')':
//                stackItem = st.Pop();
//                while (stackItem.GetStr() != "(")
//                {
//                    postfix += stackItem.GetStr();
//                    stackItem = st.Pop();
//                }
//                break;
//            case '+':case '-':case '*':case '/':
//                while (!st.IsEmpty())
//                {
//                    stackItem = st.Pop();
//                    if (priority[item[0]] <= priority[stackItem.GetStr()[0]])
//                        postfix += stackItem.GetStr();
//                    else {
//                        st.Push(stackItem);
//                        break;
//                    }
//                }
//                st.Push(input[i]);
//                break;
//            }
//        else {
//            operands.insert({ item,0.0 });
//            postfix += item;
//        }
//    }
//    while (!st.IsEmpty())
//    {
//        stackItem = st.Pop();
//        postfix += stackItem.GetStr();
//    }
//}
//
//Arithmetic::Arithmetic(string str) : infix(str) // конструктор
//{
//    priority = { {'+',1}, {'-',1}, {'*',2}, {'/',2} , {'(',0} };
//    Parse();
//    Check();
//    ToPostfix();
//    ParsePostfix();
//}
//
//void Arithmetic::Check() {
//    Lexema past = input[0];
//    int index = 1, br = 0;
//    if (past.GetStr() == "(")
//        br++;
//    else {
//        if (past.GetT() == 3)
//            throw "operation cant be first";
//    }
//    while (index < input.size())
//    {
//        Lexema item = input[index];
//        if (item.GetStr() == "(")
//            br++;
//        if (item.GetStr() == ")")
//            br--;
//        if ((past.GetT() == 2) && (item.GetT() == 1) || (past.GetT() == 1) && (item.GetT() == 2))
//            throw "no operation between operands";
//        past = input[index];
//        index++;
//    }
//    if (br != 0)
//        throw "issues with brackets";
//}
//
//vector <Lexema> Arithmetic::GetInfixLexems() const // получаем vector <Lexema> input
//{
//    return input;
//}
//
//vector <Lexema> Arithmetic::GetPostfixLexems() const // получаем vector <Lexema> Vpostfix
//{
//    return Vpostfix;
//}
//
//string Arithmetic::GetInfix() const // получаем string infix
//{
//    return infix;
//}
//
//string Arithmetic::GetPostfix() const // получаем string postfix
//{
//    return postfix;
//}
//
//void Arithmetic::PrintInfixLexems() {
//    cout << "|";
//    for (int i = 0; i < input.size(); i++) {
//        cout << input[i].GetStr() << "|";
//    }
//    cout << endl;
//}
//
//void Arithmetic::PrintPostfixLexems() {
//    cout << "|";
//    for (int i = 0; i < Vpostfix.size(); i++) {
//        cout << Vpostfix[i].GetStr() << "|";
//    }
//    cout << endl;
//}
//
//double Arithmetic::Calculate(const map<string, double>& values) // по постфиксной записи вычисляем выражение
//{
//    for (auto& val : values)
//    {
//        try
//        {
//            operands.at(val.first) = val.second;
//        }
//        catch (out_of_range& e) {}
//    }
//    TVectorStack<double> st;
//    		double left, right;
//    		for (Lexema l : Vpostfix)
//    		{
//    			string element = l.GetStr();
//    			if (GetType(element) == 3)
//    				switch (element[0])
//    				{
//    				case '+':
//    					right = st.Pop();
//    					left = st.Pop();
//    					st.Push(left + right);
//    					break;
//    				case '-':
//    					right = st.Pop();
//    					left = st.Pop();
//    					st.Push(left - right);
//    					break;
//    				case '*':
//    					right = st.Pop();
//    					left = st.Pop();
//    					st.Push(left * right);
//    					break;
//    				case '/':
//    					right = st.Pop();
//    					left = st.Pop();
//    					st.Push(left / right);
//    					break;
//    				}
//    			else
//    			{
//    				st.Push(operands[element]);
//    			}
//    		}
//    		return st.Pop();
//}
//vector <string> Arithmetic::GetOperands()
//	{
//		vector <string> op;
//		for (const auto& element : operands) {
//			op.push_back(element.first);
//		}
//		return op;
//	}