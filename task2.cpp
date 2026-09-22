/*
 * Course: CS-250 Data Structures and Algorithms
 * Task: Handling Dangling Pointers & Memory Leaks
 * Author: Laraib Fatima
 * Date: 22-09-2026
 */

#include <iostream>
#include <string>

using namespace std;


class StringPool {
private:
    string* pool;    // Pointer to dynamic array
    int capacity;    // Maximum capacity of the array
    int currentCount;// Number of strings currently stored

public:
    
    StringPool() {
        capacity = 5;
        currentCount = 0;
        pool = new string[capacity]; 
    }

    // Destructor
    ~StringPool() {
        delete[] pool;
    }

    // Function to add a string to the pool
    void addString(string str) {
        if (currentCount < capacity) {
            pool[currentCount] = str;
            currentCount++;
            cout << "Added: \"" << str << "\"" << endl;
        } else {
            cout << "Pool is full! Cannot add \"" << str << "\"" << endl;
        }
    }

    // Removing a string without clearing memory 
    void removeString(int index) {
        if (index >= 0 && index < currentCount) {
            cout << "Removing element at index " << index << ": \"" << pool[index] << "\"" << endl;
            
            // Shift elements to the left
            for (int i = index; i < currentCount - 1; i++) {
                pool[i] = pool[i + 1];
            }
            currentCount--; 
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    // Function to print current strings
    void display() {
        cout << "\n Current Strings in Pool " << endl;
        if (currentCount == 0) {
            cout << "Pool is empty." << endl;
        } else {
            for (int i = 0; i < currentCount; i++) {
                cout << "Index " << i << ": " << pool[i] << endl;
            }
        }
        cout << "-------------------------------\n" << endl;
    }

    // Function to safely clear and reset dynamic memory
    void fixAndCleanMemory() {
        delete[] pool;               // Freee array
        pool = new string[capacity]; // Allocate a fresh clean array
        currentCount = 0;
        cout << "Memory safely freed and pool reset!" << endl;
    }
};

int main() {
    StringPool myPool;

    //  Add strings to dynamic memory
    cout << " Adding Strings " << endl;
    myPool.addString("Apple");
    myPool.addString("Banana");
    myPool.addString("Cherry");
    myPool.display();

    //  Remove a string 
    cout << " Removing String " << endl;
    myPool.removeString(1); 
    myPool.display();

    //  Clean up dynamic memory
    cout << " Cleaning Memory " << endl;
    myPool.fixAndCleanMemory();
    myPool.display();

    return 0;
}