#include "badnums.h"
#include "complicated.h"
#include <iostream>
using namespace std;

/*
This file is going to be your working ground. Please do not
make changes to any of the other files. You may of course read
through them to understand the logic but refrain to changing them
until you have completed the two functions below.

Each function has some setup code at the beginning to initialize
the data structure. Please do not change this code. Your job is
to insert code where designated to get the required results.
 */


/*
This function tests the positive cruncher. Upon successful completion
of this function, the program should either give an incorrect/strange
value for the functions given the numbers in the vector numbers or
crash altogether. BOTH OUTCOMES ARE POSSIBLE. Please try to make
both happen before moving on.

Note, the code you need to add is not terribly complicated. Think
carefully before acting. HINT: It is called a POSITIVE number cruncher
 */
void badNumberFunction(){
    //Initialize the Cruncher
    PositiveCruncher pc;

    //Populate with some initial values
    pc.addNumber(1);
    pc.addNumber(5);
    pc.addNumber(3);

//    pc.getNumbers().push_back(0);
    ////////////////////////////////////////////////////////
    // ADD CODE HERE TO MAKE SOME OF THE FOLLOWING OCCUR: //
    // A) Give an incorrect answer                        //
    // B) Crash the program                               //
    ////////////////////////////////////////////////////////


    //Display the calculations
    cout << "Average is: " << pc.average() << endl;
    cout << "Squares are: " << pc.squareSum() << endl;
    cout << "Square roots are: " << pc.squareRootSum() << endl;
    cout << "Ratios are: " << pc.ratioSum() << endl;

}


/*
This function tests the more complicated data structure we gave you.
If you look closely, it appears that the problem of the Number
Cruncher has been fixed in this class (const). However, it is still
not perfect. The ComplicatedExample comes pre-initialized. It is your
job to try to make a change to that initialized structure. If a change
is successfully made, isChanged() will return true and you will see
GOOD JOB! displayed. Otherwise, you will see KEEP TRYING!

This class should hopefully teach you think carefully when using
pointers!

Hint: Look at the structure of isChanged to see what is actually
happening.
 */
void complicatedFunction(){
    ComplicatedExample ce;

    const vector<ImportantInfo*> & test = ce.getStuff();

    ImportantInfo* const* temp = &test[2];
    ImportantInfo* const* temp2 = &test[3];
    //*temp2 = *temp;



    /////////////////////////////////////////////////
    //ADD CODE HERE SO THAT pc.isChanged() passes! //
    /////////////////////////////////////////////////

    if(ce.isChanged())
        cout << "GOOD JOB!" << endl;
    else
        cout << "KEEP TRYING!" << endl;

}

int main(){
    badNumberFunction();
    complicatedFunction();
    return 0;
}
