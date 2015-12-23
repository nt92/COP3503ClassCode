#include "badnums.h"
#include <cmath>

PositiveCruncher::PositiveCruncher(){

}

/*
Note the check for >= 0.
 */
bool PositiveCruncher::addNumber(int n){
    if(n <= 0){
        return false;
    }
    numbers.push_back(n);
    return true;
}

vector<int>& PositiveCruncher::getNumbers(){
    return numbers;
}

float PositiveCruncher::sum(){
    float accum = 0;

    for(int n = 0; n < numbers.size(); n++)
    	accum += numbers[n];

    return accum;
}

int PositiveCruncher::size(){
    return numbers.size();
}

float PositiveCruncher::average(){
    return sum()/size();
}

float PositiveCruncher::squareRootSum(){
    float accum = 0;
    for(int n = 0; n < numbers.size(); n++){
        accum += sqrt(numbers[n]);
    }
    return accum;
}

float PositiveCruncher::ratioSum(){
    float accum = 0;
    for(int n = 0; n < numbers.size(); n++){
        float temp = 1/numbers[n];
        accum += 1.0/numbers[n];
    }
    return accum;
}

float PositiveCruncher::squareSum(){
    float accum = 0;
    for(int n = 0; n < numbers.size(); n++){
        accum += numbers[n]*numbers[n];
    }
    return accum;
}
