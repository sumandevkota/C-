// Suman Devkota
//Assingment 2, problem 2


#include <iostream>
#include <cmath>
using namespace std;
/*
values in the functions were passed as a actual value because of which it was only affecting variable inside a functions
the simple way of fixing this problem is to pass a value using a pointer or passing value by reference
which will send the address instead of actual value.
I have fixed the problem by replacing & before variables which is used as a pointer to reference an address in the memory
*/
void pour(double &bucket1, double &bucket2, double &capacity, double amount);

int main() {
    double capacity1 = 5;
    double bucket1 = 4;
    double capacity2 = 3;
    double bucket2 = 1;

    cout << bucket1 << " gallons in bucket 1, " << bucket2 << " gallons in bucket 2" << endl;
    cout << "Going to pour 4 gallons from bucket 1 into bucket 2" << endl;
    pour(bucket1, bucket2, capacity2, 4);
    cout << bucket1 << " gallons now in bucket 1, " << bucket2 << " gallons now in bucket 2" << endl;

    return 0;
}

// This function pours an amount of water from one bucket to another.
//   bucket1: The amount of water in the bucket we are pouring from.
//   bucket2: The amount of water in the bucket we are pouring to.
//   capacity: The amount of water the bucket we are pouring into can hold.
//   amount: The amount of water we are attempting to pour.

void pour(double &bucket1, double &bucket2, double &capacity, double amount){
    // There is enough room in bucket 2 for all of the water we are pouring
    if (amount + bucket2 <= capacity) {
        bucket2 += amount;
        bucket1 -= amount;
    }
    // There is not enough room in bucket 2, so we just pour what will fit
    else {
        float poured = capacity - bucket2;
        bucket2 = capacity;
        bucket1 -= poured;
    }
}