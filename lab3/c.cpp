#include <bits/stdc++.h>
using namespace  std;
#include <vector> 

vector<int> solveQueries(const vector<int>& a, int n, const vector<vector<int>>& queries, int q){ 
    vector<int> answers(q); 
    for (int i = 0; i < q; i++) {
        int l1= queries[i][0]; 
        int r1= queries[i][1];
        int l2= queries[i][2];
        int r2= queries[i][3];
        int cnt=0; 
        for (int j=0; j<n; j++){ 
            if((a[j]>=l1 && a[j]<=r1) || (a[j]>=l2 && a[j]<= r2) ){ 
                cnt++; 
            }
        }
        answers[i]= cnt;
    } 
    return answers; 
}


int main(){ 
    int n; cin>>n; 
    int q; cin>>q; 
    vector<int> a(n); 
    for (int i=0; i<n; i++){ 
        cin>>a[i]; 
    }
    vector<vector<int>> queries(q,vector<int>(4)); 
    for(int i=0; i<q; i++) {
        cin>>queries[i][0]>> queries[i][1]>>queries[i][2]>> queries[i][3];
    }

    vector<int> answers = solveQueries(a,n,queries,q); 
    for (int i=0; i<q; i++){ 
        cout<<answers[i]<<endl;
    }


}