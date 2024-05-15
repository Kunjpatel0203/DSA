#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertBefore(Node*& head, int val, int key) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        
            newNode->prev = temp->prev;
            newNode->next = temp;
            temp->prev->next = newNode;
            temp->prev = newNode;
           }
}

void insertAfter(Node*& head, int val, int key) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
        
    }
}

void deleteBefore(Node*& head, int key) {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
   temp->prev->prev->next=temp;
    temp->prev=temp->prev->prev;
}


void deleteAfter(Node*& head, int key) {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp != nullptr && temp->next != nullptr) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != nullptr) {
            toDelete->next->prev = temp;
        }
        delete toDelete;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    cout << "Original Doubly Linked List:" << endl;
    display(head);

    insertBefore(head, 2, 3);
    insertAfter(head, 5, 4);
    cout << "Doubly Linked List after insertions:" << endl;
    display(head);

    deleteBefore(head, 4);
    deleteAfter(head, 6);
    cout << "Doubly Linked List after deletions:" << endl;
    display(head);

    return 0;
}
