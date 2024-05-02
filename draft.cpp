#include "Dict.h"


int main(){
   BST bst;
   Dictionary dict;
   ifstream infile("mini_dictionary.txt");
   while(! infile.eof()){
    string s;
    getline(infile, s);
    vector<string> nodes = dict.get_nodes_from_line(s);
    Node* p = bst.build_BST_from_InOrder(nodes);
    bst.set_root(p);
    bst.graph(0, bst.get_root());
   }



}