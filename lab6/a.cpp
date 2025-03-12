#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    int n;
    string s;
    
    cin >> n >> s;
    
    vector<char> vowels;
    vector<char> consonants;
    
    for (char c : s) {
        if (isVowel(c)) {
            vowels.push_back(c);
        } else {
            consonants.push_back(c);
        }
    }
    
    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());
    
    for (char c : vowels) {
        cout << c;
    }
    for (char c : consonants) {
        cout << c;
    }
    
    cout << endl;
    
    return 0;
}