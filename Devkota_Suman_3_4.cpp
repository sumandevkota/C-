// Suman Devkota
//Assingmet: 3, problem 4

/*
With the success of previous pokemon games this time we are implementing C++ class for our game
to make program different we are assinged different pokemon based on our last y digit in my case it's 4 
therefore pokemon that i will be using today is "Voltorb" whose hunger rate it 3 and boredom rate is 7 
*/

#include <iostream>
#include <string>
using namespace std;

// creating Class Pokemon 
class Pokemon {
    public:
    Pokemon(string name) {
        this->name = name;
        hunger = 0;
        boredom = 0;
    }
    string getName() {
        return name;
    }
    int getHunger() {
        return hunger;
    }
    int getBoredom() {
        return boredom;
    }
    void currentValues() {
        cout <<"Hungry_level "<<hunger << " " <<"Bordome_level "<< boredom << endl;
    }
   
    void setHunger(int hunger) {
        this->hunger = hunger;
    }
    void setBoredom(int boredom) {
        this->boredom = boredom;
    }
    
    string currentFeeling() {
    string feeling;
        if((hunger + boredom) < 15 ) {
            feeling = "Happy";
        }
        else if(hunger > boredom) {
            feeling = "Hungry";
            if(hunger > 20) {
                feeling = "Very Hungry";
            }
        }
        else if(hunger < boredom) {
            feeling = "Bored";
            if(boredom > 20) {
                feeling = "Very Bored";
            }
        }
    return feeling;
    }
    private:
    string name;
    string feeling;
    int hunger;
    int boredom;
};


int main() {
    string name;
    char choice;
    int hunger_rate = 3;
    int boredom_rate = 7;
   
    

    // Prompt the player for the name of their character.
    cout << "You have a Voltorb!" << endl;
    cout << "What do you want to name it? ";
    cin >> name;

    // Construct an object for that character
    Pokemon p(name);

    while (true) {

        // Print how their character is feeling (happy, hungry, bored, etc.)
        //p.currentValues();//uncomment this section for debugging purpose
        cout<<name<<" is "<<p.currentFeeling()<<endl;
        
        // Prompt the player for whether they want to feed or play with their character
        cout << "Do you want to feed (f) or play with (p) " << p.getName() << "? ";
        cin >> choice;
        // (looping until they give a legal answer)
        while (choice != 'f' && choice != 'p') {
            cout << "Please enter f or p: ";
            cin >> choice;
        }
        switch (choice) {
            case 'f':{
                // Feed the character
                int hungry = p.getHunger();
                if((hungry -15)<0){
                    p.setHunger(0);
                }
                else{
                    hungry = hungry - 15;
                    p.setHunger(hungry);
                }
                //p.currentValues();//uncomment this section for debugging purpose

                break;
            }
            case 'p':{
                // Play with the character
                int bore = p.getBoredom();
                if((bore -15)<0){
                    p.setBoredom(0);
                }
                else {
                    bore = bore - 15;
                    p.setBoredom(bore);
                }

              // p.currentValues();//uncomment this section for debugging purpose
                break;
        }
    }
        // Increase the hunger and boredom levels by the rates for your
        // specific type of Pokemon.
        
        if (choice == 'f'){
        int bore = p.getBoredom();
        bore = bore + boredom_rate;
        p.setBoredom(bore);
            
        }
        else if(choice == 'p'){
          int hungry = p.getHunger();
          hungry = hungry + hunger_rate;
          p.setHunger(hungry);
            
        }

    }
    return 0;
}