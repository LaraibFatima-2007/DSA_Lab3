/*
 * Course: CS-250 Data Structures and Algorithms
 * Task: Strings in C++ (Palindrome Checker)
 * Author: Laraib Fatima
 * Date: 22-09-2026
 */

#include <iostream>
#include <string>

using namespace std;

// Function to convert uppercase letters (A-Z) to lowercase (a-z)
char makeLowercase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32; // In ASCII, adding 32 converts Capital alphabet to small 
    }
    return ch;
}

// Function to check if a character is a letter or number
bool isLetterOrDigit(char ch) {
    if ((ch >= 'a' && ch <= 'z') || 
        (ch >= 'A' && ch <= 'Z') || 
        (ch >= '0' && ch <= '9')) {
        return true;
    }
    return false;
}

// Function to check if a string is a palindrome 
bool isPalindrome(string text) {
    int start = 0;
    int end = text.length() - 1;

    while (start < end) {
        // Skip spaces and special characters from the left
        while (start < end && !isLetterOrDigit(text[start])) {
            start++;
        }
        
        // Skip spaces and special characters from the right
        while (start < end && !isLetterOrDigit(text[end])) {
            end--;
        }

        // Compare characters 
        if (makeLowercase(text[start]) != makeLowercase(text[end])) {
            return false; 
        }

        start++;
        end--;
    }

    return true; 
}

int main() {
    string inputString;

    cout << "Enter a string to check for palindrome: ";
    getline(cin, inputString);

    if (isPalindrome(inputString)) {
        cout << "\"" << inputString << "\" is a valid palindrome!" << endl;
    } else {
        cout << "\"" << inputString << "\" is NOT a palindrome." << endl;
    }

    return 0;
}