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
        /*Slow pointer / fast pointer 
        1) We firstly make a fastpointer that points to the second element  and slow pointer that points to the head of the linkedlist like the node
        2) then each time we do current = current.next for the SP we do current.next.next for tthe fast pointer
        4) if sp and fp reach we know this is a cycle 
        5) if fp ever reaches nullptr we return false
        */
        if (head == nullptr) return false;


        ListNode* sp = head; // slow pointer
        ListNode* fp = head; // fast pointer 

        while (fp != nullptr && fp->next != nullptr){
            fp = fp->next->next;
            sp = sp->next;

            if (fp == sp){
                return true;
            }
            

        }

        return false;
        
    }
};
