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
        ListNode dummy;
        dummy.next = head;
        ListNode* sp = &dummy;
        ListNode* fp = &dummy;

        for (int i = 0; i < (n + 1); i++){
            fp = fp->next;
        }

        while (fp != nullptr){
            sp = sp->next;
            fp = fp->next;
        }

        sp->next = sp->next->next;

        return dummy.next;
    }
};