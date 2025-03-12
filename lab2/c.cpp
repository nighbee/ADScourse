#include <iostream>
using namespace std; 
#include <vector> 

struct Node{ 
    int  val; 
    Node* next; 
    Node(int  x){ 
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
    void push(int s){ 
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
    LinkedList l;
    for(int i=0; i<n;i++){ 
        int s; cin>>s; 
        if(i%2==0){ 
            l.push(s); 
        }
        else{
            continue;  
        }
    }
    l.print(); 
    return 0; 
}