/*
 * NumericalMenu.h
 *
 *  Created on: Jun 14, 2015
 *      Author: Nikhil
 */

#include <vector>
using namespace std;

#ifndef NUMERICALMENU_H_
#define NUMERICALMENU_H_

class NumericalMenu
{
public:
	NumericalMenu();
	//virtual ~NumericalMenu();

	void setPrompt(string);
	int addOption(string);
	void setCancelText(string);
	void setRepeatPromptOnError(bool);
	void setErrorText(string);
	int run() const;
	int size() const;

private:
	string prompt;
	string error;
	string cancel;
	int numOptions;
	bool repeatPrompt;
	vector<string> options;
};


#endif /* NUMERICALMENU_H_ */
