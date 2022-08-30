#include "k_AVL.h"
using namespace std;

// Function to parse the input string:
vector<string> inputParsing(string myInput)
{
    // Commands vector to store the parsed input string: 
    vector<string> myCommands;

    stringstream ss(myInput);

    // Variable to hold a single word of the input string:
    string singleWord;

    // Loop to parse the input string:
    while(getline(ss, singleWord, ' '))
    {
        // This erases the "," in each word:
        singleWord.erase(remove(singleWord.begin(), singleWord.end(), ','), singleWord.end());

        // This puts each word in the commands vector:
        myCommands.push_back(singleWord);
    }
    return myCommands;
}

// Function to convert a string to an integer:
int stringToInt(string myString)
{
    // This is an object of the "stringstream" class:
    stringstream myObject(myString);

    // This streams the value of "myObject" into the integer "x":
    int x = 0;
    myObject >> x;

    return x;
}

int main(int argc, char* argv[])
{
    // Input string from the command line prompt:
    string input = argv[1];
    //string input = "1, insert 4 5, insert 3 9, insert 3 5, insert 2 7, insert 2 6, in_order, insert 5 6, insert 4 2, insert 5 1, insert 5 4, search 2 6, search 8 9, insert 5 2, insert 4 1, delete 3 9, delete 2 7, delete 5 4, delete 5 2, delete 3 5, delete 9 3, delete 2 6, delete 4 1, delete 5 6, delete 5 1, delete 4 5, delete 4 2, pre_order, delete 9 7, search 4 2";

    // Vector to store the parsed input string:
    vector<string> commands = inputParsing(input);

    // Creating an object of the k_AVL class by passing the first command (k value) to the constructor:
    k_AVL myTree(stringToInt(commands[0]));

    // Checking and performing each command from the input:
    for (int i = 1; i < commands.size(); i++)
    {
        // Checking for the command to insert a decimal number:
        if ((commands[i] == "insert") || (commands[i] == "Insert"))
        {
            // This stores the int for the whole part that follows "insert" from the input:
            int myWholePart = stringToInt(commands[i + 1]);

            // This stores the int for the fraction part that follows "insert" from the input:
            int myFraction = stringToInt(commands[i + 2]);

            // This is used to search the decimal number in the tree:
            bool isValuePresent = false;
            isValuePresent = myTree.searchValue(myWholePart, myFraction, myTree.root);

            // Checking if the decimal number is already in the tree:
            if (isValuePresent == true)
            {
                // Do nothing 
            }
            else
            {
                // This inserts the decimal number in the tree:
                myTree.insert(myWholePart, myFraction, myTree.root);
            }
        }
        // Checking for the command to search a decimal number:
        else if ((commands[i] == "search") || (commands[i] == "Search"))
        {
            // This stores the int for the whole part that follows "search" from the input:
            int myWholePart = stringToInt(commands[i + 1]);

            // This stores the int for the fraction part that follows "search" from the input:
            int myFraction = stringToInt(commands[i + 2]);

            // This is used to search the decimal number in the tree:
            bool isValuePresent = false;
            isValuePresent = myTree.searchValue(myWholePart, myFraction, myTree.root);

            // Checking if the decimal number is in the tree:
            if (isValuePresent == true)
            {
                cout << myWholePart << "." << myFraction << " found" << endl;
            }
            else
            {
                cout << myWholePart << "." << myFraction << " not found" << endl;
            }
        }
        // Checking for the command to perform an approximate search of the decimal number:
        else if ((commands[i] == "approx_search") || (commands[i] == "Approx_search"))
        {
            // This stores the int for the whole part that follows "approx_search" from the input:
            int myWholePart = stringToInt(commands[i + 1]);

            // This stores the int for the fraction part that follows "approx_search" from the input:
            int myFraction = stringToInt(commands[i + 2]);
            
            // This is used to search the value in the tree closest to the decimal number you are searching for:
            myTree.approx_search(myWholePart, myFraction, myTree.root);
        }
        // Checking for the command to traverse and print the tree in an in-order (LNR) manner :
        else if ((commands[i] == "in_order") || (commands[i] == "In_order"))
        {
            if (myTree.root != nullptr)
            {
                cout << "Printing the K-AVL tree in LNR (in-order traversal): ";
                myTree.printLNR(myTree.root);
                cout << endl;
            }
        }
        // Checking for the command to traverse and print the tree in a pre-order (NLR) manner:
        else if ((commands[i] == "pre_order") || (commands[i] == "Pre_order"))
        {
            if (myTree.root != nullptr)
            {
                cout << "Printing the K-AVL tree in NLR (pre-order traversal): ";
                myTree.printNLR(myTree.root);
                cout << endl;
            }
        }
        // Checking for the command to delete a decimal number:
        else if ((commands[i] == "delete") || (commands[i] == "Delete"))
        {
            // This stores the int for the whole part that follows "delete" from the input:
            int myWholePart = stringToInt(commands[i + 1]);

            // This stores the int for the fraction part that follows "delete" from the input:
            int myFraction = stringToInt(commands[i + 2]);

            // This is used to search the decimal number in the tree:
            bool isValuePresent = false;
            isValuePresent = myTree.searchValue(myWholePart, myFraction, myTree.root);

            // Checking if the decimal number is in the tree:
            if (isValuePresent == true)
            {
                // This deletes the decimal number in the tree:
                myTree.deleteNumber(myWholePart, myFraction, myTree.root);

                // This deletes the node containing the decimal number you want to delete:
                cout << myWholePart << "." << myFraction << " deleted" << endl;
            }
        }
    }

    return 0;
}