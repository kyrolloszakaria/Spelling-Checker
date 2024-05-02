#include "Dict.h"

Dictionary::Dictionary(){

    wordsList = new BST*[size];
    // initialize the wordsList to null.
    for(int i = 0; i < size; i++){
        wordsList[i] = new BST();
    }
}

void Dictionary::build_dictionary(){
    ifstream infile("wordsList.txt");
    if(! infile.is_open()){
        cout << "Error opening the file\n";
        return;
    }
    string tmp;
    while(!infile.eof()){
        infile >> tmp;
        int index = findIndex(tmp);
        if(index == -1){
            cout << "The word " << tmp << " is invalid. We couldn't add to the dictionary.\n";
            continue; 
        }
        wordsList[index]->insert(tmp);
    }
    cout << "Dictionary is built successfully.\n";
}

int Dictionary::findIndex(string k){
    // whether the first character is lower or upper case
    if(  int(k[0]) >= 97 && int(k[0]) <= 122  ) // type casting
    {
        // this character is lower-case
        return (int(k[0]) - 97);
    }
    else if( int(k[0] >= 65 && int(k[0] <= 90)))
    {
        // this character is upper-case
        return (int(k[0]) - 39); // 39 is int('A') - 26
    }
    else{
        // this word is invalid word
        return -1;
    }
}

void Dictionary::printDictionary(){
    for(int i = 0; i < size; i++){
        char c = (i < 26)? char(i+97):char(i+39);
        cout << "Tree for " << c << ": \n\n";
        wordsList[i]->graph(0,wordsList[i]->get_root());
        cout << "-----------------------------------------------------------------------\n";
    }
}

void Dictionary::read_input(){
    cout << "what is your input file name?\n";
    string fileName;
    cin >> fileName;
    ifstream infile(fileName);
    if(!infile.is_open())
    {
        cout << "Error the file could not be open.\n";
        return;
    }
    string tmp;
    while(!infile.eof()){
        infile >> tmp;
        remove_dots(tmp);
        input_words.push_back(tmp);
    }
}

void Dictionary:: print_input(){
    vector<string>::iterator it = input_words.begin();
    while(it != input_words.end()){
        cout << *it << endl;
        it++;
    }
    
}
void Dictionary::remove_dots(string &s) {
    if (!s.empty() && (s.back() == '.' || s.back() == '!' || s.back() == ',')) {
        // cout << "removing the dot: " <<s<< endl;
        s = s.substr(0, s.length() - 1);
        // cout << "after removing the dot: " <<s<< endl;

    }
}
bool Dictionary::check_spelling(string k){
    int index = findIndex(k);
    if (index == -1) {cout << "Error! invalid word."; return false;}
    bool isCorrect = wordsList[index]->isExistant(k); // O(log (n))
    cout << "The word " << k << " is ";
    if (isCorrect) cout << "Correct.\n";
    else cout <<"worng.\n";
    return isCorrect;
}
void Dictionary::check_input(){
    cout << "\n================================================================\n";
    cout << "Checking Your Input ...\n";
    vector<string>::iterator it = input_words.begin();
    while(it != input_words.end()){
        if (! check_spelling(*it) ){
            // the word is wrong, so we need to print out our suggestions
            // or there doesn't exist a tree for this word.
            int index = findIndex(*it);
            if(index == -1) {
                // the tree for the word does not exist
                cout << "We don't have suggestions for this word\n";
                it++;
                continue;
            }
            vector<string> suggestions = wordsList[index]->suggestClosestWords(*it);
            cout << "Maybe you mean: ";
            for(auto s: suggestions) cout << s << ", ";
            cout << "\n";
        }
        it++;
    }
}
int Dictionary::get_dictionary_size(){
    int count = 0;
    for(int i =0; i < size; i++) count += wordsList[i]->get_tree_size();
    cout << "The dictionary size is " << count << ".\n";
    return count;
}

void Dictionary::store_dictionary(){
    ofstream outFile("dictionary.txt");
    for(int i = 0; i < size; i++){
        wordsList[i]->store_BST(wordsList[i]->get_root(),outFile);
        outFile << "\n";
    }
    cout << "Dictionary is stored in dictionary.txt\n";
}

vector<string> Dictionary::get_nodes_from_line(const string& line){
    vector<string> nodes;
    istringstream iss(line);
    string word;
    while (iss >> word) {
        nodes.push_back(word);
    }
    return nodes;
}

void Dictionary::load_dictionary(){
    ifstream infile("dictionary.txt");
    while(! infile.eof()){
        string line;
        getline(infile, line);
        string first_char = line[0] + "x"; // add padding because find index takas a string
        int index = findIndex(first_char);
        wordsList[index]->build_tree(line);
    }
}

void  Dictionary::update_dictionary()
{
    cout << "What words you want to add?\n";
    char c = 'a';
    string s;
    while(c != 'q' && c != 'Q'){
        cout << "Enter the word or the letter q to exit: ";
        cin >> s;
        c = s[0];
        if(c != 'q' && c != 'Q'){
            insert_a_word(s);
            cout << s << " inserted successfully.\n";
        }
    }
    int i;
    cout << "do you want to store the updated dictionary?\n";
    cout << "please enter 1 to update, 2 to ignore: ";
    cin >> i;
    if (i == 1) store_dictionary();
}

void Dictionary::insert_a_word(string k){
    int index = findIndex(k);
    wordsList[index]->insert(k);
}

void Dictionary::continue_checking(){
    cout << "Do you want to check for another file?\n";
    int i = 1;
    while(i != 2){
        cout << "enter 1 to check again, 2 to exit: ";
        int i;
        cin >> i;
        if(i == 2) return;
        read_input();
        check_input();
    }
}