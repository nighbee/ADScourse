#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    priority_queue<long long> seats; // Use long long for larger numbers
    for (int i = 0; i < n; ++i) {
        long long seat;
        cin >> seat;
        seats.push(seat);
    }
    
    long long maxRevenue = 0; // Use long long for larger numbers
    for (int i = 0; i < m; ++i) {
        long long top = seats.top();
        seats.pop();
        maxRevenue += top;
        if (top > 1) {
            seats.push(top - 1);
        }
    }
    
    cout << maxRevenue << endl;
    return 0;
}