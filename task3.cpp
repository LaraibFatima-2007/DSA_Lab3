/*
 * Course: CS-250 Data Structures and Algorithms
 * Task:  Singly Linked List Implementation
 * Author: Laraib Fatima
 * Date: 22-09-2026
 */

#include <iostream>

using namespace std;

// Structure representing each Node in the Linked List
struct Node {
    int data;
    Node* next;
};

// 1. Insert a node at the head 
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << val << " at the head." << endl;
}

// 2. Insert a node at the 3rd location 
void insertAtThird(Node*& head, int val) {
    // If list has fewer than 2 elements, we cannot insert at 3rd position
    if (head == nullptr || head->next == nullptr) {
        cout << "List has fewer than 2 nodes! Cannot insert at 3rd position." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;

    // move to the 2nd node
    Node* temp = head->next;

    // Insert new node after the 2nd node 
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Inserted " << val << " at the 3rd position." << endl;
}

// 3. Display all contents of the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "List contents: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 4. Delete the last node in the linked list
void deleteLast(Node*& head) {
    if (head == nullptr) {
        cout << "List is already empty! Nothing to delete." << endl;
        return;
    }

    // Special Case: Only 1 node present
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Last node deleted. List is now empty." << endl;
        return;
    }

    // move to the second-to-last node
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Delete the last node and set the new end to nullptr
    delete temp->next;
    temp->next = nullptr;
    cout << "Last node successfully deleted." << endl;
}

// 5. Count total number of nodes present
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 6. Reverse the linked list iteratively
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next; // Store next
        current->next = prev;     // Reverse current node's pointer
        prev = current;           // Move prev forward
        current = nextNode;       // Move current forward
    }

    head = prev; // Update head to new start
    cout << "List reversed successfully!" << endl;
}

// 7. Search for a given value in the list
void searchValue(Node* head, int val) {
    Node* temp = head;
    int position = 1;

    while (temp != nullptr) {
        if (temp->data == val) {
            cout << "Value " << val << " found at position " << position << "." << endl;
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Value " << val << " was NOT found in the list." << endl;
}

// 8. Menu-driven Interface
int main() {
    Node* head = nullptr; // Initialize list pointers to NULL
    int choice, val;

    do {
        cout << "\n=========================================" << endl;
        cout << "      SINGLY LINKED LIST OPERATIONS      " << endl;
        cout << "=========================================" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at 3rd Position" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Delete Last Node" << endl;
        cout << "5. Count Nodes" << endl;
        cout << "6. Reverse List" << endl;
        cout << "7. Search Value" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter integer value to insert: ";
                cin >> val;
                insertAtHead(head, val);
                break;

            case 2:
                cout << "Enter integer value to insert at 3rd position: ";
                cin >> val;
                insertAtThird(head, val);
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                deleteLast(head);
                displayList(head);
                break;

            case 5:
                cout << "Total nodes in list: " << countNodes(head) << endl;
                break;

            case 6:
                reverseList(head);
                displayList(head);
                break;

            case 7:
                cout << "Enter value to search for: ";
                cin >> val;
                searchValue(head, val);
                break;

            case 8:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please choose between 1 and 8." << endl;
        }
    } while (choice != 8);

    // Clean up remaining memory before exiting
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}