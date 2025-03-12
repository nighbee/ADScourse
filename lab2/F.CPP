#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void print() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void insertAtPosition(int pos, int newData) {
        Node* newNode = new Node(newData);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
            return;
        }

        Node* cur = head;
        for (int i = 0; i < pos - 1 && cur != nullptr; ++i) {
            cur = cur->next;
        }

        if (cur == nullptr) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }

        newNode->next = cur->next;
        cur->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList l;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.push(x);
    }
    int newData;
    cin >> newData;
    int pos;
    cin >> pos;
    l.insertAtPosition(pos, newData);
    l.print();

    return 0;
}