//Suman Devkota
//Assingment 2, problem 6
#include <iostream>
#include<time.h>
#include<random>
const int column = 5; // size of the column  of multi-dimensional array
const int row = 5;    // size of the row  of multi-dimensional array
using namespace std;

/*These are the functions used in the program
defination for each of them are after the main program*/
void display_array(int rooms[row][column]);
int random(int x);
bool New_Pokemon(int x);
int *Search_Pokemon(int room[]);
bool Sense_Pokemon(int row, int column,int rooms[][5]);


int main(){
    srand(time(0));
    string MY_Pokemon = "Voltorb";
    int Pokemon_creation = 4;
    int rooms[row][column];
    int pokemon_caught = 0;
    //cout<<"I am here"<<endl; // line for debugging
    //Initially setting all rooms to zero
    for(int i = 0; i< row; i++)
    {

        for(int j = 0; j < column; j++)
        {
            rooms[i][j]=0;
        }
    }

   // display_array(rooms); //used for debugging purpose
   /*generating random number for row and column
   and placing first pokemon randomly*/
    int random_col=random(5);
    int random_row=random(5);
    rooms[random_row][random_col] = 1;
    //cout<<"---------"<<endl; // printed to debug the program
    //display_array(rooms); // to see where the pokemon is randomly placed

    //cout<<"I am here now"<<endl; // line for debugginh purpose
    /*No of turns each player gets is 10
    here for loop has been used to loop 10 times which will give player to input 10 times*/
    for (int t=0;t<10;t++) {
        int row,col;
        int *in;
        int userinput[2];
        in = Search_Pokemon(userinput);
        row = in[0];
        col = in[1];
        /*If statement is implemented if randomly generated number is less than pokemon creation
        and prompts user acknowledging that new pokemon has arrived
        Also it randomly places the new pokemon in random room*/
        if(New_Pokemon(Pokemon_creation)) {
            cout << "Another " << MY_Pokemon << " has arrived!!!" << endl;
            int rrow = random(5);
            int rcolumn = random(5);
            rooms[rrow][rcolumn] += 1;   
            //display_array(rooms); // to see where the new pokemon is randomly placed
        }   
    /*if statement here checks if there is any pokemon in the room that user entered*/
        if(rooms[row][col] == 0) {
            cout << "There are no " << MY_Pokemon <<  " in that room .." << endl;  
            if(Sense_Pokemon(row, col,rooms)) {
                cout << "You sense a " << MY_Pokemon << "in an adjacent room!" << endl;
            }
        }
        
        else {
            int totalpokemon = rooms[row][col];
            pokemon_caught = totalpokemon;
            cout << "You found " << totalpokemon << " in that room ..." << endl;
        }
    }
    cout << "You found " << pokemon_caught << " total Pokemons!" << endl;
    }

//Functions Definations
/*Function here displays either 0 or 1 in all rooms
if there is pokemon inside the room it displays 1 else displays 0
this function was created to debugg the program and make writting code easier*/
void display_array(int rooms[row][column]){
    for(int i = 0; i < row ; i++) {
        for(int j = 0; j < column; j++) {
            cout << rooms[i][j] << " ";
        }
        cout << endl;
    }

}

/* This function returns random number less than the limit
it takes limit as the argument*/
int random(int x){
    return rand() % x;
}


/*this function takes an array as an argument and prompts user to input the room number
it also tells user if the number they gives as a input are legal or not
it returns the room index given by the user*/
int * Search_Pokemon(int room[]) {
    cout << "What room do you want to search:" << endl;
    cout << "Enter row and column with a space:";
    int row, column;
    cin >> row;
    cin >> column;
    while((row < 0 || row > 4) || (column < 0 || column > 4) ) {
       cout << "That is not a legal room number. Try again:";
       cin >> row >> column;
    }
    room[0] = row;
    room[1] = column;
    return room;
}
/*this function here is used to see if new pokemon is created
it takes pokemon creation as a an argument and returns
true or false based on the fact if randomly generated number is less than pokemon creation
implying that new pokemon is created or not*/
bool New_Pokemon(int x){
    if(random(10) < x){
        return true;
    }
    return false;
}
/*this function here takes row and column index as well as array as an argument
and checks if there are any pokemons in the adjecent room*/
//Aniket helped me with this one 
bool Sense_Pokemon(int row, int col,int arr[][5]){
    if(row != 0 && arr[row-1][col] != 0) {
        return true;
    }
    if(col != 0 && arr[row][col-1] != 0) {
        return true;
    }
    if(col != 4 && arr[row][col+1] != 0) {
        return true;
    }
    if(row != 4 && arr[row+1][col] != 0) {
        return true;
    }
    return false;
}
