#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Comparator function to sort rows based on the given rules
bool compareRows(const vector<int>& row1, const vector<int>& row2) {
    int sum1 = accumulate(row1.begin(), row1.end(), 0);
    int sum2 = accumulate(row2.begin(), row2.end(), 0);

    if (sum1 != sum2) {
        return sum1 > sum2; // Sort by sum in decreasing order
    }
    return row1 < row2; // If sums are equal, sort lexicographically
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rows(n, vector<int>(m));

    // Read the input rows
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> rows[i][j];
        }
    }

    // Sort the rows using the custom comparator
    sort(rows.begin(), rows.end(), compareRows);

    // Print the sorted rows
    for (const auto& row : rows) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}