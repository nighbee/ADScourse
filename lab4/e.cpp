#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int n, vector<tuple<int, int, int>>& edges) {
    unordered_map<int, TreeNode*> nodes;
    for (int i = 1; i <= n; ++i) {
        nodes[i] = new TreeNode(i);
    }
    for (auto& edge : edges) {
        int x, y, z;
        tie(x, y, z) = edge;
        if (z == 0) {
            nodes[x]->left = nodes[y];
        } else {
            nodes[x]->right = nodes[y];
        }
    }
    return nodes[1];
}

int getMaxWidth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int maxWidth = 0;
    while (!q.empty()) {
        int count = q.size();
        maxWidth = max(maxWidth, count);
        for (int i = 0; i < count; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return maxWidth;
}

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = make_tuple(x, y, z);
    }
    TreeNode* root = buildTree(n, edges);
    cout << getMaxWidth(root) << endl;
    return 0;
}