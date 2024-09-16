#pragma once

#include "BinaryTree.hpp"


class RecursiveBST : public BynarySearchTree {
public:
	bool rContains(Node* currentNode, int value);
	bool rContains(int value);
	Node* rInsert(Node* currentNode, int value);
	void rInsert(int value);
	Node* rDeleteNode(Node* currentNode, int value);
	void rDeleteNode(int value);
};
