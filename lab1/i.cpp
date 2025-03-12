#include <iostream>
using namespace std;
#include <queue>
int main() {
    // Your code here
    int n; cin>> n; 
    queue<char> q; 
    for(int i=0; i<n; i++){ 
        char c; cin>> c; 
        q.push(c); 
    }

    int cntS=0; 
    int cntK=0; 

    while(q.size()>1 && q.size() > cntS && q.size()> cntK){ 
        if(q.front() == 'K'){ 
            if(cntK>0){ 
                cntK--; 
                q.pop(); 
            }
            else{ 
                cntS++; 
                q.push(q.front()); 
                q.pop(); 
            } 
        }
        else{ 
            if(cntS>0){ 
                cntS--; 
                q.pop(); 
            }
            else{ 
                cntK++; 
                q.push(q.front()); 
                q.pop();
            }
        }
    }

    if(q.front()=='K'){ 
        cout<< "KATSURAGI"; 
    }
    else{ 
        cout<< "SAKAYANAGI";
    }
    return 0;
}