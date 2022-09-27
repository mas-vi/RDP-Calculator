#pragma once
#include <iostream>
#include <Windows.h>
#include "parser.hpp"


void getInput(char& action)
{
	std::cout << "Introduce an action\n";
	std::cout << "q - quit ; n - introduce a new expression; e = evaluate current value; c - clear; p - print\n";
	std::cout << "action:";
	std::cin >> action;
}

void getNewValue()
{
	std::getline(std::cin, expression);
}
void handleInput(char& action, bool& shoudlClose)
{
	switch (action)
	{
	case 'q':
		shoudlClose = true;
		break;
	case 'n':
		getNewValue();
		break;
	case 'e':
		std::cout << "expression = ";
		print();
		break;
	case 'c':
		system("cls");
		break;
	case 'p':
		std::cout << expression << '\n';
		break;
	default:
		getInput(action);
		break;
	}
}
void run()
{
	bool shoudlClose = false;
	char action{};

	while (!shoudlClose)
	{
		getInput(action);
		handleInput(action, shoudlClose);
	}
}