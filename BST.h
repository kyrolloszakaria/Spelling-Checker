#include<iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <fstream>
using namespace std;

class Node
{
    public:
        string key; 	// key 
        Node *left;	    // left subtree	       
        Node *right;	// right subtree
        Node(string k) {key = k; left = nullptr; right = nullptr;}
}; // end of class Node declaration


class BST{
    private:
        Node* root;
        int size;
    public:
        BST();
        Node* get_root();
        void insert(string k);
        bool isEmpty();
        bool isExistant(string k);
        vector<string> suggestClosestWords(string k);
        void traverseInOrder();
        void traverseInOrder_helper(Node* ptr);
        void traversePreOrder();
        void traversePostOrder();
        void traverseBFS(); // level order traversal
        void traverseBFS_helper(Node* ptr);
        void remove(string k);
        void graph(int indent, Node* aroot); // to draw the tree
        bool isLessThan(string k, string other_k); // returns true if k is less than other_k
        void graph_straight(int indent);
        int  maxDepth(Node* node);
        int calculateHammingDistance(string a, string b);
        int get_tree_size();
        void store_BST(Node* cur, ofstream &outFile); // using in-order traversal;
        Node* build_BST_from_InOrder(const vector<string>& inOrder);
        Node* build_BST_from_InOrder_helper(const vector<string>& inOrder, int start, int end);
        void set_root(Node* p);
        vector<string> get_nodes_from_line(const string& line);
        void build_tree(const string& line);


};