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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *curr=head;
        ListNode *prev=nullptr;
        while(curr && curr->next){
            ListNode *nxt=curr->next;
            ListNode *itr=nxt->next;
            nxt->next=curr;
            curr->next=itr;
            if(prev!=nullptr){
                prev->next=nxt;
            }
            else{
                head=nxt;
            }
            prev=curr;
            curr=itr;
            
        }
        return head;
    }
};