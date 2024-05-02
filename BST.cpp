#include "BST.h"

BST::BST()
{ 
    root = nullptr;
    size = 0;
}

bool BST::isLessThan(string k, string other_k) // returns true if k is less than other_k
{
    // TODO: accommodate for case sensitivity
    int min_l = min(k.length(), other_k.length());
    int i = 0;
    while(i < min_l){
        if(k[i] < other_k[i]) return true;
        else if (k[i] > other_k[i]) return false;
        else i++;
    }
    return (k.length() < other_k.length());
}




void BST::insert(string k)
{ 
    Node* p = new Node(k);
    // check if the tree is empty, so insert a head
    if(root == nullptr){
        // cout << "inside insert - if";
        root = p;
    }
    else {
        // cout << "inside insert - else";
        Node *ptr;
        Node *parent;
        ptr = root;
        while(ptr != NULL) {
            parent = ptr;
            if(isLessThan(k ,ptr->key)) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if(isLessThan(k, parent->key)) {
            parent->left = p;
        } else {
            parent->right = p;
        }
    } 
    size++;
}
void BST::traverseInOrder(){
    traverseInOrder_helper(root);
}
void BST::traverseInOrder_helper(Node* ptr){
    if(ptr != NULL) {
        traverseInOrder_helper(ptr->left);
        cout << ptr->key << endl;
        traverseInOrder_helper(ptr->right);
    }
}

void BST::graph(int indent, Node* aRoot){
    if (aRoot != NULL)
    { 
        graph (indent+8, aRoot->right);           
        cout << setw(indent) << " " << aRoot->key << endl; 
        graph (indent+8, aRoot->left); 
    }
}
Node* BST::get_root(){
    return root;
}


void BST::graph_straight(int indent) {
        int h = maxDepth(root);
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();
                cout << setw(h*indent + ((h)* i*indent/2) ) << current->key << " ";
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            h--;
            std::cout << std::endl;
        }
    }


int BST::maxDepth(Node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

bool BST::isExistant(string k){
    Node* cur = root;
    while(cur != nullptr)
    {    
        if(k == cur->key){
            return true;
        }
        else if(isLessThan(k, cur->key)){
            cur=cur->left;
        }
        else cur=cur->right;
    }
    return false; // if the tree is empty or we did not find the word.
}

int BST::calculateHammingDistance(string a, string b){
    int max_l = max(a.length(), b.length());
    int min_l = min(a.length(), b.length());
    int numMatches = 0;
    for(int i =0; i <min_l; i++){
        if(a[i] == b[i]) numMatches++;
    }
    return max_l - numMatches;
}

vector<string> BST::suggestClosestWords(string k){
    multimap<int, string> distanceMap;
    vector<string> suggestions;
    if (root == nullptr) {
        cout << "The tree is empty.\n No suggestions provided.\n";
        return {};
    }
    stack<Node*> stack;
    stack.push(root);
    while (!stack.empty()) {
        Node* cur = stack.top();
        stack.pop();
        int d = calculateHammingDistance(cur->key, k); // calculating the distance between each node and the given word k.
        distanceMap.emplace(d,cur->key);
        if (cur->right != nullptr) {
            stack.push(cur->right);
        }
        if (cur->left != nullptr) {
            stack.push(cur->left);
        }
    }
    // we finished traversing, now we need to return the first five elements:
    multimap<int, string>:: iterator it = distanceMap.begin();
    int i = 0;
    while(i < 5 && it != distanceMap.end()){
        // cout << "map: " << it->first << " " << it->second << " \n";
        suggestions.push_back( it->second );
        i++;
        it++;
    }
    return suggestions;
}
int BST::get_tree_size(){
    Node* cur = root;
    if (cur == nullptr) return 0;
    queue<Node *> q;
    q.push(cur);
    int count = 0;
    while(!q.empty()){
        count++;
        if(cur->left != nullptr) q.push(cur->left);
        if(cur->right != nullptr) q.push(cur->right);
        q.pop();
        cur = q.front();
    }
    return count;
}
void BST::store_BST(Node* cur, ofstream &outFile){
    // In-order traversal
    if (cur == nullptr) {
        return;
    }
    store_BST(cur->left, outFile);
    outFile << cur->key << " "; // Write key to file with space separator
    store_BST(cur->right, outFile);
}



Node* BST::build_BST_from_InOrder_helper(const vector<string>& inOrder, int start, int end) {
    if (start > end) {
        return nullptr; // Base case: Empty subtree
    }

    // Find the middle element as the root node
    int mid = start + (end - start) / 2;
    Node* root = new Node(inOrder[mid]);

    // Recursively build left and right subtrees
    root->left = build_BST_from_InOrder_helper(inOrder, start, mid - 1);
    root->right = build_BST_from_InOrder_helper(inOrder, mid + 1, end);

    return root;
}

Node* BST::build_BST_from_InOrder(const vector<string>& inOrder) {
    return build_BST_from_InOrder_helper(inOrder, 0, inOrder.size() - 1);
}

void BST::set_root(Node* p){
    root = p;
}
vector<string> BST::get_nodes_from_line(const string& line){
    vector<string> nodes;
    istringstream iss(line);
    string word;
    while (iss >> word) {
        nodes.push_back(word);
    }
    return nodes;
}

void BST::build_tree(const string& line){
    vector<string> nodes = get_nodes_from_line(line);
    Node* p = build_BST_from_InOrder(nodes);
    cout << "build tree";
    set_root(p);
}
