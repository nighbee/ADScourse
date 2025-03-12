#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortVectors(const vector<int>& vec1, const vector<int>& vec2){ 
    vector<int> result; 
    int i = 0, j = 0; 
    while (i < vec1.size() && j < vec2.size()){ 
        if (vec1[i] < vec2[j]){ 
            result.push_back(vec1[i]); 
            i++; 
        } else { 
            result.push_back(vec2[j]); 
            j++; 
        } 
    }

    while (i < vec1.size()){ 
        result.push_back(vec1[i]); 
        i++;
    }
    while (j < vec2.size()){ 
        result.push_back(vec2[j]);
        j++; 
    }
    return result; 
}

void print(const vector<int>& vec){ 
    for (int i = 0; i < vec.size(); i++){ 
        cout << vec[i] << " "; 
    }
    cout << endl; 
}

int main(){ 
    vector<int> vec1; 
    vector<int> vec2; 
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++){ 
        int x; 
        cin >> x; 
        vec1.push_back(x);
    }
    int m; 
    cin >> m; 
    for (int j = 0; j < m; j++){ 
        int x; 
        cin >> x; 
        vec2.push_back(x);
    }
    vector<int> res = mergeSortVectors(vec1, vec2); 
    print(res);
}