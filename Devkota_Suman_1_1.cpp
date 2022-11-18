// Suman Devkota
// Assingment: 1, Problem: 1
// Line Slope

#include <iostream> // this header file contains functions that we are using in our program like cin,cout 
using namespace std;

// This program prompts for two points (x1,y1) and (x2,y2)
// and computes the slope of the line defined by those points.
int main() {             //  main() is the function where program starts
    int x1, x2, y1, y2; // defining integer variables to store coordinates values which are given by the user
    float slope;        // defining float variable because result from the formula can end up being non integer or float
    const int zero = 0;     // definibg a constant variable zero with a value of '0'
    // Prompt for coordinates of first point
    cout << "Enter x coordinate of first point: "; // Displays in the screen so that user can interact with the program and enter first coordinate of a first point
    cin >> x1;                                    // Stores the value entered by user into a variable x1 which is defined as integer
    cout << "Enter y coordinate of first point: ";// Displays in the screen so that user can interact with the program and enter Secord coordinate of first point
    cin >> y1;                                   // Stores the value entered by user into a variable y1 which is defined as integer

    // Prompt for coordinates of second point
    cout << "Enter x coordinate of second point: ";// Displays in the screen so that user can interact with the program and enter first coordinate of second point
    cin >> x2;                                     // Stores the value entered by user into a variable x2 which is defined as a integer
    cout << "Enter y coordinate of second point: ";// Displays in the screen so that user can interact with the program and enter Secord coordinate of second point
    cin >> y2;

    // Compute and print slope
    // the implementation of the formula here is not correct  
    // the arithmetic operation here frist divides y2 by x1 and then substract the result and x2 from y1
    // also program doesn't checks if the given line is parallel to x and y-axis
    // since the variable slope is float (y1-y2) and (x1-x2) must be float to get the correct output
    //slope = y1 - y2 / x1 - x2; 
    
    // The program has been fixed to get the correct output
    // Also, program checks if the given line is parallel to any of the axis
    
    
    if (x1-x2 == 0) // condition here checks if the x coordinate of the given points is same 
    {               // if the condition above matches it reveals that line is parallel to Y-axis
        cout<<"The given line is parallel to Y-axis"<<endl; // let's user know that given line doesn't have y-intercept and hence is parallel to Y-axis
        cout<<"The slope of the line cannot be determined ";   // Let's the user know that slope cannot be determined
    }
    
    else if (y1-y2 == 0) // condition here checks if the y-coordinate of the given points is same
    {                    // if the conditions is true it reveals that the line is parallel to X-axis
        cout<<"The given line is parallel to X-axis"<<endl; // let's the user know that the given line does't have X-intercept and hence is parallel to X-axis
        cout<<"The slope of the line is "<<zero<<endl;
    }
    
    else 
    {
    slope = float(y1-y2)/float(x1-x2); // the first bug here in the program was fixed by the use of parenthesis
                             // after adding parenthesis program computes (y1-y2) and (x1-x2)
                             //adding float in front of (y1-y2) and (x1-x2) makes the program computable for getting float division
                             // and divides the result from (y1-y2) by the result from (x1-x2)
                             // Which is exactly how we end up getting slope of a line from two coordinates
    cout << "The slope of line formed by those points is " << slope << endl;
    }
    return 0;
}
