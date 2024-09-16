#pragma once

#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BynarySearchTree {
public:
    Node* root;
    BynarySearchTree(int value) {
        Node* newNode = new Node(value);
        root = newNode;
    }
    BynarySearchTree() {
        root = nullptr;
    }
    bool insert(int value);
    bool contains(const int value);
};