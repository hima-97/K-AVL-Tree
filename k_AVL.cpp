#include "k_AVL.h"
using namespace std;

// Constructor that takes "k" as parameter and builds (initializes) an empty k-AVL tree:
k_AVL::k_AVL(int k)
{
    // This sets the root to nullptr:
    root = nullptr;

    // This sets the balance factor of the k-AVL tree equal to the value of "k":
    balanceFactor = k;
}

// Function to get the height of a node:
int k_AVL::getHeight(Node* node) const
{
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

// Function to convert a string to an integer:
int k_AVL::stringToInt(string myString)
{
    // This is an object of the "stringstream" class:
    stringstream myObject(myString);

    // This streams the value of "myObject" into the integer "x":
    int x = 0;
    myObject >> x;

    return x;
}

// Function to convert an integer to a string:
string k_AVL::intToString(int myInt)
{
    // This is an object of the "ostringstream" class for the output string:
    ostringstream strObject;

    // This sends the value of "myInt" into the string object "strObject":
    strObject << myInt;

    // This converts the int value in the string object into a string:
    string myString = strObject.str();

    return myString;
}

// Function to concatenate two integer values into one single integer value:
int k_AVL::concatenateIntValues(int x, int y)
{
    // This is used to convert an integer value to a string:
    string xString = intToString(x);
    string yString = intToString(y);

    // This is used to concatenate two strings:
    string xyString = xString + yString;

    // This is used to convert a string to an integer values:
    int xy = stringToInt(xyString);

    return xy;
}

// Function to rotate the node with the left child and update the heights (single rotation):
void k_AVL::singleRotationWithLeftChild(Node*& node)
{
    Node* myNode = node->left;
    node->left = myNode->right;
    myNode->right = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    myNode->height = max(getHeight(myNode->left), node->height) + 1;
    node = myNode;
}

// Function to rotate the node with the right child and update the heights (single rotation):
void k_AVL::singleRotationWithRightChild(Node*& node)
{
    Node* myNode = node->right;
    node->right = myNode->left;
    myNode->left = node;
    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    myNode->height = max(getHeight(myNode->right), node->height) + 1;
    node = myNode;
}

// Function to rotate the node's left child with its right child, then rotate the node with its new left child (double rotation):
void k_AVL::doubleRotationWithLeftChild(Node*& node)
{
    singleRotationWithRightChild(node->left);
    singleRotationWithLeftChild(node);
}

// Function to rotate the node's right child with its left child, then rotate the node with its new right child (double rotation):
void k_AVL::doubleRotationWithRightChild(Node*& node)
{
    singleRotationWithLeftChild(node->right);
    singleRotationWithRightChild(node);
}

// Function to balance the k-AVL tree:
void k_AVL::balance(Node*& node)
{
    if (node == nullptr)
    {
        return;
    }
    // Checking if the difference between the heights of the node's left subtree and right subtree is greater than the balance factor:
    if ((getHeight(node->left) - getHeight(node->right)) > balanceFactor)
    {
        if (getHeight(node->left->left) >= getHeight(node->left->right))
        {
            singleRotationWithLeftChild(node);
        }
        else
        {
            doubleRotationWithLeftChild(node);
        }
    }
    // Checking if the difference between the heights of the node's right subtree and left subtree is greater than the balance factor:
    else if ((getHeight(node->right) - getHeight(node->left)) > balanceFactor)
    {
        if (getHeight(node->right->right) >= getHeight(node->right->left))
        {
            singleRotationWithRightChild(node);
        }
        else
        {
            doubleRotationWithRightChild(node);
        }
    }

    // This assigns the new height to the node, after balancing it:
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to insert a decimal number in the tree:
void k_AVL::insert(int myWholePart, int myFraction, Node*& node)
{
    // Checking if the node pointer points to nothing:
    if (node == nullptr)
    {   
        node = new Node(); // This creates a new node on the heap (dynamic allocation):
        node->wholePart = myWholePart;
        node->fraction = myFraction;
        cout << node->wholePart << "." << node->fraction << " inserted" << endl;

        // This sets the root of the tree equal to the current node (if current node is the very first node in the tree):
        if (root == nullptr)
        {
            root = node;
        }
    }
    // Checking if whole part to be insert is equal to node's whole part:
    else if (myWholePart == node->wholePart)
    {
        // Checking if fraction to be insert is less than node's fraction:
        if (myFraction < node->fraction)
        {
            insert(myWholePart, myFraction, node->left);
        }
        // Checking if fraction to be insert is greater than node's fraction:
        else
        {
            insert(myWholePart, myFraction, node->right);
        }
    }
    // Checking if whole part to be insert is less than node's whole part:
    else if (myWholePart < node->wholePart)
    {
        insert(myWholePart, myFraction, node->left);
    }
    // Checking if whole part to be insert is greater than node's whole part:
    else if (myWholePart > node->wholePart)
    {
        insert(myWholePart, myFraction, node->right);
    }

    // Calling the function to balance the k-AVL tree:
    balance(node);
}

// Function to search a decimal number in the tree:
bool k_AVL::searchValue(int myWholePart, int myFraction, Node* node)
{
    if (node == nullptr)
        return false;

    // Checking if node's decimal number is equal to the decimal number you are searching for:
    if ((myWholePart == node->wholePart) && (myFraction == node->fraction))
        return true;

    // Checking the left subtree of the current node:
    bool isPresentLeft = searchValue(myWholePart, myFraction, node->left);
    if (isPresentLeft)
        return true;

    // Checking the right subtree of the current node:
    bool isPresentRight = searchValue(myWholePart, myFraction, node->right);
    if (isPresentRight)
        return true;
    
    return false; // Added to handle the case when the value is not found
}

// Function to search the value in the tree closest to the decimal number you are searching for:
void k_AVL::approx_search(int myWholePart, int myFraction, Node* node)
{
    // If the tree is empty, then do not do anything:
    if (node == nullptr)
    {
        return;
    }
    else
    {
        // This is used to concatenate the whole part and the fraction of the decimal number you are searching for into one single integer value:
        int targetValue = concatenateIntValues(myWholePart, myFraction);
        
        // This is used to keep track of the minimum difference between the whole parts of two decimal numbers:
        int minimumDifference = INT_MAX;

        // This is used to keep track of the node that contains the value closest to the decimal number you are searching for:
        Node* nodeWithClosestValue = node;

        // This is used to keep track of the current node:
        Node* current = node;

        // While loop that keeps executing until the current node points to nothing:
        while (current != nullptr)
        {
            // Checking if current node's left subtree is empty:
            if (current->left == nullptr)
            {
                // This is used to concatenate the whole part and the fraction of the current node into one single integer value:
                int currentValue = concatenateIntValues(current->wholePart, current->fraction);

                // Checking if the current difference of the values is smaller than the previous minimum difference recorded so far:
                if (abs(currentValue - targetValue) < minimumDifference)
                {
                    // This updates the minimum difference recorded so far:
                    minimumDifference = abs(currentValue - targetValue);

                    // This updates the node that contains the value closest to the decimal number you are searching for:
                    nodeWithClosestValue = current;
                }

                // This sets the current node equal to the right child of the current node:
                current = current->right;
            }
            else
            {
                // This is used to store the in-order predecessor of the current node:
                Node* inOrderPredecessor = current->left;

                // This is used to get the in-order predecessor of the current node:
                while ((inOrderPredecessor->right != nullptr) && (inOrderPredecessor->right != current))
                {
                    inOrderPredecessor = inOrderPredecessor->right;
                }

                // Checking if the in-order predecessor's right subtree is empty:
                if (inOrderPredecessor->right == nullptr)
                {
                    // This sets the right child of the in-order predecessor equal to the current node:
                    inOrderPredecessor->right = current;

                    // This sets the current node equal to the left child of the current node:
                    current = current->left;
                }
                else
                {
                    // This sets the in-order predecessor's right child equal to nullptr:
                    inOrderPredecessor->right = nullptr;

                    // This is used to concatenate the whole part and the fraction of the current node into one single integer value:
                    int currentValue = concatenateIntValues(current->wholePart, current->fraction);

                    // Checking if the current difference of the values is smaller than the previous minimum difference recorded so far:
                    if (abs(currentValue - targetValue) < minimumDifference)
                    {
                        // This updates the minimum difference recorded so far:
                        minimumDifference = abs(currentValue - targetValue);

                        // This updates the node that contains the value closest to the decimal number you are searching for:
                        nodeWithClosestValue = current;
                    }

                    // This sets the current node equal to the right child of the current node:
                    current = current->right;
                }
            }
        }

        // This prints the value closest to the decimal number you are searching for:
        cout << "closest to " << myWholePart << "." << myFraction << " is " << nodeWithClosestValue->wholePart << "." << nodeWithClosestValue->fraction << endl;
    }
}

// Function to find the node containing the maximum value in a node's subtree:
k_AVL::Node* k_AVL::findMax(Node* node)
{
    while (node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

// Function to delete a decimal number in the tree:
void k_AVL::deleteNumber(int myWholePart, int myFraction, Node*& node)
{
    // Checking if the node pointer points to nothing (decimal number is not in the tree):
    if (node == nullptr)
        return;
    
    // Checking if decimal  umber to delete is less than node's decimal number:
    if (concatenateIntValues(myWholePart, myFraction) < concatenateIntValues(node->wholePart, node->fraction))
    {
        deleteNumber(myWholePart, myFraction, node->left);
    }
    // Checking if  decimal  umber to delete is greater than node's decimal number:
    else if (concatenateIntValues(myWholePart, myFraction) > concatenateIntValues(node->wholePart, node->fraction))
    {
        deleteNumber(myWholePart, myFraction, node->right);
    }
    // Checking if node to delete has two children:
    else if ((node->left != nullptr) && (node->right != nullptr))
    {
        node->wholePart = findMax(node->left)->wholePart;
        node->fraction = findMax(node->left)->fraction;

        deleteNumber(node->wholePart, node->fraction, node->left);
    }
    else
    {
        Node* nodeToDelete = node;

        if (node->left != nullptr)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }

        delete nodeToDelete;
        nodeToDelete = nullptr;
    }
    // Calling the function to balance the k-AVL tree:
    balance(node);
}

// Function to traverse and print the tree in LNR (in-order traversal):
void k_AVL::printLNR(Node* node)
{
    if (node == nullptr)
        return;

    // Checking the left subtree of the current node:
    if (node->left != nullptr)
    {
        printLNR(node->left);
        cout << " ";
    }

    // This prints the decimal number of a node:
    cout << node->wholePart << "." << node->fraction;

    // Checking the right subtree of the current node:
    if (node->right != nullptr)
    {
        cout << " ";
        printLNR(node->right);
    }
}


// Function to traverse and print the tree in NLR (pre-order traversal):
void k_AVL::printNLR(Node* node)
{
    if (node == nullptr)
        return;

    // This prints the decimal number of a node:
    cout << node->wholePart << "." << node->fraction;

    // Checking the left subtree of the current node:
    if (node->left != nullptr)
    {
        if (node->left == root)
        {
            printNLR(node->left);
        }
        else
        {
            cout << " ";
            printNLR(node->left);
        }
    }

    // Checking the right subtree of the current node:
    if (node->right != nullptr)
    {
        if (node->right == root)
        {
            printNLR(node->right);
        }
        else
        {
            cout << " ";
            printNLR(node->right);
        }
    }
}
