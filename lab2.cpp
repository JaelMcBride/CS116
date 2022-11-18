/*Your program is fine.  But your code does not match the algorithm.  You say "cout<< " gross and multiply......., but you really coded all of the match before the output.*/

#include <iostream>
#include <iomanip>;
#include <string>;
using namespace std;

/*
Jael McBride
7, September, 2022
*/

// You kept talking about user input, so I assumed you also wanted user input.

//P.S. Please don't make me reprogram this to remove the user inputs.

//P.P.S It took me 5 Hours to figure out how to multiply by 20% in C++ (lol), I really don't want to look at this peice of code ever again.

int main() {
// variables
  
  string movieName;
  int numAticket, numCticket;
  const float aTicketcost = 12.00;
  const float cTicketcost = 6.00;
  float gboProfit, nboProfit, aptDistributor, aProfit, cProfit;
  

  // user input lines
  
  // movie name
  cout << "Enter movie name" << endl;
  getline(cin,movieName);

  // tickets
  
  cout << "Enter number of adult movie tickets sold" << endl;
  cin >> numAticket;

  cout << "Enter number of child tickets sold" << endl;
  cin >> numCticket;

  // Equations

  // Gross box office gain
  
  aProfit = numAticket * aTicketcost;

  cProfit = numCticket * cTicketcost;

  gboProfit = aProfit + cProfit;
  
 // Net box office gain

  nboProfit = gboProfit * .20;

  // Amount Paid To Distributor

  aptDistributor = gboProfit - nboProfit;

  // outputs


  

  // Movie name
  cout << setw(10) << left << "Movie Name" << setw(29) << right << movieName << endl;
  //Adult tickets sold
  cout << setw(10) << left << "Adult tickets sold " << setw(20) << right << numAticket << endl;
  // Child tickets sold
  cout << setw(10) << left << "Child tickets sold " << setw(20) << right << numCticket << endl;
  // Gross Box Office profit
  cout << setw(10) << left << "Gross Box Office Profit"<< fixed << showpoint << setprecision (2) << setw(16) << right << gboProfit << endl;

  // Net Box Office Profit
  cout << setw(10) << left << "Net Box Office Profit" << fixed << showpoint << setprecision(2) << setw(18) << right << nboProfit << endl;

  // Amount Paid to Distributor
cout << setw(10) << left << "Amount paid to Distributor" << fixed << showpoint << setprecision(2) << setw(13) << right << aptDistributor << endl;

  //Output
/* 
 make -s
 ./main
Enter movie name
Wheels of Fury
Enter number of adult movie tickets sold
100
Enter number of child tickets sold
25
Movie Name               Wheels of Fury
Adult tickets sold                  100
Child tickets sold                   25
Gross Box Office Profit         1350.00
Net Box Office Profit            270.00
Amount paid to Distributor      1080.00

*/

//Algorithm

/*
  Jael, McBride
LAB 2 ALGORITHM

1.	Define variables: numAticket, numCticket
2.	Output movie name with “cout <<.”
3.	Get variable value for “Adult tickets and Child tickets.” With “numAticket =” for adults and “numCticket =” for child tickets 
4.	Output “cout << Adult tickets” and multiply the total amount of tickets sold by the value of the ticket and output the total
5.	Output “cout << Child Tickets” and multiply the total amount of tickets sold by the value of the ticket and output the total
6.	Output “cout << Gross box office” then add the totals of steps 4 & 5 for the total for Gross box office.
7.	Output “cout << Net Box Office” then Multiply the total of step 6 by 20%
8.	Output “cout << Amount paid to Distributor” then subtract the total of step 7 to the total of step 6

Variables
numAticket = 12
numCticket = 6

User inputs
Movie name
Amount of adult tickets
Amount of child tickets
*/
}