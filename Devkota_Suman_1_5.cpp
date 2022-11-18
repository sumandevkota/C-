// Suman Devkota
//Assingment 1, Problem 5
#include <iostream>
using namespace std;

// This program totals integers from 1 to
// some value given by the user
int main()
{
    int total = 0; // Running total
    int limit; // Sum from 1 to this
   

    // Prompt for limit
    cout << "Enter the number to calculate the sum of sum: ";
    cin >> limit;

    // Loop from 1 to that limit (including limit)
    for (int count = 1; count <= limit; count++) {
        
        
        for (int j=1 ; j <= count;j++ )                                           // created a nested for loop to calculate sum of sum 
        {
            total = total + j;
         
        }
           cout<<"the sum of all numbers upto "<<count<<" is "<<total<<endl;
    }

    // Display result
   // cout << "The sum of all integers up to " << limit << " is " << total;
}