#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = 100000;

struct Edge {
    int u, v, weight;
};

bool findNegativeCycle(int n, vector<Edge>& edges, vector<int>& cycle) {
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    int x = -1;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (const auto& edge : edges) {
            if (dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
                parent[edge.v] = edge.u;
                x = edge.v;
            }
        }
    }

    if (x == -1) {
        return false;
    } else {
        for (int i = 0; i < n; ++i) {
            x = parent[x];
        }

        for (int v = x; ; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        return true;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Edge> edges;
    vector<int> cycle;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            cin >> weight;
            if (weight != INF) {
                edges.push_back({i, j, weight});
            }
        }
    }

    if (findNegativeCycle(n, edges, cycle)) {
        cout << "YES" << endl;
        cout << cycle.size() << endl;
        for (int v : cycle) {
            cout << v + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}