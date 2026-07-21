/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        /*So How i would solve this:
        1)Since the index isn given we use a hashmap , firstly we store al the pointers we seen so far 
        2) we iterate throught the linked list if we reach a pointer we seen before  we return true
        3) if pointer is equal to null ptr we return false 
        */

        ListNode* current = head;
        set<ListNode*> seen;
        while (current != nullptr){
            if (seen.find(current)!= seen.end()){
                return true;
            }
            else if (current == nullptr){
                return false;
            }
            seen.insert(current);
            current = current->next;


        }

        return false;

        
    }
};
