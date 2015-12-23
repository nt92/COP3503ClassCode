#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "Enter a, b, c: ";
	double a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	double discrim = b * b - 4 * a * c;
	if(discrim < 0)
		{
			cout << "The equation has no real roots";
		}
	else if(discrim > 0)
		{
			double r1 = (-b + sqrt(discrim)) / (2 * a);
			double r2 = (-b - sqrt(discrim)) / (2 * a);

			cout << "The equation has two roots "  << r1 << " and " << r2;
		}
	else // if discrim == 0
		{
			double r = -b / (2 * a);

			cout << "The equation has one root " << r;
		}

	return 0;
}

