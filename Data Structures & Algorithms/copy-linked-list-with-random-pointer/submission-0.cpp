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
        unordered_map <Node*, Node*> clone;
        clone[nullptr] = nullptr;
        auto curr = head;
        while(curr){
            if(clone.find(curr) == clone.end()){
                clone[curr] = new Node(curr->val);
            }
            auto dupe = clone[curr];
            if(curr->next && clone.find(curr->next) == clone.end()){
                clone[curr->next] = new Node(curr->next->val);
            }
            dupe->next = clone[curr->next];
            if(curr->random && clone.find(curr->random) == clone.end()){
                clone[curr->random] = new Node(curr->random->val);
            }
            dupe->random = clone[curr->random];

            curr = curr->next;
        }

        return clone[head];
    }
};