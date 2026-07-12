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
    ListNode* getkthNode(ListNode* node, int k){
        auto curr = node;
        while(curr && k){
            curr = curr->next;
            k--;
        }
        return curr;
    }
    ListNode* reverse(ListNode* first, ListNode* last){
        ListNode * stop = last->next;
        ListNode* curr = first;
        ListNode* prev = nullptr;
        while(curr != stop){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev_end = dummy;
        while(true){
            ListNode * kth = getkthNode(prev_end, k);
            if(!kth){
                break;
            }
            ListNode* groupStart = prev_end->next;
            ListNode* next_start = kth->next;
            reverse(groupStart, kth);
            prev_end->next = kth;
            groupStart->next = next_start;

            prev_end = groupStart;
        }
        return dummy->next;
    }
};
