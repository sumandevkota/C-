// Suman Devkota
// Assingment 2 , problem 1

/*The assingment on problem 1 was to test the between function by writting a simple main function as a function driver
initially function was not working as expected 
here I have combined the logical condition to make it work properly
I have also displayed what value function is returning whihc is either 1 or 0

Test cases
Assuming min = 1 and max = 10
val = -7  output = false
val = 0  output = false
val = 1  output = True
val = 5  output = True
val = 10  output = True
val = 50  output = False */

#include <iostream>

using namespace std;

bool between(double minval, double maxval, double value);
int main()
{
    //Just to check the function I am assuming that minimum and maximum value to be 1 and 10 respectively
     double min,max,val;
    //prompting a values to pass to a function minimum ,maximum and value
    cout<<"Enter the minimum for the range ";
    cin>>min;
    cout<<"Enter the maximum for the range ";
    cin>>max;
    
    cout << "Enter a number to check if it is between "<<min<<" and "<< max<<": " ;
    cin >> val;
    //checking if functions returns tru or false and displaying accordingly
    if (between(min,max,val)){
        
        cout<<"Value returned by Function "<<between(min,max,val)<<endl; //printting out the value returned by function
        cout << "Entered number lies between mim and max" << endl;
    }
    else{
        cout<<"Value returned by Function "<<between(min,max,val)<<endl; //printting out the value returned by function
        cout << "Entered number doesn't lies between mim and max" << endl;
    }
}

bool between(double minval, double maxval, double value) {
      if((value >= minval) && (value <= maxval))  
        return true;
      return false;
}