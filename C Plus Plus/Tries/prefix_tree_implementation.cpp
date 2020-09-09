#define MAX_NODES 26
class Trie {
    struct Trienode
    {
        char val;
        int count;
        int endsHere;
	    vector<Trienode *> child;
        Trienode(){
           child.resize(MAX_NODES);
           count = endsHere = 0;
	    }
    };
    void clear(Trienode *root){
        for(int i = 0; i < 26; i++){
            if(root->child[i] != nullptr){
                clear(root->child[i]);
            }
        }
        delete root;
    }
    
    Trienode *root;
    Trienode *getNode(int index)
    {
        // sets the value acc to index
        // incase of root('/') it cancels out 
        Trienode *newnode = new Trienode;
        newnode->val = 'a'+index;
        newnode->count = newnode->endsHere = 0;
        return newnode;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getNode('/'-'a');
    }
    ~Trie()
    {
        clear(root);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode *curr = root;
        int index;
        for(auto w:word){
            index = w-'a';
            if(curr->child[index]==nullptr)
                curr->child[index] = getNode(index);
            curr->child[index]->count +=1;
            curr = curr->child[index];
        }
        curr->endsHere +=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode *curr = root;
        int index;
        for(auto w:word){
            index = w-'a';
            if(curr->child[index]==nullptr)
                return false;
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *curr = root;
        int index;
        for(auto w:prefix){
            index = w-'a';
            if(curr->child[index]==nullptr)
                return false;
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};