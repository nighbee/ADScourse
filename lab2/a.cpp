#include <iostream>
using namespace std; 

struct Node {
    int val;
    Node* next;
    Node(int x){ 
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

    void push(int x){ 
    Node* newNode = new Node(x); 
    if(head  == nullptr) {
        
        head=newNode; 
        tail = newNode; 
    }
    else { 
        tail->next = newNode; 
        tail = tail->next; 
    }
    }

    int diff(int t){ 
        Node* cur =head; 
        int i=0; 
        int min, posOfMin; 
        while(cur !=NULL ){ 
            cur-> val= abs(cur-> val - t); 
            if(i==0) { 
                min = cur->val; 
                posOfMin = i; 
            }
            else { 
                if(cur->val < min) { 
                    min = cur->val; 
                    posOfMin = i; 
                }
            }
        cur = cur->next; 
        i++; 
        }
        return posOfMin;
     
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
    // Your code here
    int n; cin>>n; 
    LinkedList l;
    for(int i=0; i<n; i++ ){ 
        int x; cin>>x; 
        l.push(x); 
        }
    int j; cin>>j; 
    cout<<l.diff(j); 
}