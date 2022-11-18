//Suman Devkota
//Assingment 2, problem 3

#include <iostream>
#include <time.h>
using namespace std;

int case_net(int speed);
int case_freez(int strength);
char pokemon_attack();

int main()
{
    int x;
    int total = 0;
    char p;
    int ret; 
    for(int i=1; i<=11;i++)
        {    srand(time(0));
             x = rand() % 2; // random number generator that gives either 0 or 1
            // if else statement here displays which pokemon is seen based on number generated in above line
        //here 0 is Pikachu and 1 is Pangolin
        //cout<<"value of X "<<x <<endl;
       if(x == 0)
        {
            cout<<" You See a Pikachu! "<<endl;
            char p = pokemon_attack();
            if ( p == 'n')
            { // we are given the speed of Pikachu which is being passed as a argument in this function
                ret = case_net(8) ;
                total += ret;
            }
            else if (p == 'f')
            {// we are given the strength of Pikachu which is being passed as a argument in this function
                ret = case_freez(5);
                total += ret;
            }
            
         }
         else if ( x == 1)
         {
             cout<<"You see a Pangolin! "<<endl;
            
            char p = pokemon_attack();
            if ( p == 'n')
            { // we are given the speed of Pangolin which is being passed as a argument in this function
                ret = case_net(2) ;
                total += ret;
            }
            else if (p == 'f')
            {// we are given the strength of pangolin  which is being passed as a argument in this function
                ret = case_freez(7);
                total += ret;
            }
            
         }
         
        } 
        cout<<"Total pokemon Caught is "<< total;
}

/*function here is executed when user uses net as their attack strategy 
this function takes speed as its argument which is 8 for pikachu and 2 for pangolin
and returns 1 if pokemon is caught else returns 0*/
int case_net(int speed)
{
    int chance,y;
    chance = (10 - speed) * 10;
    srand(time(0));
    y = rand() % 100+1;
                    //the chance of getting caught with net is 20 % for Pikachu
                    //here i have related the probability with random number generator
                    //where if random number generates number less than 20 
                    //i assume that pokemon is caught if not pokemon Dodged
                    if(y < chance)
                        {
                            cout<<"The pokemon is caught in the net "<<endl;
                            return 1;
                        }
                    else
                        {
                         cout<<"The Pokemon Dodged the Net!"<<endl;
                         return 0;
                         
                        }
    
}

/*function here is executed when user uses Freez as their attack strategy 
this function takes strength as its argument which is 5 for pikachu and 7 for pangolin
and returns 1 if pokemon is caught else returns 0*/

int case_freez(int strength)
{
    int chance,total,y;
    chance = (10 - strength)*10; //calculating
    srand(time(0));
    y = rand() % 100+1;
    /* random number generated upto max number generated will be 100 
    the chance of getting caught with freez is 50 % for Pikachu
    here i have related the probability with random number generator
    where if random number generates number less than 50 
    i assume that pokemon is caught if not pokemon Dodged*/
                    
                    if(y < chance)                
                        {
                            cout<<"The pokemon is Frozen in place "<<endl;
                            return 1;
                        }
                    else
                        {
                         cout<<"The Pokemon broke free of ICE!"<<endl;
                         return 0;
                         
                        }
}

/*function here prompts for user to use net or freez as their attack strategy
it keeps prompting user until they input f (freez) or n (net) */
char pokemon_attack(){
    char attack;
            // do while loop keeps prompting user to input either n or f 
            // loop doesn't end until user enters the correct key which is either 'n' or 'f' 
            do{
                cout<<"Use a net (n) or a freeze ray (f): ";
                cin>>attack;
                
            }while(attack != 'n' and attack != 'f');
    return attack;
}