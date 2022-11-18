//Suman Devkota
//Assingnment 2, problem 4
/*
There was two new features added to the existing program uploaded in the blackboard
the program displays the total number of courses registered by looping through the array and computing totalcourse
the duplication of the course that could be added in different time was prevented 
using a search algorithm that finds and matches if there have been any repeation of the course
*/
#include <iostream>
using namespace std;
const int SIZE = 12;
const int START = 800;

int getTime();
void add(int[]);
void display(int[]);
bool find(int schedule[], int key);

// This program maintains a daily schedule of courses.
// Users may add a new course to the schedule and view all courses.
// TImes are represented in military format from 800 to 1900 (12 times).
// Internally, times with no courses are represented as 0.
int main() {
    char choice;

    // Declare array and initialize all elements to 0 (no course).
    int schedule[SIZE];
    for (int index = 0; index < SIZE; index++) {
        schedule[index] = 0;
    }

    // Initially we just loop forever. This will be upgraded to allow a quit option.
    // We will also add an option to allow courses to be dropped.
    while (true) {
        cout << "Add course (a) or View courses (v): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                add(schedule);
                break;
            case 'v':
                display(schedule);
                break;
            default:
                cout << "That is not a legal option." << endl;
        }
    }
}
//this function helps to find the course
bool find(int schedule[], int key) { 
    for(int i = 0; i < SIZE; i++) {
        if(schedule[i] == key) {
            return true;
        }
    }
    return false;
}
// This prompts for a course number to add and a time to add it.
void add(int schedule[]) {
    int course, time;
    cout << "Enter course to add: ";
    cin >> course;
    if(!find(schedule,course)) { //condition is true only if not registered for the course
        time = getTime();
         // Validate time entered
        if (time < 0 || time >= SIZE) {
           cout << "Not a legal time!" << endl;
        }
        else {
            schedule[time] = course;
        }   
    }
    else {
        cout << "You are already registered for that course" << endl;
    }
}

// Display all courses in schedule.
void display(int schedule[]) {
  int totalCourses = 0;

    for (int index = 0; index < SIZE; index++) {
        // Translate index to time for printing
        cout << index * 100 + START << ": ";
        // Only print value if course exists (that is, not 0)
        if (schedule[index] != 0) {
            cout << schedule[index];
        }
        if(schedule[index] != NULL) {
            totalCourses++; //count all cources excepts null
        }
        cout << endl;   
    }
    //displaying the total number of course taken
    cout << "You are currently taking " <<  totalCourses << " courses" << endl;
}

// Translate military time into array index
int getTime() {
    int time;
    cout << "Enter time: ";
    cin >> time;
    return (time - START)/100;
}
