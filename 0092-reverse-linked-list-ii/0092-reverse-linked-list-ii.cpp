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
    ListNode *reverse(ListNode *head){
        if(head==NULL || head->next==nullptr){
            return head;
        }

        ListNode *temp=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;

        return temp;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr=head;
        int c=1;
        while(curr && c<left-1){
            curr=curr->next;
            c++;
        }
        ListNode *tempHead=(left==1?head:curr->next);
        if(tempHead==nullptr) return head;

        ListNode *temp=tempHead;
        c=0;
        while(temp && c<right-left){
            temp=temp->next;
            c++;
        }
        ListNode *nxt;
        if(temp==nullptr){
            return head;
        }
        if(temp->next) nxt=temp->next;
        temp->next=nullptr;

        ListNode *nn=reverse(tempHead);
        if(left==1){
            head=nn;
        }
        else curr->next=nn;
        while(curr->next){
            curr=curr->next;
        }

        curr->next=nxt;

        return head;


    }
};