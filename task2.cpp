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
    string** pool;    // Dynamic array of string pointers
    int currentSize;  // Current number of strings in pool
    int maxSize;      // Maximum size of pool

public:
    // Constructor
    StringPool() {
        maxSize = 5;
        currentSize = 0;
        pool = new string*[maxSize];
        for (int i = 0; i < maxSize; i++) {
            pool[i] = nullptr;
        }
    }

    // Destructor to clean up all allocated memory
    ~StringPool() {
        for (int i = 0; i < maxSize; i++) {
            if (pool[i] != nullptr) {
                delete pool[i];
                pool[i] = nullptr;
            }
        }
        delete[] pool;
    }

    // Method to add a string to the pool
    void addString(string str) {
        if (currentSize < maxSize) {
            pool[currentSize] = new string(str);
            cout << "Added: \"" << *pool[currentSize] << "\" at index " << currentSize << endl;
            currentSize++;
        } else {
            cout << "Pool is full! Cannot add \"" << str << "\"" << endl;
        }
    }

    // Removes reference without freeing memory (creates a memory leak)
    void removeString(int index) {
        if (index >= 0 && index < currentSize) {
            cout << "[LEAK CREATED] Removed reference at index " << index 
                 << " (\"" << *pool[index] << "\") WITHOUT deleting memory!" << endl;
            
            // Shift pointers left without deleting pool[index]
            for (int i = index; i < currentSize - 1; i++) {
                pool[i] = pool[i + 1];
            }
            pool[currentSize - 1] = nullptr; // important: original string memory still leaked in heap!
            currentSize--;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    // Safely removes element and frees memory to prevent leak
    void safeRemoveString(int index) {
        if (index >= 0 && index < currentSize) {
            cout << "[MEMORY FREED] Safely deleted string \"" << *pool[index] 
                 << "\" at index " << index << endl;
            delete pool[index]; // Free memory
            
            // Shift pointers left
            for (int i = index; i < currentSize - 1; i++) {
                pool[i] = pool[i + 1];
            }
            pool[currentSize - 1] = nullptr;
            currentSize--;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    // Display current contents of the pool
    void display() {
        cout << "\n--- Current Strings in Pool (" << currentSize << "/" << maxSize << ") ---" << endl;
        if (currentSize == 0) {
            cout << "Pool is empty." << endl;
        } else {
            for (int i = 0; i < currentSize; i++) {
                if (pool[i] != nullptr) {
                    cout << "Index " << i << ": " << *pool[i] << endl;
                }
            }
        }
        cout << "-------------------------------------------\n" << endl;
    }
};

int main() {
    StringPool myPool;

    cout << "=== 1. Adding Strings ===" << endl;
    myPool.addString("Apple");
    myPool.addString("Banana");
    myPool.addString("Cherry");
    myPool.display();

    cout << "=== 2. Removing String (Demonstrating Memory Leak) ===" << endl;
    myPool.removeString(1); // Removes "Banana" without deleting heap memory
    myPool.display();

    cout << "=== 3. Safely Removing String (Fixing Memory Leaks) ===" << endl;
    myPool.safeRemoveString(0); //  deletes "Apple"
    myPool.display();

    return 0;
}