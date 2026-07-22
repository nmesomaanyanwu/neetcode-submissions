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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        1. Reverse the linkedlist
        2. While in the while loop keep updating a count ill you reach n then return the node value 
        */

        ListNode* current = head;
    
        ListNode* prev= nullptr;
        int count = 2;

        // revese
        while (current != nullptr){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        current = prev; // head of the reversed list
        ListNode* s = current;
        ListNode* t = current->next; 


        while (current != nullptr){
            if (n == 0){
                return head;
            }
            if (1 == n){
                ListNode dummy;
                return dummy.next;
            }
            else if (n>= 2 && count == n){
                s->next = t->next;
                t->next = nullptr;
                ListNode* prev = nullptr;

                while (current != nullptr){
                    ListNode* next = current->next;
                    current->next = prev;
                    prev = current;
                    current = next;

                }
                current = prev;
                break;
            }

        }
        
        return current;
    }
};
