// реализация пользовательского приложения
#include "stack.h"
#include "arithmetic.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    //setlocale(LC_NUMERIC, "eng");
    std::cout << std::stod("3,14") << std::endl;
    std::cout < <std::stod("3.14") << std::endl;
    std::cout << "enter expression : ";
    string in;
    getline(cin, in);
    std::cout << std::endl;
    Arithmetic expr(in);
    std::cout << expr.GetInfix() << std::endl;
    cout << endl;
    std::cout << expr.GetPostfix() << std::endl;
    expr.PrintPostfixLexems();
    vector<string> operands = expr.GetOperands();
    double val;
    map<string, double> values;
    for (const auto& op : operands) {
        if (GetType(op) == 2)
            values[op] = std::stod(op);
        else {
            std::cout << "enter value of " << op << ": ";
            std::cin >> val;
            values[op] = val;
        }
    }
    cout << "result: " << expr.Calculate(values) << endl;
    return 0;
}
