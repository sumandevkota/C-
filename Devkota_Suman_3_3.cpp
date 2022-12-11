//Suman Devkota
//Assingment: 3, problem 3 

/* Existing program was given and we are asked to add class Account, which stores the password and balance for the account
and provides methods to allow these to be assessed and manipulated*/

#include <iostream>
#include <string>
using namespace std;

/*Class Account here  have following constructors and methods 
1. Account() to set balance to 0 and password to "changeit"
2. Account(string opass,int bal) to set balance to bal and pass to pass
3. login(string p) to return true if password matches password
4. getBalance() to return the current balance
5. deposit(int amount) to increase the amount balance in Account
6. withdraw(int amount) to decrease the withdrawl amount from the actual balance
the class also has private variable to store account password and balance
*/
class Account {
    public:
    //constructor
    Account() {
        this->balance = 0;            //this ->  operator here is used to access private members
        this->password = "changeit";
    }
    //overloading constructor
    Account(string pass, int bal) {
        balance = bal;
        password = pass;
    }
    //method
    bool login(string p) {
        if( p == password){
            return true;
        }
        return false;
    }
    int getBalance() {
        return balance;
    }
    //method
    void deposit(int amount) {
        balance = balance + amount;
    }
    //method
    bool withdraw(int amount) {
        if(amount <= balance) {
            balance = balance - amount;
            return true;
        }
        return false;
    }
    
    private:
    int balance;
    string password;
};

int main() {
    int id;
    char choice;
    string password;
    int amount;

    // Create array of accounts and construct Account objects for each one.
    Account accounts[3];
    accounts[0] = Account("12345", 100);
    accounts[1] = Account("password", 500);
    accounts[2] = Account("xyzzy", 200);

    while (true) {
        // Get the user account number and make sure it exists
        cout << "Enter account number: ";
        cin >> id;
        while (id < 0 || id > 2) {
            cout << "Enter account number: ";
            cin >> id;
        }

        // Prompt for password
        cout << "Enter password for that account: ";
        cin >> password;

        // Ask that Account object to validate that password
        if (accounts[id].login(password)) {

            // Successful login, so present options until quit chosen
            cout << "Get balance (g), Deposit (d), Withdraw (w), or Quit (q): ";
            cin >> choice;
            while (choice != 'q') {
                switch (choice) {

                    // Call getBalance on object to view current balance
                    case 'g':
                        cout << "Your balance is: $" << accounts[id].getBalance() << endl;
                        break;

                    // Call deposit on object to increment amount in account
                    case 'd':
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        accounts[id].deposit(amount);
                        break;

                    // Call deposit on object to decrement amount in account
                    case 'w':
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        bool result = accounts[id].withdraw(amount);

                        // withdraw returns false if not enough money in account to withdraw that amount
                        if (!result) {
                            cout << "Can't withdraw that amount!" << endl;
                        }
                        break;
                }
                cout << "Get balance (g), Deposit (d), Withdraw (w), or Quit (q): ";
                cin >> choice;
            }
        }
        else {
            // Incorrect password for that Account object entered
            cout << "Incorrect password!" << endl;
        }
    }
}