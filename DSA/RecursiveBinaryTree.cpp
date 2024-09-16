#include "RecursiveBinaryTree.hpp"

bool RecursiveBST::rContains(Node* currentNode, int value)
{
	if (currentNode == nullptr) return false;
	if (currentNode->value == value) return true;
	if (value < currentNode->value) {
		return rContains(currentNode->left, value);
	}
	else {
		return rContains(currentNode->right, value);
	}
}

bool RecursiveBST::rContains(int value)
{
	return rContains(root,value);
}

Node* RecursiveBST::rInsert(Node* currentNode, int value)
{
	if (currentNode == nullptr) return new Node(value);
	if (value < currentNode->value) {
		currentNode->left = rInsert(currentNode->left, value);
	}
	else if (value > currentNode->value) {
		currentNode->right = rInsert(currentNode->right, value);
	}
	return currentNode;
}

void RecursiveBST::rInsert(int value)
{
	if (root == nullptr) root = new Node(value);
	rInsert(root, value);
}

Node* RecursiveBST::rDeleteNode(Node* currentNode, int value)
{
	if (value < currentNode->value) {
		currentNode->left = rDeleteNode(currentNode->left, value);
	}else if (value > currentNode->value) {
		currentNode->right = rDeleteNode(currentNode->right, value);
	}
}

void RecursiveBST::rDeleteNode(int value)
{
	rDeleteNode(root, value);
}
