# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

string binSearch(vector<int> vec, int low, int high, int x){ 
     string yes ="Yes"; 
        string no ="No"; 
    while (low<=high){ 
    
        int mid= low + (high - low)/2; 
        if (vec[mid]==x) return yes; 
        if (vec[mid]<x) low= mid+1; 
        else high= mid-1; 
    }
    return no; 
}


int main(){ 
    int n; cin>> n; 
    vector<int> vec(n); 
    for (int i=0; i<n; i++){ 
        cin>> vec[i]; 
    }

    int low= 0; 
    int high= n-1; 

    int x; cin>> x; 
    cout<<binSearch(vec, low, high, x); 
}