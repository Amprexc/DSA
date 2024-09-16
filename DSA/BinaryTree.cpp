#include "BinaryTree.hpp"

bool BynarySearchTree::insert(int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
        root = newNode;
        return true;
    }
    Node* temp = root;
    while (true) {
        if (newNode->value == temp->value) return false;
        if (newNode->value < temp->value) {
            if (temp->left == nullptr) {
                temp->left = newNode;
                return true;
            }
            temp = temp->left;

        }
        else {
            if (temp->right == nullptr) {
                temp->right = newNode;
                return true;
            }
            temp = temp->right;
        }
    }
}

bool BynarySearchTree::contains(const int value) {
    //if(root == nullptr) return false;
    Node* temp = root;
    while (temp != nullptr) {
        if (value < temp->value) {
            temp = temp->left;
        }
        else if (value > temp->value) {
            temp = temp->right;
        }
        else {
            return true;
        }
    }
    return false;
}