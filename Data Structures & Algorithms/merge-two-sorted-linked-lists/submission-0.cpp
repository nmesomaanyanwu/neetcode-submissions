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
ok so basically we go to the end of the first node and connect the head of the second one to the first one and then rreturn it

*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy; 
        ListNode* l1 = list1;
        ListNode* l2 = list2; 

        if (list1 == nullptr){
            return list2;
        }
        if (list2 == nullptr){
            return list1;
        }

        while ((l1 != nullptr) && (l2 != nullptr)){
            if ((l1->val <= l2->val)){
                tail->next = l1;
                l1 = l1->next;
                tail = tail ->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
                tail = tail ->next;

            }
            
        }

        tail->next = (l1 != nullptr)? l1:l2;

        return dummy.next;
        
    }
};
