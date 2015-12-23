#include <iostream>
using namespace std;

int getDigit(int number)
{
	return (number / 10) + (number % 10);
}

int getSize(long long d)
{
	int count = 0;
	while(d > 0)
	{
		d /= 10;
		count++;
	}
	return count;
}

int sumOfDoubleEvenPlace(long long number)
{
	int sum = 0;

	while(number > 0)
	{
		int digit = (int) ((number % 100) / 10);
		number /= 100;

		sum += getDigit(2 * digit);
	}

	return sum;
}

int sumOfOddPlace(long long number)
{
	int sum = 0;

	while(number > 0)
	{
		int digit = (int) (number % 10);
		number /= 100;

		sum += getDigit(digit);
	}

	return sum;
}

long long getPrefix(long long number, int k)
{
	int numberSize = getSize(number);
	int decimalMovements = numberSize - k;

	while(decimalMovements-- > 0)
	{
		number /= 10;
	}
	return number;
}

bool prefixMatched(long long number, int d)
{
	return getPrefix(number, getSize(d)) == d;
}

bool isValid(long long number)
{
	int numSize = getSize(number);

	if(numSize > 16 || numSize < 13)
	{
		return false;
	}

	int sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);

	if(sum % 10 != 0)
	{
		return false;
	}

	if(prefixMatched(number, 4) || prefixMatched(number, 5) || prefixMatched(number, 37) || prefixMatched(number, 6))
	{
		return true;
	}

	return false;
}

int main()
{
	cout << "Enter a credit card number as a long long integer: ";
	long long number;
	cin >> number;

	if(isValid(number))
	{
		cout << number << " is " << " valid";
	}
	else
	{
		cout << number << " is " << " invalid";
	}

	return 0;
}
