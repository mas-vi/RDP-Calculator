#pragma once
inline std::string expression{};
inline int cursor{};
inline bool valid_expr{ true };

double parseFormula();
double parseFactor();
double parseNumber();
double parseFirstDegree();
double parseSecondDegree();
double parseThirdDegree();
void ignoreWhiteSpaces();
void print();


double parseFormula()
{
	valid_expr = true;
	return parseFirstDegree();
}

double parseFirstDegree()
{

	double fact1 = parseSecondDegree();
	ignoreWhiteSpaces();
	while (expression[cursor] == '+' || expression[cursor] == '-')
	{
		char operat = expression[cursor];
		++cursor;
		double fact2 = parseSecondDegree();
		fact1 += (operat == '+' ? +fact2 : -fact2);

	}

	return fact1;
}

double parseSecondDegree()
{

	double fact1 = parseThirdDegree();
	ignoreWhiteSpaces();
	while (expression[cursor] == '*' || expression[cursor] == '/')
	{
		char operat = expression[cursor];
		++cursor;
		double fact2 = parseThirdDegree();
		fact1 *= (operat == '*' ? fact2 : 1 / fact2);

	}
	return fact1;
}

double parseThirdDegree()
{
	double fact1 = parseFactor();
	ignoreWhiteSpaces();
	while (expression[cursor] == '^')
	{
		char operat = expression[cursor];
		++cursor;
		double fact2 = parseThirdDegree();
		fact1 = pow(fact1, fact2);

	}
	return fact1;
}



double parseFactor()
{
	ignoreWhiteSpaces();
	if (expression[cursor] >= '0' && expression[cursor] < '9')
	{
		return parseNumber();
	}
	else if (expression[cursor] == '(')
	{
		++cursor;
		double number = parseFormula();
		if (expression[cursor] != ')')
			valid_expr = false;
		else ++cursor;
		return number;
	}
	else
	{
		valid_expr = false;
		return -1;
	}

}

double parseNumber()
{
	double number{};
	ignoreWhiteSpaces();
	while (expression[cursor] >= '0' && expression[cursor] <= '9')
	{
		number *= 10;
		number += expression[cursor] - '0';
		++cursor;

	}
	if (expression[cursor] == '.')
	{
		++cursor;
		double divider{ 1 };
		while (expression[cursor] >= '0' && expression[cursor] <= '9')
		{
			divider /= 10;
			number += (expression[cursor] - '0') * divider;
			++cursor;
		}
	}



	return number;
}

void ignoreWhiteSpaces()
{
	while (expression[cursor] == ' ')
		++cursor;
}

void print()
{
	cursor = 0;
	double expr = parseFormula();
	if (valid_expr)
		std::cout << expr << '\n';
	else std::cout << "Invalid expression!\n";
}