#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

   
};

int main() {
    // Sample BST Structure
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int val = 65; // Value to be inserted later
    Node* temp = root;

    // Traverse until temp reaches nullptr
    while (temp->left != nullptr || temp->right != nullptr) {
        if (val < temp->data) {
            if (temp->left == nullptr) break; // Stop if we reach insertion point
            temp = temp->left;  // Move left
        } else {
            if (temp->right == nullptr) break; // Stop if we reach insertion point
            temp = temp->right; // Move right
        }
    }

    cout << "Final position of temp (before insertion): " << temp->data << endl;

    // You can insert at temp->left or temp->right now.

    return 0;
}
