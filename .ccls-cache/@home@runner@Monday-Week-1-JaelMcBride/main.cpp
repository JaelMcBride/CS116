// Monday-Week-1
// Due: Friday, February 10, 11:59 PM
/*************************************************
Student First Name: Jael
Student Last Name: Mcbride
**************************************************/

#include <iostream>
#include<string>
using namespace std;

int main()
{
    string uName;

    cout << "Hello World!\n\nAnd most importantly\n\nHELLO CS 216!!!\n\n";

    cout << "Please enter your first and last name fellow human\n\n";

    getline(cin, uName);

    cout << "\nWell Hello " << uName << '!' << endl;
}

/*********************************************
 sh -c make -s
 ./main
Hello World!
And most importantly
HELLO CS 216!!!
Please enter your first and last name fellow human
Jael Mcbride
Well Hello Jael Mcbride!
 

**********************************************/
