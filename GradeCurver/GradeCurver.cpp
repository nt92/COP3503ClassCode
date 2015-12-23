#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the number of students: ";
	int num;
	cin >> num;
	int scores[num];
	char grades[num];

	cout << "Enter " << num << " scores: ";

	int best = -1;
	for(int i = 0; i < num; i++)
	{
		cin >> scores[i];
		if(best < scores[i])
		{
			best = scores[i];
		}
	}

	for(int i = 0; i < num; i++)
	{
	    if(scores[i] >= best - 10)
	    {
	    	grades[i]='A';
	    }
	    else if(scores[i] >= best - 20)
	    {
	    	grades[i]='B';
	    }
	    else if(scores[i] >= best - 30)
	    {
	   		grades[i]='C';
	    }
	   	else if(scores[i] >= best - 40)
	   	{
	   		grades[i]='D';
	   	}
	   	else
	   	{
	   		grades[i]='F';
	   	}

	   	cout << "Student " << i << " score is " << scores[i] << " and grade is "  << grades[i]<< endl;
	}


	return 0;
}
