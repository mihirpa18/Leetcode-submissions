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
    ListNode* reverseLL(ListNode *head){
        ListNode *curr=head,*prev=nullptr;
        while(curr!=nullptr){
            ListNode *nn=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nn;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *head2=reverseLL(slow->next);
        slow->next=nullptr;

        while(head!=nullptr && head2!=nullptr){
            ListNode *nxt1=head->next;
            ListNode *nxt2=head2->next;
            head->next=head2;
            head2->next=nxt1;  
            head=nxt1;
            head2=nxt2;
        }

    }
};