#include <iostream>
#include <queue>
using namespace std; 
int main() {
    // Your code goes here
    queue<int> boris; 
    queue<int> nursik; 

    for(int i=0; i <10; i++){ 
        int card; cin>> card; 
        if(i<5){ 
            boris.push(card);
        }
        else{ 
            nursik.push(card); 
        }
    }

    int cnt=0; 
    while(!boris.empty()&& !nursik.empty()){ 
        cnt++; 
        if(cnt==100000){ 
            cout<< "blin nichiya"<<endl; 
            break;
        }

        if(boris.front() == 0 && nursik.front() == 9){ 
            boris.push(boris.front()); 
            boris.push(nursik.front()); 
            boris.pop(); 
            nursik.pop();
        }
        else if(boris.front() == 9 && nursik.front() == 0){ 
            nursik.push(boris.front()); 
            nursik.push(nursik.front()); 
            boris.pop(); 
            nursik.pop();
        }
        else if(boris.front() > nursik.front()){ 
            boris.push(boris.front()); 
            boris.push(nursik.front()); 
            boris.pop(); 
            nursik.pop();
        }
        else{ 
            nursik.push(boris.front()); 
            nursik.push(nursik.front()); 
            boris.pop(); 
            nursik.pop();
        }
    }
    if(nursik.empty()){ 
        cout<< "Boris "<< cnt; 
    }
    else{ 
        cout<< "Nursik "<< cnt;
    }
}