// Suman Devkota
//Assingment 1, Problem 3



// The modified program can be tested by providing following sets of input 

// temperature < 50 prints "That is a cold temperature"
// temperature = 50 prints "That is a comfortable temperature"
// temperature = 79 prints "That is a comfortable temperature"
// temperature = 80 prints "That is a hot temperature" and prompts for Dewpoint 
// temperature > 80 prints "That is a hot temperature" and prompts for dewpoint 
        // Dewpoint = 50 program ends 
        // Dewpoint = 61 prints " It is uncomfortable today"


#include <iostream>
using namespace std;

// This program inputs a temperature and outputs how that temperature feels.
int main()             //  main() is the function where program starts
{
    float temperature; // Current temperature in Fahrenheit
    float dewpoint;    // stores dewpoint value as a float variable

    // Prompt for the temperature
    cout << "Enter the temperature in Fahrenheit: ";
    cin >> temperature;

    // Temperatures below 50 are cold, comfortable otherwise
    if (temperature < 50) {
        cout << "That is a cold temperature." << endl;
    }
    else if(temperature >= 80)                             // Else if statement has been added to modify the program 
                                                          // to print "That is a hot temperature" for temperatures of at least 80
    {
        cout<<"That is a hot temperature"<<endl;
        // Prompts User for Dewpoint
        cout<<"Please Enter the dewpoint: "<<endl; 
        cin>>dewpoint;
        if (dewpoint > 60)                             // if statement here checks if the dew point is greater than 60
                                                       // if true it prints "It is uncomfortable today"
        {
            cout<<"It is uncomfortable today"<<endl;
        }
    
        
    }
    else {
        cout << "That is a comfortable temperature." << endl;
    }
}