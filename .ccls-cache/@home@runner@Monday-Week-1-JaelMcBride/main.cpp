// Monday-Week-1
// Due: Friday, February 10, 11:59 PM
/*************************************************
Student First Name: 
Student Last Name: 
**************************************************/

#include <iostream>
#include<string>
using namespace std;

int main()
{
    string uName;

    cout << "Hello World!\nAnd most importantly\nHELLO CS 216!!!\n";

    cout << "Please enter your first and last name fellow human\n";

    getline(cin, uName);

    cout << "Well Hello " << uName << '!' << endl;
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
