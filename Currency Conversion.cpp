#include <iostream>
using namespace std;
int main()
{
    double USA;         //variable that saves amount in USD
    double Nepal;       //variable that saves amount in Nepali Currency
    const double R = 127.84;
    
    
    
    cout << "This program changes USD into Nepali Currency!!\n";
    cout <<"Enter the amount in dollar: ";
    cin >> USA;          // Taking input from the user 
    Nepal = R * USA;    // Performing the conversion using arithmetic operator (Multiply)
    
    
    cout <<"The amount in Nepali Currency is: "<< Nepal <<" Nepali Rupeese";
    
    
}