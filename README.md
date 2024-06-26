﻿# Spelling Checker Application

## Introduction
This spelling checker application is designed to efficiently check the spelling of words against a dictionary. It utilizes an array of binary search trees (BST) data structure to store the dictionary words and provides functionality to insert new words, remove existing ones, and suggest corrections for misspelled words. Basically an open-source Grammarly!

## Usage
1. **Building the Dictionary**
   - The dictionary is initialized by reading from a file using the `build_dictionary()` method.
   - This method populates the dictionary with words and organizes them into an array of Binary Search Trees for efficient retrieval.

2. **Checking Spelling**
   - The `check_spelling(string k)` method is used to verify whether a given word `k` exists in the dictionary.
   - If the word is not found, the application suggests The closes five words to it using the Hamming-Distance Algorithm. 

3. **Adding and Removing Words**
   - Words can be added to the dictionary using the `insert(string k)` method.
   - Existing words can be removed using the `remove(string k)` method.

4. **Updating the Dictionary**
   - The `update_dictionary()` method allows for modifications to the dictionary, such as adding or removing words.
   - After updating, the dictionary is stored back to the file for future use.

5. **Input Processing**
   - Input words can be read from the user or a file using the `read_input()` method.
   - The application then checks the spelling of each input word and provides feedback.

6. **Storing the Dictionary**
   - The `store_dictionary()` method uses an in-oreder traversal to save each tree of the array.
   - Each character's BST is stored in a separate line, ensuring efficient retrieval.

## Classes and Methods
- **Dictionary Class**
   - Manages the overall functionality of the spelling checker application.
   - Key Methods:
       - `build_dictionary()`: Initializes the dictionary from a file.
       - `check_spelling(string k)`: Checks the spelling of a word.
       - `insert(string k)`: Adds a word to the dictionary.
       - `remove(string k)`: Removes a word from the dictionary.
       - `update_dictionary()`: Updates the dictionary after modifications.
       - `read_input()`: Reads input words for spelling checks.
       - `store_dictionary()`: Saves the dictionary back to the file.

- **BST Class**
   - Implements the binary search tree data structure for efficient word storage and retrieval.
   - Key Methods:
       - `insert(string k)`: Inserts a word into the BST.
       - `remove(string k)`: Removes a word from the BST.
       - `suggestClosestWords(string k)`: Suggests closest words for misspelled words.
       - `traverseInOrder()`, `traversePreOrder()`, `traversePostOrder()`: Traversal methods for the BST.
       - `graph(int indent, Node* aroot)`: Draws the tree structure for visualization.
       - `maxDepth(Node* node)`: Calculates the maximum depth of the BST.

## File Structure
- `Dict.h`: Header file containing the Dictionary class declaration.
- `BST.h`: Header file containing the BST class declaration.
- `main.cpp`: Main application file where the Dictionary class is instantiated and used.

## Dependencies
- Standard C++ libraries: `<iostream>`, `<string>`, `<iomanip>`, `<queue>`, `<vector>`, `<map>`, `<stack>`, `<fstream>`.
- Ensure the appropriate inclusion of these libraries in the compilation environment.

## Compilation and Execution
- Compile the application using a C++ compiler, ensuring all necessary files are included.
- Execute the compiled binary to run the spelling checker application.

## Contributors
- This application was developed by Kyrollos Zakaria as part of Applied Data Structures Course.

