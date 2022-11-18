/*Looks good*/

#include <iostream>
#include <fstream> 
#include <iomanip> 
#include <string>
using namespace std;

int main() {

ifstream testData;
ofstream dataOut;
int dataRead, leastVal, maxVal, currInput, i, row;
float lineAve, lineTotal; 
const int x = 0;
row = 0;
  
testData.open ("testData");
dataOut.open ("dataOut");
  
if (!testData.is_open()) {
  cout << "File could not be openned.\n";
  return 1;
} //If file can not be reached
testData >> dataRead; // catches the ocurring 0 each time.
//dataOut << dataRead << endl;

while (!testData.eof()) {
  
//resets values
leastVal = 0;
maxVal = 0;
lineAve = 0;
lineTotal = 0;

  row = row + 1;

  cout << "Row num " << row << endl;
  
 for (i = 0; i < 7; i++) {
    
    currInput = dataRead;

    cout << "Input " << i+1 << ": " << currInput << endl;
    dataOut << "Input " << i+1 << ": " << currInput << endl;
   
    if (maxVal == 0){
      maxVal = currInput;
    }         

     else if (currInput > maxVal) {

     maxVal = currInput;
       }

    if (leastVal == 0){
      leastVal = currInput;
    }

    else if (leastVal > currInput){
      leastVal = currInput;
    }

    testData >> dataRead;
   
   lineTotal = lineTotal + currInput;

  } //forloop

  lineAve = lineTotal / i;
  
   cout << endl << "Max of current line is " << maxVal << endl;
  
     dataOut << endl << "Max of current line is " << maxVal << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////
   cout << "Lowest input of current line is " << leastVal << endl;

     dataOut << "Lowest input of current line is " << leastVal << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////
  cout << "Line total is " << static_cast<int>(lineTotal) << endl << "Line average is " << fixed << showpoint << setprecision(2) << lineAve << endl << endl;

  dataOut << "Line total is " << static_cast<int>(lineTotal) << endl << "Line average is " << fixed << showpoint << setprecision(2) << lineAve << endl << endl;//lineTotal << '\n' << lie << "\n \n"
}
  
  
cout << "File read has ended\n" << "Closing file "<< '"' << "testData" << '"' << '\n';
  
testData.close();
dataOut.close();

  /*
Input 1: 346
Input 2: 130
Input 3: 982
Input 4: 90
Input 5: 656
Input 6: 117
Input 7: 595

Max of current line is 982
Lowest input of current line is 90
Line total is 2916
Line average is 416.57

Input 1: 415
Input 2: 948
Input 3: 126
Input 4: 4
Input 5: 558
Input 6: 571
Input 7: 87

Max of current line is 948
Lowest input of current line is 4
Line total is 2709
Line average is 387.00

Input 1: 42
Input 2: 360
Input 3: 412
Input 4: 721
Input 5: 463
Input 6: 47
Input 7: 119

Max of current line is 721
Lowest input of current line is 42
Line total is 2164
Line average is 309.14

Input 1: 441
Input 2: 190
Input 3: 985
Input 4: 214
Input 5: 509
Input 6: 2
Input 7: 571

Max of current line is 985
Lowest input of current line is 2
Line total is 2912
Line average is 416.00

Input 1: 77
Input 2: 81
Input 3: 681
Input 4: 651
Input 5: 995
Input 6: 93
Input 7: 74

Max of current line is 995
Lowest input of current line is 74
Line total is 2652
Line average is 378.86

Input 1: 310
Input 2: 9
Input 3: 995
Input 4: 561
Input 5: 92
Input 6: 14
Input 7: 288

Max of current line is 995
Lowest input of current line is 9
Line total is 2269
Line average is 324.14

Input 1: 466
Input 2: 664
Input 3: 892
Input 4: 8
Input 5: 766
Input 6: 34
Input 7: 639

Max of current line is 892
Lowest input of current line is 8
Line total is 3469
Line average is 495.57

Input 1: 151
Input 2: 64
Input 3: 98
Input 4: 813
Input 5: 67
Input 6: 834
Input 7: 369

Max of current line is 834
Lowest input of current line is 64
Line total is 2396
Line average is 342.29


  */
} // Main