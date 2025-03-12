#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool compareByLength(const string &a, const string &b) { 
    return a.size() < b.size(); 
}

int main() { 
    int n; 
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input

    for(int i = 0; i < n; i++) { 
        string line; 
        getline(cin, line); 

        stringstream ss(line); 
        vector<string> words; 
        string word; 
        while (ss >> word) { 
            words.push_back(word); 
        }

        stable_sort(words.begin(), words.end(), compareByLength); 

        for(size_t j = 0; j < words.size(); ++j) { 
            cout << words[j];
            if (j < words.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
