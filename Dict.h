#include"BST.h"

class Dictionary{
    private:
        const int size = 52; // 26 + 26: uppercase + lowercase + digits
                             // from 0 to 25 is the lower case letters
                             // from 26 to 51 is the upper case letters
        BST** wordsList;    // wordsList is a pointer that is pointing to an array of pointers to a BSTs
        vector<string> input_words;
    public:
        Dictionary();
        void build_dictionary(); // initialize the dictionary from a file
        void insert();
        void remove();
        int findIndex(string k);
        void printDictionary();
        bool check_spelling(string k);
        void read_input();
        void print_input();
        void remove_dots(string &s);
        void check_input();
        int get_dictionary_size();
        void store_dictionary(); // this will print 52 lines each one of them is the tree of a given character
        void load_dictionary();
        void update_dictionary();
        vector<string> get_nodes_from_line(const string& line);
        void insert_a_word(string k);
        void continue_checking();
        
         
        

};