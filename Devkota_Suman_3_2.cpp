//Suman Devkota
//Assingment: 3, problem 2
/*
Here the program
1.	Prompts the user for a city.
2.	Reads through the file until that city is found.
3.	Prints the corresponding zip code

*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    string city,search,zipcode,citystring;
    int index;
    ifstream fin;                          // Stream to read from a file
    bool isfound = false;
   // bool cityfound=false;
    cout<<"What city would you like the zip code for : "<<endl;
    getline(cin,city);
    fin.open("zipcodes.txt");
    if (!fin){
        cout<<"The file was not opened!!"<<endl;
    }
    else{
        /* While loop here scans each and every line in the file until it reaches end of the line
        on every line scan it is determining the index of the ':' and creating a substring to check if that is the match to what user entered
        if the city entered by users matches is again uses sub string function to prompt the zip code of that particular city */
    while(!fin.eof()){
        search = "";
    
        //cout<<"file was successfully opened!!!!"<<endl;
           //cout<<search<<endl;
            getline(fin,search,'\n');
            index = search.find(":");
            //cout<<"Index is: "<<index;
            citystring = search.substr(0,index);
           // cityfound = search.find(city);
           
            //cout<<cityfound;
            if(citystring == city){
                
                if(index){
                    isfound = true;
                     zipcode = search.substr(index + 1,search.length());
                     cout<<"The zipcode for "<<city<<" is "<<zipcode;
                     break;
                    }
            }   
            
        }
        if(!isfound){
            cout<<"That city is not in our database"<<endl;
        }
    }
    fin.close();
    return 0;
}
