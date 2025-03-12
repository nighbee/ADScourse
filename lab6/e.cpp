#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortINDesc(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int j = 0; j < m; ++j) {
        vector<int> column(n);
        for (int i = 0; i < n; ++i) {
            column[i] = matrix[i][j];
        }
        sort(column.begin(), column.end(), greater<int>());
        for (int i = 0; i < n; ++i) {
            matrix[i][j] = column[i];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    sortINDesc(matrix);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
