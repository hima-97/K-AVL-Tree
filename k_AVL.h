#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Needed to remove characters in strings
#include <sstream> // Needed for the parsing function
#include <cmath>
#include <climits>
using namespace std;

// k-AVL Tree class:
class k_AVL
{
public:
	// k-AVL Tree Node class:
	class Node
	{
	public:
		int wholePart;
		int fraction;
		int height;
		Node* left, *right;

		// Node constructor:
		Node() { right = left = nullptr; height = 0; }
		// Node destructor:
		~Node() { right = left = nullptr; delete left, right; }
	};

	// Function to get the height of a node:
	int getHeight(Node* node) const;

	// This is used to track the balance factor of the k-AVL tree:
	int balanceFactor;

	// Pointer to the root of the tree:
	Node* root;

	// Tree constructors:
	k_AVL(int k);

	// Tree destructor:
	~k_AVL() { root = nullptr; delete root; };

	// Function to convert a string to an integer:
	int stringToInt(string myString);

	// Function to convert an integer to a string:
	string intToString(int myInt);

	// Function to concatenate two integer values into one single integer value:
	int concatenateIntValues(int x, int y);

	// Function to rotate the node with the left child and update the heights (single rotation):
	void singleRotationWithLeftChild(Node*& node);

	// Function to rotate the node with the right child and update the heights (single rotation):
	void singleRotationWithRightChild(Node*& node);

	// Function to rotate the node's left child with its right child, then rotate the node with its new left child (double rotation):
	void doubleRotationWithLeftChild(Node*& node);

	// Function to rotate the node's right child with its left child, then rotate the node with its new right child (double rotation):
	void doubleRotationWithRightChild(Node*& node);

	// Function to balance the k-AVL tree:
	void balance(Node*& node);

	// Function to insert a decimal number in the tree:
	void insert(int myWholePart, int myFraction, Node*& node);

	// Function to search a decimal number in the tree:
	bool searchValue(int myWholePart, int myFraction, Node* node);

	// Function to search the value in the tree closest to the decimal number you are searching for:
	void approx_search(int myWholePart, int myFraction, Node* node);

	// Function to delete a decimal number in the tree:
	void deleteNumber(int myWholePart, int myFraction, Node*& node);

	// Function to find the node containing the maximum value in a node's subtree:
	Node* findMax(Node* node);

	// Function to traverse and print the tree in LNR (in-order traversal):
	void printLNR(Node* node);

	// Function to traverse and print the tree in NLR (pre-order traversal):
	void printNLR(Node* node);
};