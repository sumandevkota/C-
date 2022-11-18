#include <iostream>
#include<time.h>


using namespace std;

/*Functions definations are under the main program
these are the functions used to Create another pokemon game that involves array*/
void display_array( int array[]);
int search_pokemon();
bool New_Pokemon(int creation);
bool Sense_Pokemon(int Room_no,int rooms[]);

const int Room = 5; //total number of rooms
int main()
{ 
    srand(time(0));
    int pokemon_caught = 0;
    string MY_Pokemon = "Voltorb";
    int Pokemon_creation = 4;
    int rooms[Room] = {0,0,0,0,0}; //initiallizing all room with the value of 0 at first
    srand(time(0));
    int x = rand() % 5;  // generating random number to place pokemon initially in random room
    rooms[x] = 1;        // assinging random room to place a pokemon 
    int Room_no;         // variable to store room number given by the user
    
    
   
    //display_array(rooms);  // checking to see if the room is randomly choosen for pokemon to place
    /*total numbers of turns any players can get is 10.
    Therefore here I am using for loop to give each player 10 turns by looping 10 times*/
    for(int i = 0;i<10;i++){
        Room_no = search_pokemon();
      //  cout<<Room_no; // line of code used for debugging
      if(New_Pokemon(Pokemon_creation)){
          cout<<"Another "<<MY_Pokemon<<" has arrived!!"<<endl;
          srand(time(0));
          int random = rand()%5;
          rooms[random] += 1;
           //display_array(rooms); // checking to see which was the random room 
          }
          if(rooms[Room_no] == 0) {
              cout << "There are no " + MY_Pokemon +  " in that room ..." << endl;
              if(Sense_Pokemon(Room_no,rooms)){
                  cout << "You sense a " + MY_Pokemon + " in an adjacent room!" << endl;
              }
          }
          else {
            int numberofPokemons = rooms[Room_no];
            pokemon_caught += numberofPokemons;
            cout << "You found " << numberofPokemons << " in that room ..." << endl;
            rooms[Room_no] = 0;
            //display_array(rooms); //line of code to check what is happening inside room
          }
       
    }
    //display_array(rooms); //line of code to check what is happening inside room
    cout << "You found " << pokemon_caught   << " total Pokemons!" << endl;
}

/*Function here displays either 0 or 1 
if there is pokemon inside the room it displays 1 else displays 0
this function was created to debugg the program and make writting code easier*/
void display_array( int array[]){
    int i;
    for(i=0;i<Room;i++)
    {
        cout<<array[i]<<" ";
    }
    
}


/* search_Pokemon will search the room provided by the user and outputs if there was any pokemon in that Room
it takes room no as an argument it also keeps prompting until user gives correct room no as input*/
int search_pokemon(){
    int no;
    cout << "Enter a Room number to search:";
    
    cin >> no;
    while(no < 0 || no > 4 ) {
       cout << "That is not a legal room number.Try number from[0-4]:";
       cin >> no;
    }
    return no;
}

/**New_Pokemon function randomly creates a new pokemon it takes creation integer of pokemon as argument
the creation of my pokemon is 4 so if randomly generated number is less than 4 there is a new pokemon created*/
bool New_Pokemon(int creation){
    if ((rand() % 10) < creation){
        return true; 
    }
    return false;
    
}

/*Sense_Pokemon takes room number and whole array of rooms as an argument and checks if there is any pokemon 
adjecent to the room number provided by the user*/
bool Sense_Pokemon(int Room_no,int rooms[]){
    if (Room_no != 0 && rooms[Room_no - 1 ] != 0)
    {
        return true;
    }
    if (Room_no != 4 && rooms[Room_no + 1 ] != 0){
        return true;
    }
    return false;
}