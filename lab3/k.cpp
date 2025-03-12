#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int minLength = INT_MAX;
    int currentSum = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        currentSum += arr[end];

        while (currentSum >= k) {
            minLength = min(minLength, end - start + 1);
            currentSum -= arr[start];
            start++;
        }
    }

    cout << minLength << endl;

    return 0;
}

int main(){ 
    
}