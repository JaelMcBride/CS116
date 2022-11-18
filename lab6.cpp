/*Corrections made--you're good to go*/

/*Jael--this is a beautiful program.  I have only 2 changes:
1.  The surcharge should be on the Total bill.  The first one should be 17.97, not 15.23.  That makes some of your totals incorrect.
2.  I would change lines 115-116.  The constant is 60%, not the formula*/

// I think I fixed the problems.

#include <iostream>
#include <iomanip> 
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
//prototypes
void DataEntry (int&, int&, int&, char&, char&, float&, ifstream&, ofstream&, bool&);//errors

float mealTotal (int, int, char); //Total

void TotalwTaxnSur (float, char, float&, float&, float&, float&, float&, float&); //Total with the extra charges

 void receipt (int, int, int, char, char, float, float, float, float, float);

int main() {
// files
ifstream introData;
ofstream errorData, outData;
//variables
int groupID, cMeal, aMeal;
char mType, weekDayorEnd;
float prePayment, Total, TotalwTax, TotalwSurcharge, TotalnWhole, Tax, Surcharge;
bool isDataGood = true;

//Opening files
introData.open ("introData");
outData.open ("outData");
errorData.open ("errorData");

 do { //loop
   
  DataEntry (groupID, aMeal, cMeal, mType, weekDayorEnd, prePayment, introData, errorData, isDataGood);

  Total = mealTotal (aMeal, cMeal, mType);

  TotalwTaxnSur (Total, weekDayorEnd, TotalwTax, TotalwSurcharge, TotalnWhole, Tax, Surcharge, prePayment);
  //void TotalwTaxnSur
   
  if (isDataGood == true) {

    receipt (groupID, aMeal, cMeal, mType, weekDayorEnd, Total, Tax, Surcharge, prePayment, TotalnWhole);
    
  }


   Total = 0;
   Surcharge = 0;
   prePayment = 0;
   Tax = 0;
   TotalnWhole = 0;

   isDataGood = true;
 } while (!introData.eof()); //loop end
  

//Closing files
introData.close();
outData.close();
errorData.close();
return 0;
  
}//main

//functions

//error function
void DataEntry (int& groupID, int& aMeal, int& cMeal, char& mType, char& weekDayorEnd, float& prePayment, ifstream& introData, ofstream& errorData, bool& isDataGood) { 

  introData >> groupID >> aMeal >> cMeal >> mType >> weekDayorEnd >> prePayment;

  //cout << groupID << ' ' << aMeal << ' ' << ' ' << cMeal << ' ' << mType << ' ' << weekDayorEnd << ' ' << prePayment << '\n'; //test
  
  if (aMeal < 0 || cMeal < 0 || mType != 'S' &&/*tried || but that just created a big error*/ mType != 'D' || weekDayorEnd != 'Y' && weekDayorEnd != 'N' || prePayment < 0) {
    
    isDataGood = false;
    
    if (!isDataGood) {
      
    errorData << "Group num:" << groupID << endl;
    errorData << "Adult meals:" << aMeal << '\n' << "Child meals:" << cMeal << '\n' << "Type of meal bought:" << mType << '\n' << "Weekend(Y|N):" << weekDayorEnd << '\n' << "Deposit amount:" << prePayment << "\n\n";
//why do you hurt us with all these if statements
        if (aMeal < 0) {
        errorData << "Invalid number of adults\nHas to be equal to 0 or more\n\n";
        }
        else if (cMeal < 0) {
        errorData << "Invalid number of children/snot_goblins\nHas to be 0 or more\n\n";
      }
        else if (mType != 'D' && mType != 'S') {
        errorData << "Invalid meal type\n Has to be S or D\n\n";
      }
        else if (weekDayorEnd != 'Y' && weekDayorEnd != 'N') {
        errorData << "IT'S JUST Y OR N\nHOW DID YOU MESS THAT UP\n\n";
      }
        else if (prePayment < 0) {
        errorData << "Invalid amount depositted\nHas to be 0 or greater\n\n";
      }
    
    }//if bool == false
  
  }//big if statement
  //isDataGood = true;
}//function end

//meal cost function
float mealTotal (int aMeal, int cMeal, char mType) {
  float Total;
  const float aMealD = 25.80;
  const float aMealS = 21.75;
  //const float cMealD = 25.80 * .6;
  //const float cMealS = 21.75 * .6;
  const float cMealD = 15.48;
  const float cMealS = 13.05;
  // is that what you wanted?
  
  if (mType == 'D') {
    Total = aMeal * aMealD + cMeal * cMealD;
  }
  else if ( mType == 'S') {
    Total = cMeal * cMealS + aMeal * aMealS;
  }
  
  return Total;
  
}

