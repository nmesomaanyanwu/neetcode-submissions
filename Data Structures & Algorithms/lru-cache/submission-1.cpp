class LRUCache {
    struct Node{
        int val;
        int key;
        Node* next;
        Node* prev;

        Node (int k , int v) : val(v),key(k), prev(nullptr), next(nullptr){}
    };
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        if (map.find(key)!= map.end()){
            Node* n = map[key];
            remove(n);
            moveToFront(n);
            return n->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (map.find(key)!= map.end()){
            remove(map[key]);
        }
        Node* n = new Node(key , value);
        map[key] = n; 
        moveToFront(n);
        

        if (map.size()> cap){
            Node* lru = tail->prev;
            map.erase(lru->key);
            remove(lru);
            delete(lru);

        }
        
    }

private:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*>  map;

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node ->prev; 
    } 

    void moveToFront(Node* node){
        Node* n = head->next;
        node->prev = head;
        head->next = node;
        node->next = n ; 
        n->prev = node;
    } 

};
