# Project Description

This project consists of building a K-AVL tree from scratch.

An AVL tree is a self-balancing binary search tree where the height of the two child subtrees at any node can differ by at most one.
However, in a K-AVL tree the height of the two child subtrees at any node can differ by at most K.
The implementation for the K-AVL tree is very similar to that of the AVL tree, except that a node is re-balanced when the height difference of its children exceeds K.

Each node of the K-AVL tree contains a customized form of a non-negative single digit precision decimal value. <br />
Each decimal number to be stored in a node is represented as a tuple (wholepart, fraction):
- The whole part can contain one or more digits, but it is smaller than the max value of a 32-bit integer
- The fraction part contains exactly one digit <br />
For example, the numbers 3.2, 5.0, and 1234.5 can be represented as (3, 2), (5, 0), and (1234, 5) respectively.

The K-AVL tree class contains the following functions:
- A constructor that takes k as parameter and constructs an empty K-AVL tree
- A function to insert a decimal value into the K-AVL tree
- A function to delete a decimal value from the K-AVL tree
- A function to search a decimal value in the K-AVL tree
- A function to search the decimal value in the K-AVL tree that is closest to a value you specify
- A function to traverse and print the K-AVL tree in LNR (in-order traversal)
- A function to traverse and print the K-AVL tree in NLR (pre-order traversal)
- A destructor to clean up memory

# Insert Function

Function for inserting a new decimal value into the K-AVL tree.

Passing the string command `"insert [whole part] [decimal part]"` via argv[1], the program should print:
- `[whole part].[decimal part] inserted`
- Print nothing if the decimal value is already in the K-AVL tree upon inserting

Example:
Passing the command `"insert 9 3"` will output:
- `9.3 inserted`, if "9.3" is not in the K-AVL tree before inserting
- Print nothing if "9.3" is already in the K-AVL tree before inserting

# Search Function

Function for searching a decimal value in the K-AVL tree.

Passing the string command `"search [whole part] [decimal part]"` via argv[1], the program should print:
- `[whole part].[decimal part] found`, if the decimal value is in the K-AVL tree
- `[whole part].[decimal part] not found`, if the decimal value is not in the K-AVL tree

Example:
Passing the command `"search 9 3"` will output:
- `9.3 found`, if "9.3" is in the K-AVL tree
- `9.3 not found`, if "9.3" is not in the K-AVL tree

# Delete Function

Function for deleting a decimal value from the K-AVL tree. <br />

- Note: to delete an internal node of the tree, first replace the node with with its in-order predecessor and then delete the predecessor

Passing the string command `"delete [whole part] [decimal part]"` via argv[1], the program should print:
- `[whole part].[decimal part] deleted`, if the decimal value was in the K-AVL tree before deletion
- Print nothing if the decimal value is not in the K-AVL tree before deletion

Example:
Passing the command `"delete 9 3"` will output:
- `9.3 deleted`, if "9.3" is in the K-AVL tree before deletion
- Print nothing if "9.3" is not in the K-AVL tree before deletion

# Approximate Search Function

Function for searching the decimal value in the K-AVL tree that is closest to a value you specify.

- Note: the program considers the value with smallest absolute difference as the closest value.
        If there are more than one values having the same absolute difference, the smallest of them is considered.

Passing the string command `"approx_search [whole part] [decimal part]"` via argv[1], the program should print:
- `closest to [whole part].[decimal part] is [whole part].[decimal part]`, if the value is in the K-AVL tree
- `closest to [whole part].[decimal part] is [whole part 1].[decimal part 1]`, if the value is closest to specified value
- Print nothing if the K-AVL tree is empty

Example:
Passing the command `"approx_search 9 3"` will output:
- `closest to 9.3 is 9.3`, if "9.3" is in the K-AVL tree
- `closest to 9.3 is 8.8`, if "8.8" is the closest value to "9.3"
- Print nothing if the K-AVL tree is empty

# Tools and Concepts
- Languages: C++
- VSCode
- Object-Oriented Programming (OOP)
- Recursion
- AVL Search trees
- Pointers

# Running and Testing the Project

You can run and test the project by running the following command:

- `if ($?) { g++ k_AVL.cpp main.cpp -o k_AVL }; if ($?) { .\k_AVL "insert argv[1] string argument here" }`

- Note: replace `insert argv[1] string argument here` with a string argument that begins with the value of K followed by a comma and a series of commands separated by a comma

- Note: the `{ g++ k_AVL.cpp main.cpp -o k_AVL }` command compiles the k_AVL.cpp and main.cpp files, producing a K_AVL executable file

Example: <br />
The command `if ($?) { g++ k_AVL.cpp main.cpp -o k_AVL } ; if ($?) { .\k_AVL "2, insert 2 2, insert 5 2, search 2 2, approx_search 5 1, in_order, pre_order, delete 2 2" }` will output: <br />

`2.2 inserted` <br />
`5.2 inserted` <br />
`2.2 found` <br />
`closest to 5.1 is 5.2` <br />
`Printing the K-AVL tree in LNR (in-order traversal): 2.2 5.2` <br />
`Printing the K-AVL tree in NLR (pre-order traversal): 2.2 5.2` <br />
`2.2 deleted` <br />