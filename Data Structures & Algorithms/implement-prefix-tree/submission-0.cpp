class PrefixTree {
    struct TrieNode{
        TrieNode* children[26]={};
        bool isEnd =false;
    };

    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto& ch : word){
            if (!cur->children[ch -'a']){
                cur->children[ch - 'a'] = new TrieNode();
            }
            cur = cur->children[ch - 'a'];
        }
        cur->isEnd = true;
        
    }
    
    bool search(string word) {
        TrieNode* cur = root; 
        for (char ch : word){
            if (cur->children[ch -'a']){
                cur = cur->children[ch - 'a'];
            }
            else{
                return false;
            }
            
        }
        return cur->isEnd;

        
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root; 
        for (char ch : prefix){
            if (cur->children[ch -'a']){
                cur = cur->children[ch - 'a'];
            }
            else{
                return false;
            }
            
        }
        
        return true;
        
    }
};
