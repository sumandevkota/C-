// Suman Devkota
//Assingment 1, Problem 5

//Pokemon Game
// My Banner ID :Y00839274
// My two pokemon are Pikachu and Pangolin
// Pangolion strength = 7; speed = 2  
// Pikachu strength = 5; speed = 8
//Number of turns my user gets = ( 5 + 8 + 7 + 2 )/ 2 = 11
// the odds of catching Pangolin with net is 10 - 2(it's speed) = 8 >> 80 %
// the odd of catching Pikachu with net is 10 - 8(it's speed) = 2 >> 20%
// the odds of catching Pangolin with freeze ray is 10 - 7(it's strength) = 3 >> 30 %
// the odds of catching Pikachu with freeze ray is 10 - 5(it's strength) = 5 >> 50 %
//Here I have used random function to generate random numbers and linked it with the probability

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    char n,f,p;         // n and p are the character that user inputs and p is where it will be stored
    int x,y;           // x and y has been used as a variable that stores randomly generated integer between 1 and 100
    int total=0;       // total counts the total number of pokemon caught 
    
    //Since my user gets only 11 turns to play 
    // For loop here allows user to only input 11 times
for(int i=1; i<=11;i++)
    {
        
     x = rand() % 2;   // random number generator that gives either 0 or 1
     
     // if else statement here displays which pokemon is seen based on number generated in above line
     //here 0 is Pikachu and 1 is Pangolin
     if(x == 0)
        {
            cout<<" You See a Pikachu! "<<endl;
            
           // do while loop keeps prompting user to input either n or f
           // loop doesn't end until user enters the correct key which is either 'n' or 'f' 
            do{
                cout<<"Use a net (n) or a freeze ray (f): ";
                cin>>p;
            }while(p != 'n' and p != 'f');
            
            //if user decides to use net then our program gets inside this if statement
            if(p == 'n')
                {
                    //srand(time(0));
                    y = rand() % 100+1;   // random number generated upto max number generated will be 100 
                    //the chance of getting caught with net is 20 % for Pikachu
                    //here i have related the probability with random number generator
                    //where if random number generates number less than 20 
                    //i assume that pokemon is caught if not pokemon Dodged
                    if(y < 20)
                        {
                            cout<<"The pokemon is caught in the net "<<endl;
                            total++;   // once the pokemon is caught it is added to total
                        }
                    else
                        {
                         cout<<"The Pokemon Dodged the Net!"<<endl;
                         
                        }
            }
            //if user decides to enter f to use freez ray then our program brachnes to this path
            else if( p == 'f')
            {
                //srand(time(0));
                y = rand() % 100+1;// random number generated upto max number generated will be 100 
                    //the chance of getting caught with freez is 50 % for Pikachu
                    //here i have related the probability with random number generator
                    //where if random number generates number less than 50 
                    //i assume that pokemon is caught if not pokemon Dodged
                    if(y < 50)
                        {
                            cout<<"The pokemon is Frozen in place "<<endl;
                            total++;
                        }
                    else
                        {
                         cout<<"The Pokemon broke free of ICE!"<<endl;
                         
                        }
            }
        }    
     else if( x == 1)
        {
            cout<<"You see a Pangolin! "<<endl;
            
            // do while loop keeps prompting user to input either n or f
            // loop doesn't end until user enters the correct key which is either 'n' or 'f' 
            do{
                cout<<"Use a net (n) or a freeze ray (f): ";
                cin>>p;
            }while(p != 'n' and p != 'f');
            
            if(p == 'f')
                {
                    //srand(time(0));
                    y = rand() % 100+1;// random number generated upto max number generated will be 100 
                    //the chance of getting caught with freez is 30 % for Pangolin
                    //here i have related the probability with random number generator
                    //where if random number generates number less than 30 
                    //i assume that pokemon is Froze if not pokemon broke free the ICE
                    if(y < 30)
                        {
                            cout<<"The pokemon is frozen in place! "<<endl;
                            total++;
                        }
                    else
                        {
                         cout<<"The Pokemon broke free of ICE! "<<endl;
                         
                        }
            }
            else if( p == 'n')
            {
                //srand(time(0));
                y = rand() % 100+1;
                    //the chance of getting caught with net is 80 % for Pangolin
                    //here i have related the probability with random number generator
                    //where if random number generates number less than 80 
                    //i assume that pokemon is caught if not pokemon Dodged
                    if(y < 80)
                        {
                            cout<<"The pokemon is caught in the net "<<endl;
                            total++;      // addition of pokemon caught
                        }
                    else
                        {
                         cout<<"The Pokemon Dodged the Net!"<<endl;
                         
                        }
            }
        }  
    }
    cout<<"You Caught "<<total<<" Pokemon"<<endl; //displays total number of pokemon caught
 
}