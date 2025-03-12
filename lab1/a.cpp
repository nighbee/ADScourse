#include <iostream>
#include <deque>
using namespace std; 

int main() {
    // Your code goes here
    int n; cin>> n; 
    for(int i=0; i<n; i++){ 
        int x; cin >>x; 
        int size=x; 
        deque<int> d;
        d.push_front(x);

        x--; 
        while(x>0){ 
            d.push_front(x); 
            int cnt=0; 
            while(cnt !=x){ 
                d.push_front(d.back()); 
                d.pop_back(); 
                cnt++; 
            } 
            x--; 
        } 
        for(int i=0; i<size; i++){ 
            cout<<d.front()<< " ";
            d.pop_front(); 
        }
        cout<<endl;
    }


    return 0;
}