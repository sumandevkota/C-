// Suman Devkota
// Assingment: 1, Problem 2 



// the program here initally had two bugs 
// first bug was inside the condition of for Loop
// when user wanted to enter n values loop used to execute for n+1 
//Asking user to input one more number than what they were expecting
// the bug has been fixed by re-writting that particular line of code 

// another bug here was inside for loop in condition of if statement
// the condition was set to give wrong value of negative numbers and was also counting 'Zero' as negative number
// which is again fixed by re-writting the condition of if statement



#include <iostream>
using namespace std;

// This program counts the number of negative values entered by the user.
int main() {
    int howMany;               // How many numbers will be input
    int inputValue;            // Current number input by user
    int numberOfNegatives = 0; // Running total of negative numbers

    // Prompt for how many values will be entered
    cout << "How many values will you input: ";
    cin >> howMany;

    // Loop for that many numbers
    //for (int count = 0; count <= howMany; count++) // the condition here was adding one more input value
    for (int count = 0; count < howMany; count++)     // the bug here was fixed by replacing '<=' by "<" only
    {
        cout << "Enter next value: ";
        cin >> inputValue;

        // If positive increment total
        //if (inputValue <= 0)          // The bug in the program was counting 0 as negative number
        if (inputValue < 0)             // The bug was fixed by replacing '<=' by '=' only
        {
            numberOfNegatives++;
        }
    }

    cout << "You entered " << numberOfNegatives << " negative numbers" << endl;

    return 0;
}
