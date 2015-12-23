#ifndef BAD_NUMS
#define BAD_NUMS

#include <vector>
using namespace std;

/*
 This is a class built to do operations on positive integers.
 addNumber is a method that allows the user to put numbers into the
 class. Once populated, the class can do a variety of useful
 calculations on the numbers
 */

class PositiveCruncher{
private:
    vector<int> numbers;

public:
    PositiveCruncher();
    bool addNumber(int);
    vector<int>& getNumbers();
    int size();
    float sum();
    float average();
    float squareRootSum();
    float squareSum();
    float ratioSum();
};

#endif
