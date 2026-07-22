/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        firstly ;
        1) We do two passes we create the nodes the first pass
        2) the second pass we connect them
        */

        unordered_map<Node*, Node*> oldtonew;

        
        Node* current = head;

        while (current != nullptr){
            Node* copy = new  Node(current->val);
            oldtonew[current] = copy;
            current = current->next;

        }

        current = head;
        while (current != nullptr){
            Node* copy =  oldtonew[current];
            copy-> next = oldtonew[current->next];
            copy->random = oldtonew[current->random] ;
            current = current->next;
        
        }



        return oldtonew[head];
        
    }
};
