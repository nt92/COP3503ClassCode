/*******************************************************************
 *					Name: Musawir Ali Shah  					   *
 *					SSN: 999-10-6888							   *
 *					FileName: tree.h						       *
 * Module Description:											   *
 * This is the implementation of the class binary_tree. All the    *
 * functions are commented as to what they do.					   *
 *******************************************************************/
#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <cstdlib>
using namespace std;

bool IsOperator(string mystring)
{
	if(mystring == "-" || mystring == "+" || mystring == "/" || mystring == "*" || mystring == "^")
		return(true);
	else
		return(false);
}

bool IsOperator(char ops)
{
	if(ops == '+' || ops == '-' || ops == '*' || ops == '/' || ops == '^' || ops == '(' || ops == ')')
		return(true);
	else
		return(false);
}


class node_type
{
public:
	string data;
	node_type *left_child;
	node_type *right_child;
	node_type(string k)
	{
		data=k;
		left_child = NULL;
		right_child = NULL;
	}
};

class binary_tree
{
public:
	node_type *root;
	void print(node_type *r);
	binary_tree(void) { root = NULL;}
	void print(void) {print (root);}
	void evaluate()
	{
		evaluate(root);
	}
	void evaluate(node_type* prt)
	{
		if(IsOperator(prt->data) && !IsOperator(prt->left_child->data) && !IsOperator(prt->right_child->data))
		{
			int num = 0;
			int num1 = atoi(prt->left_child->data.c_str());
			int num2 = atoi(prt->right_child->data.c_str());
			if(prt->data == "+")
			  num = num1 + num2;
			else if(prt->data == "-")
			  num = num1 - num2;
			else if(prt->data == "*")
			  num = num1 * num2;
			else if(prt->data == "/")
			  num = num1 / num2;
			else if(prt->data == "^")
			  num = pow(num1,num2);
			stringstream bob;
			bob << num;
			string suzzy(bob.str());
			prt->data = suzzy;
			prt->left_child = NULL;
			prt->right_child = NULL;
		}
		else if(prt->left_child == NULL && prt->right_child == NULL);
		else
		{
			evaluate(prt->left_child);
			evaluate(prt->right_child);
			evaluate(prt);
		}
	}

	void clear_help(node_type* rt)
	{
		if( rt != NULL )
		{
			clear_help( rt->left_child);
			clear_help( rt->right_child);
			delete rt;
        }

    }
	void clear()
	{
		clear_help(root);
	}

};

node_type *build_node(string x)
{
	node_type *new_node;
	new_node = new node_type(x);
	return(new_node);
}

void binary_tree::print(node_type *p)
{
	if(p != NULL)
	{
		print(p->left_child);
		print(p->right_child);
		cout << p->data << " ";
	}
}

bool IsOperand(char ch) //Checks for character to be an operand
{
   if ((ch >= '0') && (ch <= '9'))
      return true;
   else
      return false;
}

//Checks Precedence, returns true of A is higher precendence over B
bool TakesPrecedence(char OperatorA, char OperatorB)
{
   if (OperatorA == '(')
      return false;
   else if (OperatorB == '(')
      return false;
   else if (OperatorB == ')')
      return true;
   else if ((OperatorA == '^') && (OperatorB == '^'))
      return false;
   else if (OperatorA == '^')
      return true;
   else if (OperatorB == '^')
      return false;
   else if ((OperatorA == '*') || (OperatorA == '/'))
      return true;
   else if ((OperatorB == '*') || (OperatorB == '/'))
      return false;
   else
      return true;

}

void copy(node_type *&r1, node_type *r2)
{
	if(r2 == NULL)
		r1 = NULL;
	else
	{
		if(r1 == NULL)
		{
			r1 = build_node(r2->data);
			copy(r1->left_child, r2->left_child);
			copy(r1->right_child, r2->right_child);
		}
		else
		{
			r1 = build_node(r2->data);
			copy(r1->left_child, r2->left_child);
			copy(r1->right_child, r2->right_child);
		}
	}
}

#endif
