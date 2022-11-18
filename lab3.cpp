/*Great job.  Your float extra credit works!*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {

//Please check extra credit!

/*
Jael McBride
21, September, 2022
*/

// variables

  /*char*/string initialOne, initialTwo, initialThree;

  /*int*/float tValueOne, tValueTwo, tValueThree;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
// User inputs (Initials)
  
cout << "Please enter three ONE letter initial when promted." << endl;

cout << "Enter initial 1" << endl;
  getline (cin,initialOne);

  //cin >> initialOne;

cout << "Enter initial 2" << endl;
  getline (cin,initialTwo);

  //cin >> initialTwo;

cout << "Enter initial 3" << endl;

  cin >> initialThree;

 // Test output for char: cout << initialOne << initialTwo << initialThree;
  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
// User inputs (Num-Values)

cout << "Please enter 3 number values that are NON-Negative numbers" << endl;

cout << "Enter the first number" << endl;

  cin >> tValueOne;



cout << "Enter the second number" << endl;
  
 cin>> tValueTwo;



cout << "Enter the third number" << endl;
  
cin>> tValueThree;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
// If/Else for invaild inputs

//value one
if (tValueOne>0) {
    cout << "Initial " << initialOne<< " equals " << tValueOne << endl;
  }
  else { cout << "An invalid value was inputed, please start program again." << endl; abort();}
//                                                                                      ^program end is invalid


//value 2
if (tValueTwo>0) {
    cout << "Initial " << initialTwo << " equals " << tValueTwo << endl;
  }
  else { cout << "An invalid value was inputed, please start program again." << endl; abort();}



//value 3
if (tValueThree>0) {
    cout << "Initial " << initialThree << " equals " << tValueThree << endl;
  }
  else { cout << "An invalid value was inputed, please start program again." << endl; abort();}

cout << "Adding inputed values to initials so we can make a triangle \n";

////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (tValueOne == tValueTwo && tValueTwo == tValueThree && tValueThree == tValueOne) {

  cout << "your triangle is an equilateral" << endl;} //abort();}
  
  else if(tValueOne == tValueTwo || tValueTwo == tValueThree || tValueThree == tValueOne) {

    cout << "your triangle is an isosceles" << endl;} //abort();}
    
    else if(tValueOne != tValueTwo && tValueTwo != tValueThree) {

      cout << "Your triangle is a scalene" << endl;} //abort();}

  
//not sure what I did but it worked!!!!!!!!! now time for extra credit.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//get the code in class

/*
 if ((fabs(tValueOne - tValueTwo)) || (fabs(tValueTwo - tValueTwo)) < 0.000001) {
   return 0;
 }
    else cout << "";

wrong so trying to find tutor

*/
  


// Found a guy who will help me 9/25/2022 9:51pm

float hypotenuse; // i hate that i need more variables!!! I just wanna sleep!
float sideOne;
float sideTwo;
// Comparing the numbers to find the hypotenuse.
// cause hypotenuse will always be the larger number
if (tValueOne > tValueTwo && tValueOne > tValueThree) {
hypotenuse = tValueOne;
sideOne = tValueTwo;
sideTwo = tValueThree;
}
else if (tValueTwo > tValueOne && tValueTwo > tValueThree)
{
hypotenuse = tValueTwo;
sideOne = tValueOne;
sideTwo = tValueThree;
}
else {
hypotenuse = tValueThree;
sideOne = tValueOne;
sideTwo = tValueTwo;
}
//AAAAAAAAAAAHHHHHHHHH   WHY IS THIS SO PUZZLING 
if (((sideOne*sideOne) + (sideTwo*sideTwo) - (hypotenuse*hypotenuse)) < 0.0001) {
cout << "and it has a right angle\n";
}
else { 
cout << "and does not have a right angle\n"; 
}

} // Main (DO NOT REMOVE)
  
/*
 make -s
 ./main
Please enter three ONE letter initial when promted.
Enter initial 1
a
Enter initial 2
b
Enter initial 3
c
Please enter 3 number values that are NON-Negative numbers
Enter the first number
3
Enter the second number
4
Enter the third number
5
Initial a equals 3
Initial b equals 4
Initial c equals 5
Adding inputed values to initials so we can make a triangle 
Your triangle is a scalene
and it has a right angle
 
*/