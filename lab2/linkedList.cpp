#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void display(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void reverse(Node** head) {
    Node* prev = nullptr;
    Node* current = *head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void removeDuplicates(Node** head) {
    if (*head == nullptr) return;

    Node* current = *head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* next_next = current->next->next;
            delete current->next;
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

int main() {
    Node* head = nullptr;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 20);
    insert(&head, 30);

    cout << "Original list: ";
    display(head);

    removeDuplicates(&head);
    cout << "List after removing duplicates: ";
    display(head);

    reverse(&head);
    cout << "Reversed list: ";
    display(head);

    return 0;
}