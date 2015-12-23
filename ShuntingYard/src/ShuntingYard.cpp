#include <iostream>
#include <sstream>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <stdlib.h>

using namespace std;

const int LeftAssoc  = 0;

// Creates map for +, -, *, /, and rt operators
typedef map<string, pair<int, int> > OpMap;

const OpMap::value_type associations[] = {
		OpMap::value_type("+", make_pair<int, int> (0, LeftAssoc)),
		OpMap::value_type("-", make_pair<int, int> (0, LeftAssoc)),
		OpMap::value_type("*", make_pair<int, int> (5, LeftAssoc)),
		OpMap::value_type("/", make_pair<int, int> (5, LeftAssoc)),
		OpMap::value_type("rt", make_pair<int, int> (10, LeftAssoc))};

const OpMap opmap(associations, associations + sizeof(associations) / sizeof(associations[0]));

// Tests if token is a parenthesis
bool isParenthesis(const string& token)
{
	return token == "(" || token == ")";
}

// Tests if token is an operator
bool isOperator(const string& token)
{
	return token == "+" || token == "-" || token == "*" || token == "/" || token =="rt";
}

// Tests associativity of operator token
bool isAssociative( const string& token, const int& type)
{
	const pair<int,int> p = opmap.find(token)->second;
	return p.second == type;
}

// Compares precedence of operators
int cmpPrecedence( const string& token1, const string& token2 )
{
	const pair<int,int> p1 = opmap.find(token1)->second;
	const pair<int,int> p2 = opmap.find(token2)->second;

	return p1.first - p2.first;
}

// Converts infix expression format into postfix notation
bool infixToPostfix(const vector<string>& inputTokens, const int& size, vector<string>& strArray)
{
	bool success = true;

	list<string> out;
	stack<string> stack;

	for (int i = 0; i < size; i++)
	{
		const string token = inputTokens[i];

		if (isOperator(token))
		{
			// While there is an operator token, o2, at the top of the stack AND either o1 is left-associative AND its precedence is equal to that of o2, OR o1 has precedence less than that of o2
			const string o1 = token;

			if (!stack.empty())
			{
				string o2 = stack.top();

				while (isOperator(o2) && ((isAssociative(o1, LeftAssoc) && cmpPrecedence(o1, o2) == 0) || (cmpPrecedence(o1, o2) < 0 )))
				{
					// pop o2 off the stack, onto the output queue;
					stack.pop();
					out.push_back(o2);

					if (!stack.empty())
						o2 = stack.top();
					else
						break;
				}
			}

			// push o1 onto the stack.
			stack.push(o1);
		}
		// If the token is a left parenthesis, then push it onto the stack.
		else if (token == "(")
			stack.push(token);

		else if (token == ")")
		{
			// Until the token at the top of the stack is a left parenthesis, pop operators off the stack onto the output queue
			string topToken  = stack.top();

			while (topToken != "(")
			{
				out.push_back(topToken);
				stack.pop();

				if (stack.empty())
					break;
				topToken = stack.top();
			}

			// Pop the left parenthesis from the stack, but not onto the output queue.
			if (!stack.empty())
				stack.pop();

			// If the stack runs out without finding a left parenthesis, then there are mismatched parentheses
			if ( topToken != "(")
				return false;
		}
		// If the token is a number, then add it to the output queue.
		else
			out.push_back( token );
	}

	// While there are still operator tokens in the stack:
	while (!stack.empty())
	{
		const string stackToken = stack.top();

		// If the operator token on the top of the stack is a parenthesis then there are mismatched parentheses
		if (isParenthesis(stackToken))
			return false;

		// Pop the operator onto the output queue.
		out.push_back(stackToken);
		stack.pop();
	}

	strArray.assign(out.begin(), out.end());
	return success;
}

// Converts a string expression to an array of tokens
vector<string> getExpressionTokens(const string& expression)
{
	vector<string> tokens;
	string str = "";

	for (int i = 0; i < (int)expression.length(); i++)
	{
		const string token(1, expression[i]);

		if (isOperator(token) || isParenthesis(token))
		{
			if (!str.empty())
				tokens.push_back(str);
			str = "";
			tokens.push_back(token);
		}
		else
		{
			// Append the numbers
			if (!token.empty() && token != " ")
				str.append(token);
			else
			{
				if (str != "")
				{
					tokens.push_back(str);
					str = "";
				}
			}
		}
	}
	return tokens;
}

int main()
{
	cout << "> ";
	string s;
	getline(cin, s);
	s.append(" ");

	vector<string> tokens = getExpressionTokens(s);

	vector<string> postfix;
	if (infixToPostfix(tokens, tokens.size(), postfix))
	{
		for(int i = 0; i < (int)postfix.size(); i++)
		{
			cout << postfix[i] << " ";
		}
	}
	else
		cout << "Error in parenthesis. Please run again." << endl;

	return 0;
}
