/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
        unordered_map<Node*, Node*> copies; //We link every original node to the copy
        queue<Node*> pos; // to keep original nodes we havent checked yet
        Node* current = new Node(node->val);
        copies[node] = current;
        if (node != nullptr){
            pos.push(node);
        }

        while (!pos.empty()){
            Node* original = pos.front();// we get the original node 
            pos.pop();

            for(auto& n : original->neighbors){
                // we check if the original node is in hashmap if not we create the node and keep in queue to explore later 
                if (copies.count(n) == 0){
                    copies[n] = new Node(n->val);
                    pos.push(n);
                }


                // if yes or we just created the node we add the copy of that neighbor into the neighbours of  our new node 
                copies[original]->neighbors.push_back(copies[n]);

            }


        }
        return current;
    }
};
