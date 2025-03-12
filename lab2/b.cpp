#include <iostream>
using namespace std; 
#include <vector> 

struct Node{ 
    string  val; 
    Node* next; 
    Node(string x){ 
        val = x; 
        next = nullptr; 
    }
};

struct LinkedList{ 
    Node* head; 
    Node* tail; 

    public: 
    LinkedList(){ 
        head = nullptr; 
        tail = nullptr; 
    }
    void push(string s){ 
        Node* newNode = new Node(s); 
        if(head == nullptr){ 
            head = newNode; 
            tail = newNode; 
        }
        else { 
            tail->next = newNode; 
            tail = tail->next; 
        }
    }

    void shift(int pos){ 
        Node* cur = head; 
        while(cur->next !=nullptr){ 
            cur=cur->next; 
        }    
        while(pos !=0){ 
            cur-> next= head; 
            head = head->next;
            cur = cur->next;

            pos--; 
        }
        cur->next= nullptr; 
    }

    void print(){ 
        Node* cur = head; 
        while(cur != NULL){ 
            cout << cur->val << " "; 
            cur = cur->next; 
        }
    }

}; 
int main() {
    int n; cin>>n; 
    int pos; cin>>pos; 
    LinkedList l;
    for(int i=0; i<n;i++){ 
        string s; cin>>s; 
        l.push(s); 
    }
    l.shift(pos); 
    l.print(); 
    return 0; 
}