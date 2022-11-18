// Suman Devkota
//Assingment 1, Problem 4

#include <iostream>
using namespace std;

int main()
{
    int guess;
    int correct = 7 ;
    int count = 1;                          // variable to count number of guesses
    //prompt user to enter their guess
    cout <<"Enter a guess between 1 and 10: ";
    cin >> guess;
    
    while (guess != correct && count < 3)    // added another contidion to limit the number of guess to 3
    {
        cout<<"That was not correct. Guess again: ";
        cin>>guess;
        count = count + 1;                  // counting the number of guesses
        //cout<<"Count: "<<count<<endl;
        //cout<<guess<<endl;
    }

    if (guess == correct)                   // condition to print if guess was right
    {
        cout<<"That is correct!"<<endl;
    }
    else                                   // print when users is out of guesses
    {
        cout<<"You are out of guesses! "<<endl;
    }
}