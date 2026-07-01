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
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        auto slow = head;
        auto fast = head;
        auto first = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        auto second = reverse(slow->next);
        slow->next = nullptr;

        ListNode* dummy = new ListNode(0 , nullptr);
        ListNode* tail = dummy;
        bool flag = true;
        while(first && second){
            if(flag){
                tail->next = first;
                first = first->next;
                tail = tail->next;
            }
            else{
                tail->next = second;
                second = second->next;
                tail= tail->next;
            }
            flag = !flag;
        }
        if(first){
            tail->next = first;
        }
        if(second){
            tail->next = second;
        }
        head = dummy->next;
    }
};