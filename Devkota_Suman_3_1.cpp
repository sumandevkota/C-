//Suman Devkota
//Assingment: 3, problem 1

/*this program prompts user to enter their name and prompts accordingly depending on how they entered it
--------------------------------------------------------------------------------------------------------
if user enters first_name it prints "first_name, just first_name"
if user enters first_name last_name it prints "last_name, first_name last_name"
if user enters first_name middle_name last_name it prints "last_name, first_name middle_name last_name"
--------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <string>

using namespace std;
/*Function to count number of spaces in the string */
int number_of_spaces(string str);

int main()
{
    
string name,first_name,last_name,middle_and_last_name;
int length,y,index,length_1;

cout<<"Enter you name: ";
getline(cin,name);                      //getlinr() takes all the string after space too
y = number_of_spaces(name);            //calling a function to determine number of spaces on given string

//Branching program based on number of spaces
if (y == 0){
    cout<<name<<",just "<<name;
}
else if (y == 1){
    index = name.find(" ");                       //finding the index of the space to make substring  
    //first_name = name.substr(0,index);         //extracting first name from the given full name
    //cout<<first_name<<endl;                       
    last_name = name.substr(index +1 ,length);   //extracting last name from the given full name
    cout<<last_name<<", "<<name;
}
else{
    index = name.find(" ");
    middle_and_last_name = name.substr(index + 1,length);  //extrating middle and last name from given full name
    //cout<<middle_and_last_name<<endl;     
    index = middle_and_last_name.find(" ");                //finding the index of the space to make substring  
    length_1 = middle_and_last_name.size();                //finding the length of the substring made  
    //cout<<length_1<<endl;
    //cout<<length_1<<endl;
    //cout<<index<<endl;
    last_name = middle_and_last_name.substr(index + 1,length_1); //extracting last name from the given full name
    cout<<endl;
    cout<<last_name<<", "<<name;
}
return 0;
}
/*The function returns the integer representating number of spaces in the provided string
it takes string as an argument or parameter */
int number_of_spaces(string str){
    int count = 0;
    for(int i=0;i< str.size() ;i++){
        if(str.at(i) == ' '){
            count++;
        }
    }
    return count;
}
