#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> railways(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> roads(n + 1, vector<int>(n + 1, 1));

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        railways[u][v] = railways[v][u] = 1;
        roads[u][v] = roads[v][u] = 0;
    }

    auto bfs = [&](const vector<vector<int>>& graph, int start) {
        vector<int> dist(n + 1, INF);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 1; v <= n; ++v) {
                if (graph[u][v] && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist;
    };

    vector<int> dist_walk = bfs(roads, 1);
    vector<int> dist_fly = bfs(railways, 1);

    int result = max(dist_walk[n], dist_fly[n]);
    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}