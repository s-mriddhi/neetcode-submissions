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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* tail = dummy;
        int carry =0;
        while(l1||l2||carry){
            int val1 = 0;
            if(l1) {val1= l1->val; l1=l1->next;}
            int val2 = 0;
            if(l2) {val2 =l2->val; l2= l2->next;}
            int val = val1 + val2 + carry;
            carry = val/10;
            val = val%10;
            tail->next = new ListNode(val, nullptr);
            tail = tail->next;
        }

        return dummy->next;
    }
};
