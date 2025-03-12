#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n, m; cin>> n>> m; 
    vector<int> one(n), two(m); 

    for(int i=0; i<n; i++){ 
        cin>> one[i]; 
    }

    for(int j=0; j<m;j++){ 
        cin>>two[j]; 
    }

    unordered_map<int, int> fr; 
    for(int num :one){ 
        fr[num]++; 
    }

    vector<int> common; 
    for(int num: two){ 
        if(fr[num] > 0){ 
            common.push_back(num); 
            fr[num]--; 
        }
    }
    sort(common.begin(), common.end()); 
    for(size_t i =0; i<common.size(); ++i){ 
        cout<<common[i]; 
        if(i<common.size()-1){ 
            cout<<" "; 
        }
    }

}