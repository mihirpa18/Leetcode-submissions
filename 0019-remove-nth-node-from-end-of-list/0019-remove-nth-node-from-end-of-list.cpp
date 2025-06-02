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
        ListNode *slow=head,*fast=head;
        if(head->next==nullptr) return nullptr;
        while(fast->next!=nullptr && n>0){
            fast=fast->next;
            n--;
        }
        if(n>0){
            head=head->next;
            return head;
        }
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        // if(slow==head){
        //     head=head->next;
        //     // delete slow;
        // }
        if(slow->next->next==nullptr){
            slow->next=nullptr;
            // delete slow->next;
            
        }
        else{
            ListNode *temp=slow->next->next;
            slow->next=temp;
            // delete slow->next;
        }
        
        return head;
    }
};