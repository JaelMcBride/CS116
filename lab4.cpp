/*Nice program.  One suggestion:  If you set up a Boolean at Line 30, you would not have to repeat that big if statement.*/

#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <limits>
using namespace std;

/*
Need to define the variables that will go into the loop like speed, hours, and vehicle 
Ask the user to input values and/or names into those variables (If user inputs a negative number for speed of the vehicle(speed) or user inputs a value less than 1 for hours of travel(time), output an error statement and ask user to input allowed inputs before looping step two again. 
Loop step two to allow user to input multiple names of vehicles if wanted, after each loop ask user if they want to input another vehicle name 
If user does not want to add another vehicle name end loop 
Write loop by having HOURS be the times in which the loop will loop, and speed be the amount ADDED for EACH loop 
Output string (as in vehicle name that was inputted) above, hours to the left, and travel distance to the right using (setw) 
(Are we supposed to let users add another value for speed and time traveled for step two if they want to add another vehicle or is it just another vehicle name and we use the same speed and time inputs? Cause I have no clue how we’re going to code a looping code that also calculates multiple mph and time values and not have it get all jumbled up. Like we can use an if else statement for amount of vehicles inputted to change the code but we would have to set a limit to the number of vehicles allowed cause the user could theoretically put an infinite amount of vehicles) 
*/
int main() {

int hoursTraveled, speedMPH, totalDistance, timeTraveled, i;

string userYnN, vName, temp;

cout << "Would you like to calculate the distance traveled of a vehicle?\n(Enter Yes/No)\n";

  cin >> userYnN;

  if (userYnN == "yes" || userYnN == "Yes" || userYnN == "YEs" || userYnN == "YES" || userYnN == "yES" || userYnN == "yeS") {
    cout << endl << "Welcome, ";
    }
while (userYnN == "yes" || userYnN == "Yes" || userYnN == "YEs" || userYnN == "YES" || userYnN == "yES" || userYnN == "yeS") { // While loop 1
  cout << "please enter the name of the vehicle.\n";
  

getline(cin,temp);
  getline(cin,vName);
  
  cout << endl << "Enter the speed of which this " << vName << " travels in MPH\n(Miles Per Hour, cannot be a negative value)\n";

  cin >> speedMPH;

  if (speedMPH < 0 || (!cin)) { 
    do {
     cin.clear ();
     cin.ignore (200,'\n');
     cout << "Invalid value detected, Please input another value.\n";
       cin >> speedMPH;
     } while (speedMPH < 0 || (!cin)); // do while expression
    
    }// If speed is less than 1
  
  cout << endl << "So this " << vName << " travels at " << speedMPH << "Mph.\n" << "How many hours will this " << vName << " travel for?\n";

  cout << endl << "Enter amount of hours this " << vName << " will travel in hours only. (Inputted value cannot be less than 0 or a negative number)\n";

  cin >> hoursTraveled;

  if (hoursTraveled < 1 || (!cin)) { 
    do {
      cin.clear ();
      cin.ignore (200,'\n');
      cout << "Invalid value detected, Please input another value.\n";
       cin >> hoursTraveled;
    }  while (hoursTraveled < 1 || (!cin)); // do while expression
    
  }// If hours is less than 1

  cout << endl << endl;

totalDistance = speedMPH;
timeTraveled = hoursTraveled;
  
  cout << fixed << setw(10) << left << "Hour/s" << fixed << setw(10) << right << "Distance traveled" << endl;
  
//for (hoursTraveled = hoursTraveled; hoursTraveled > 1; hoursTraveled--)
for (timeTraveled = 1; timeTraveled < hoursTraveled; timeTraveled++ ){
  cout << fixed << setw(10) << left << timeTraveled << fixed << setw(10) << right << totalDistance << endl;

 totalDistance = totalDistance + speedMPH;
  
  } // for loop

  cout << fixed << setw(10) << left << timeTraveled << fixed << setw(10) << right << totalDistance << endl << endl;
  
 cout << "If this " << vName << " traveled for " << timeTraveled << " hours at " << speedMPH << "Mph.\nThen the the total distance this " << vName << " has traveled is " << totalDistance << " miles." << endl << endl;

cout << "Would you like to run this program again?\n Yes/No\n\n";

  cin >> userYnN;
  
} // While loop 1

 cout << "Have a nice day.\n"; // outputted when user inputs anything other than yes.

/*
 make -s
 ./main
Would you like to calculate the distance traveled of a vehicle?
(Enter Yes/No)
yes

Welcome, please enter the name of the vehicle.
Porsche 911

Enter the speed of which this Porsche 911 travels in MPH
(Miles Per Hour, cannot be a negative value)
240

So this Porsche 911 travels at 240Mph.
How many hours will this Porsche 911 travel for?

Enter amount of hours this Porsche 911 will travel in hours only. (Inputted value cannot be less than 0 or a negative number)
3


Hour/s    Distance traveled
1                240
2                480
3                720

If this Porsche 911 traveled for 3 hours at 240Mph.
Then the the total distance this Porsche 911 has traveled is 720 miles.

Would you like to run this program again?
 Yes/No

no
Have a nice day.
 
*/
  
} // int main