//TotalwTaxnSur
void TotalwTaxnSur (float Total, char weekDayorEnd, float& TotalwTax, float& TotalwSurcharge, float& TotalnWhole, float& Tax, float& Surcharge, float& prePayment) {
  float totalwTax = Total;
  Tax = 0;
  Surcharge = 0;
  TotalnWhole = 0;
  const float tax = .18;
  const float surcharge = .07;
  
  Tax = Total * tax;

  totalwTax = Total + Tax;

  if (weekDayorEnd == 'Y') {
    Surcharge = totalwTax * surcharge;
  }
  TotalnWhole = Total + Tax + Surcharge - prePayment;
}

//output bill
void receipt (int groupID, int aMeal, int cMeal, char mType, char weekDayorEnd, float Total, float Tax, float Surcharge, float prePayment, float TotalnWhole) {

  cout << "Group num #" << groupID << endl;
  cout << "Number of adults in group " << aMeal << endl;
  cout << "Number of childern in group " << cMeal << endl;
  cout << "Type of meal Standard or Deluxe (S|D): " << mType << endl;
  cout << "Weekend (Y|N): " << weekDayorEnd << endl;
  cout << "Total amount: " << fixed << showpoint << setprecision(2) << Total << endl;
  cout << "Early deposit: " << fixed << showpoint << setprecision(2) << prePayment << endl;
  cout << "Tax and FORCED tip: " << fixed << showpoint << setprecision(2) << Tax << endl;
  cout << "Surcharge if aplicable: " << fixed << showpoint << setprecision(2) << Surcharge << endl;
  cout << "Total left to pay: " << fixed << showpoint << setprecision(2) << TotalnWhole << endl << endl << endl;
  
}

/*
output

 make -s
 ./main
Group num #1
Number of adults in group 10
Number of childern in group 0
Type of meal Standard or Deluxe (S|D): S
Weekend (Y|N): Y
Total amount: 217.50
Early deposit: 100.00
Tax and FORCED tip: 39.15
Surcharge if aplicable: 17.97
Total left to pay: 174.62


Group num #2
Number of adults in group 27
Number of childern in group 3
Type of meal Standard or Deluxe (S|D): D
Weekend (Y|N): Y
Total amount: 743.04
Early deposit: 57.50
Tax and FORCED tip: 133.75
Surcharge if aplicable: 61.38
Total left to pay: 880.66


Group num #3
Number of adults in group 125
Number of childern in group 17
Type of meal Standard or Deluxe (S|D): D
Weekend (Y|N): N
Total amount: 3488.16
Early deposit: 0.00
Tax and FORCED tip: 627.87
Surcharge if aplicable: 0.00
Total left to pay: 4116.03


Group num #4
Number of adults in group 4
Number of childern in group 0
Type of meal Standard or Deluxe (S|D): S
Weekend (Y|N): N
Total amount: 87.00
Early deposit: 25.00
Tax and FORCED tip: 15.66
Surcharge if aplicable: 0.00
Total left to pay: 77.66


Group num #5
Number of adults in group 0
Number of childern in group 25
Type of meal Standard or Deluxe (S|D): S
Weekend (Y|N): Y
Total amount: 326.25
Early deposit: 23.75
Tax and FORCED tip: 58.73
Surcharge if aplicable: 26.95
Total left to pay: 388.17


Group num #6
Number of adults in group 250
Number of childern in group 43
Type of meal Standard or Deluxe (S|D): D
Weekend (Y|N): N
Total amount: 7115.64
Early deposit: 500.00
Tax and FORCED tip: 1280.82
Surcharge if aplicable: 0.00
Total left to pay: 7896.46


Group num #7
Number of adults in group 0
Number of childern in group 0
Type of meal Standard or Deluxe (S|D): D
Weekend (Y|N): N
Total amount: 0.00
Early deposit: 0.00
Tax and FORCED tip: 0.00
Surcharge if aplicable: 0.00
Total left to pay: 0.00


Group num #10
Number of adults in group 5
Number of childern in group 0
Type of meal Standard or Deluxe (S|D): D
Weekend (Y|N): Y
Total amount: 129.00
Early deposit: 275.00
Tax and FORCED tip: 23.22
Surcharge if aplicable: 10.66
Total left to pay: -112.12

*/

/*
error data

Group num:8
Adult meals:10
Child meals:0
Type of meal bought:R
Weekend(Y|N):Y
Deposit amount:10

Invalid meal type
 Has to be S or D

Group num:9
Adult meals:17
Child meals:3
Type of meal bought:D
Weekend(Y|N):R
Deposit amount:15

IT'S JUST Y OR N
HOW DID YOU MESS THAT UP

Group num:11
Adult meals:-3
Child meals:10
Type of meal bought:D
Weekend(Y|N):Y
Deposit amount:20

Invalid number of adults
Has to be equal to 0 or more

Group num:12
Adult meals:14
Child meals:-1
Type of meal bought:S
Weekend(Y|N):N
Deposit amount:30

Invalid number of children/snot_goblins
Has to be 0 or more

Group num:13
Adult meals:20
Child meals:3
Type of meal bought:D
Weekend(Y|N):Y
Deposit amount:-10

Invalid amount depositted
Has to be 0 or greater

*/