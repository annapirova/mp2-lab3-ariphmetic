// тесты для вычисления арифметических выражений

#include <gtest.h>
#include <arithmetic.h>

TEST(Arithmetic, no_throws_with_correct_input)
{
	ASSERT_NO_THROW(Arithmetic a1("2.0+s"));
}
TEST(Arithmetic, throws_when_string_have_invalid_characters)
{
	ASSERT_ANY_THROW(Arithmetic a1("2.0+@"));
}
TEST(Arithmetic, throws_when_string_too_short)
{
	ASSERT_ANY_THROW(Arithmetic a1("s"));
}
TEST(Arithmetic, throws_when_issues_with_brackets)
{
	ASSERT_ANY_THROW(Arithmetic a1("2.0 + d * ((s/2.0)"));
}
TEST(Arithmetic, throws_when_empty_brackets)
{
	ASSERT_ANY_THROW(Arithmetic a1("() - f"));
}
TEST(Arithmetic, throws_when_issues_with_operations)
{
	ASSERT_ANY_THROW(Arithmetic a1("2.0 + + d"));
}
TEST(Arithmetic, throws_when_issues_with_operands)
{
	ASSERT_ANY_THROW(Arithmetic a1("2.0 + 7.0 d"));
}
TEST(Arithmetic, throws_when_start_with_operation)
{
	ASSERT_ANY_THROW(Arithmetic a1("+2.0 - d"));
}
TEST(Arithmetic, can_get_infix)
{
	Arithmetic a1("2.0+s");
	EXPECT_EQ("2.0+s", a1.GetInfix());
}
TEST(Arithmetic, can_parse_infix_without_spaces)
{
	Arithmetic a1("2.0+val/2.0");
	vector <Lexema> vec;
	vec.push_back(Lexema("2.0", 2));
	vec.push_back(Lexema("+", 3));
	vec.push_back(Lexema("val", 1));
	vec.push_back(Lexema("/", 3));
	vec.push_back(Lexema("2.0", 2));
	EXPECT_EQ(vec,a1.GetInfixLexems());
}
TEST(Arithmetic, can_parse_infix_with_spaces)
{
	Arithmetic a1(" 2.0 + val / 2.0 ");
	vector <Lexema> vec;
	vec.push_back(Lexema("2.0", 2));
	vec.push_back(Lexema("+", 3));
	vec.push_back(Lexema("val", 1));
	vec.push_back(Lexema("/", 3));
	vec.push_back(Lexema("2.0", 2));
	EXPECT_EQ(vec, a1.GetInfixLexems());
}
TEST(Arithmetic, can_go_to_postfix)
{
	Arithmetic a1("2.0+val/2.0");
	EXPECT_EQ("2.0val2.0/+", a1.GetPostfix());
}
TEST(Arithmetic, can_parse_postfix)
{
	Arithmetic a1(" 2.0 + val / l ");
	vector <Lexema> vec;
	vec.push_back(Lexema("2.0", 2));
	vec.push_back(Lexema("val", 1));
	vec.push_back(Lexema("l", 1));
	vec.push_back(Lexema("/", 3));
	vec.push_back(Lexema("+", 3));
	EXPECT_EQ(vec, a1.GetPostfixLexems());
}
TEST(Arithmetic, can_get_operands)
{
	Arithmetic a1(" 2.2 + a *( ls - d/2.0) ");
	vector<string> operands;
	operands.push_back("2.0");
	operands.push_back("2.2");
	operands.push_back("a");
	operands.push_back("d");
	operands.push_back("ls");
	EXPECT_EQ(operands, a1.GetOperands());
}
TEST(Arithmetic, can_calculate_value)
{
	Arithmetic a1(" 2.2 + a *( ls - d/2.0) ");
	vector<string> operands = a1.GetOperands();
	map<string, double> values;
	values[operands[0]] = 2.0; //2.0
	values[operands[1]] = 2.2; //2.2
	values[operands[2]] = 3.3; //a
	values[operands[3]] = 6.6; //d
	values[operands[4]] = 9.3; //ls
	EXPECT_EQ(22.0,a1.Calculate(values));
}