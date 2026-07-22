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

 /*
 [0,1,2,3,4,5,6]
 okay so i'll say we can do this with two pointers 
 1. We have two pointers  one short pointer and another fast pointer : when the ast pointer reaches the end of the list the other pointer is halfway
 2. then from the start of the of short pointer to the end reverse and then we make two lists
 
 */

class Solution {
public:
    void reorderList(ListNode* head) {


        ListNode* start = head;
        ListNode* sp = head; // slow pointer 1 step at a time
        ListNode* fp = head ;// fast pointer 2 step at a time

        //get the right pointer positions
        while (fp->next  != nullptr && fp->next->next != nullptr){
            sp = sp->next;
            fp = fp->next->next; 

        }
        // now sp.next would be the end of the reversed list while fp will be th e head 
         ListNode* current = sp->next;
         sp->next = nullptr;
         ListNode* prev = nullptr;

        while(current != nullptr){
             ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } 
        //current = head;
        current = prev;

        while(current != nullptr && start != nullptr){
             ListNode* currentnext =current->next;
             ListNode* startnext = start->next;
            start->next = current;
            current->next = startnext;
            
            current = currentnext;
            start = startnext; 

        }
        if (start != nullptr) start->next = nullptr;



        
    }
};
