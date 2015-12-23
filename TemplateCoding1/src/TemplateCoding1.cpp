/*
 * main.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: Joshua
 */

#include <iostream>
#include "CustomVector.h"
#include "Fraction.h"

using namespace std;

int main()
{
	CustomVector<Fraction> vec;
	CustomVector<string> strs;
	CustomVector<int> ints;
	CustomVector<double> doubles;

	cout << "A CustomVector's default size is :" << CustomVector<Fraction>::defaultSize << endl;

	vec.add(Fraction(3, 4));
	vec.add(Fraction(1, 2));

	vec[1] = Fraction(7, 8);

	cout << "Vector contents: " << endl;

	cout << vec;
}


