//============================================================================
// Name        : NumericalMenu.cpp
// Author      : Nikhil Thota
// Version     : 6/15/15
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "NumericalMenu.h"

NumericalMenu::NumericalMenu()
{
	prompt = "Choose an option: ";
	error = "Error!";
	cancel = "Cancel";
	numOptions = 0;
	repeatPrompt = true;
}

void NumericalMenu::setPrompt(string text)
{
	prompt = text;
}

int NumericalMenu::addOption(string text)
{
	numOptions++;
	options.push_back(text);

	return numOptions;
}


void NumericalMenu::setCancelText(string text)
{
	cancel = text;
}
void NumericalMenu::setRepeatPromptOnError(bool repeat)
{
	repeatPrompt = repeat;
}

void NumericalMenu::setErrorText(string text)
{
	error = text;
}

int NumericalMenu::run() const
{
	int selected;

	cout << prompt << endl << endl;

	for(int i = 1; i <= size(); i++)
	{
		cout << i << " - " << options[i - 1] << endl;
	}

	cout << size() + 1 << " - " << cancel << endl << endl;

	while(!(cin >> selected) || selected < 1 || selected > size() + 1)
	{
		if(!repeatPrompt)
		{
			cout << endl << error << endl << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			cout << endl << error << endl << endl;
			cin.clear();
			cin.ignore(1000, '\n');

			cout << prompt << endl << endl;

			for(int i = 1; i <= size(); i++)
			{
				cout << i << " - " << options[i - 1] << endl;
			}

			cout << size() + 1 << " - " << cancel << endl << endl;
		}
	}

	if(selected == size() + 1)
	{
		return -1;
	}
	else
	{
		return selected;
	}
}

int NumericalMenu::size() const
{
	return numOptions;
}

void test1(){
    NumericalMenu menu;

    menu.addOption("Cat");
    menu.addOption("Dog");

    int a = menu.run();

    std::cout << "Return Value is: " << a << std::endl;
}

void test2(){
    NumericalMenu menu;

    menu.addOption("Cat");
    menu.addOption("Dog");
    menu.addOption("");

    menu.setCancelText("None");

    menu.setPrompt("Choose an animal");
    menu.setErrorText("Wrong!");
    menu.setRepeatPromptOnError(false);

    int result = menu.run();

    std::cout << "The choice was: " << result << std::endl;

    menu.addOption("?");

    std::cout << "Size is " << menu.size() << std::endl;
}

void test3(){
    NumericalMenu menu;

    menu.addOption("Cat");
    menu.addOption("Dog");

    menu.setCancelText("None");

    menu.setPrompt("Choose an animal");
    menu.setErrorText("Wrong!");
    menu.setRepeatPromptOnError(false);

    int result = menu.run();

    std::cout << "The choice was " << result << std::endl;

    while(result != -1){
        result = menu.run();
        std::cout << "\nThe choice was " << result << std::endl;
    }
}
