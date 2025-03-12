#include <iostream>
#include <map>

class BST {
private:
    struct Node {
        int key;
        int count;
        Node* left;
        Node* right;
        Node(int k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            node->count++;
        }
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return node;
        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->count > 1) {
                node->count--;
            } else {
                if (!node->left) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                } else if (!node->right) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
                Node* temp = minValueNode(node->right);
                node->key = temp->key;
                node->count = temp->count;
                temp->count = 1;
                node->right = deleteNode(node->right, temp->key);
            }
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    int count(Node* node, int key) {
        if (!node) return 0;
        if (key < node->key) {
            return count(node->left, key);
        } else if (key > node->key) {
            return count(node->right, key);
        } else {
            return node->count;
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    int count(int key) {
        return count(root, key);
    }
};

int main() {
    int q;
    std::cin >> q;
    BST bst;
    while (q--) {
        std::string command;
        int key;
        std::cin >> command >> key;
        if (command == "insert") {
            bst.insert(key);
        } else if (command == "delete") {
            bst.deleteNode(key);
        } else if (command == "cnt") {
            std::cout << bst.count(key) << std::endl;
        }
    }
    return 0;
}