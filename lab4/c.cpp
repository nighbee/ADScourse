#include <iostream>
#include <vector>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to find the node with the given value
TreeNode* findNode(TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return findNode(root->left, val);
    } else {
        return findNode(root->right, val);
    }
}

// Function to perform pre-order traversal and print the values
void preOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> gifts(n);
    for (int i = 0; i < n; ++i) {
        cin >> gifts[i];
    }
    int k;
    cin >> k;

    // Construct the BST
    TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = insert(root, gifts[i]);
    }

    // Find the subtree rooted at the gift with number k
    TreeNode* subtreeRoot = findNode(root, k);

    // Print the subtree in pre-order
    preOrder(subtreeRoot);
    cout << endl;

    return 0;
}