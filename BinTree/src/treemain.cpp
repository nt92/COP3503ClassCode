/*******************************************************************
 *					Name: Musawir Ali Shah  					   *
 *					FileName: treemain.cpp						   *
 * Module Description:											   *
 * This is the main file containing the main function.			   *
 *******************************************************************/
#include <iostream>
#include <string>
#include <stack>
#include "tree.h"

/*********** Checks if expression is ok **********/
bool isok(string exp)
{
	char check;
	int error=0;
	int lb=0;
	int rb=0;
	for(int m=0;m < exp.size(); m++)
	{
		check = exp[m];
		if(IsOperand(check))
		{


		}
		else if(IsOperator(check))
		{
			if(check == ')')
			{
				rb++;
				if(IsOperator(exp[m+1]) && (exp[m+1]=='+' || exp[m+1]=='-' || exp[m+1]=='*' || exp[m+1]=='/' || exp[m+1]=='^' || exp[m+1]==')'))
				{
					m++;
					if(exp[m] == ')')
						rb++;
				}
				else if(IsOperator(exp[m+1]))
					error++;
			}
			else if(check == '(')
			{
				lb++;
				if(IsOperator(exp[m+1]) && exp[m+1] =='(')
				{
					m++;
					lb++;
				}
				else if(IsOperator(exp[m+1]))
					error++;
			}
			else
			{
				if(IsOperator(exp[m+1]) && exp[m+1] == '(')
				{
					m++;
					lb++;
				}
				else if(IsOperator(exp[m+1]))
					error++;
			}
		}
		else
			error++;
	}

	if(error == 0 && lb==rb)
		return(true);
	else
		return(false);
}
/*******************************************/

int main()
{
	binary_tree etree;
	stack<binary_tree> NodeStack;
	stack<char> OpStack;
	string infix;
	char choice = 'y';
	char c;

	while(choice == 'y' || choice == 'Y')
	{
		cout << "\n\nIntroduce the Expression (no spaces): ";
		cin >> infix;
		cout << "----------------------------------------------" << endl;
		cout << "Expression:   " << infix << endl;

		if(isok(infix))
		{
			for(int i=0; i < infix.size(); i++)
			{
				c = infix[i];
				if(IsOperand(c)) //if operand, create tree and push into NodeStack
				{
					string tempstring;
					tempstring = tempstring + c;
					if(i+1 < infix.size() && IsOperand(infix[i+1]))
					{
						while(i+1 < infix.size() && IsOperand(infix[i+1]))
						{
							tempstring = tempstring + infix[++i];
						}
					}
					binary_tree temp;
					temp.root = build_node(tempstring);
					NodeStack.push(temp);
				}
				//Else if Operator, check precedence and push into OpStack
				else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
				{
					if(OpStack.empty())
						OpStack.push(c);
					else if(OpStack.top() == '(')
						OpStack.push(c);
					else if(TakesPrecedence(c, OpStack.top()))
						OpStack.push(c);
					else
					{
						while(!OpStack.empty() && TakesPrecedence(OpStack.top(), c))
						{
							binary_tree temp_tree;
							string thisstring="";
							thisstring = thisstring + OpStack.top();
							OpStack.pop();
							etree.root = build_node(thisstring);
							copy(temp_tree.root,NodeStack.top().root);
							NodeStack.pop();
							etree.root->right_child = temp_tree.root;
							temp_tree.root = NULL;
							copy(temp_tree.root,NodeStack.top().root);
							etree.root->left_child = temp_tree.root;
							NodeStack.pop();
							temp_tree.root = NULL;
							copy(temp_tree.root, etree.root);
							NodeStack.push(temp_tree);
							etree.root = NULL;

						}
						OpStack.push(c);
					}
				}
				else if(c == '(')
					OpStack.push(c);
				else if(c == ')')
				{
					while(OpStack.top() != '(')
					{
						binary_tree temp_tree;
						string thisstring="";
						thisstring = thisstring + OpStack.top();
						OpStack.pop();
						etree.root = build_node(thisstring);
						copy(temp_tree.root,NodeStack.top().root);
						NodeStack.pop();
						etree.root->right_child = temp_tree.root;
						temp_tree.root = NULL;
						copy(temp_tree.root,NodeStack.top().root);
						etree.root->left_child = temp_tree.root;
						NodeStack.pop();
						temp_tree.root = NULL;
						copy(temp_tree.root, etree.root);
						NodeStack.push(temp_tree);
						etree.root = NULL;
					}
					OpStack.pop();
				}

			} // end of for loop

			while(!OpStack.empty()) //While OpStack not empty, pop that stack
									//and create tree
			{
				binary_tree temp_tree;
				string thisstring="";
				thisstring = thisstring + OpStack.top();
				OpStack.pop();
				etree.root = build_node(thisstring);
				copy(temp_tree.root,NodeStack.top().root);
				NodeStack.pop();
				etree.root->right_child = temp_tree.root;
				temp_tree.root = NULL;
				copy(temp_tree.root,NodeStack.top().root);
				etree.root->left_child = temp_tree.root;
				NodeStack.pop();
				temp_tree.root = NULL;
				copy(temp_tree.root, etree.root);
				NodeStack.push(temp_tree);
				if(!OpStack.empty())
				{
					etree.root = NULL;
				}
			}

			cout << "Postfix traversal: ";
			etree.print();
			cout << endl;
			etree.evaluate();
			cout << "Result: " << etree.root->data << endl;
			cout << "----------------------------------------------" << endl;
			cout << "\n\nRun Program again? Enter <y/n> : ";
			cin >> choice;
			}
			else
			{
				cout << "******************************************************" << endl;
				cout << "ERROR: Invalid Expression" << endl;
				cout << "******************************************************" << endl;
				cout << "\n\nRun Program again? Enter <y/n> : ";
				cin >> choice;

			}
	}
	return 0;
} //end of main
