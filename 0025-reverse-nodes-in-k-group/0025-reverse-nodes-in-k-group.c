/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int count(struct ListNode* head){
    int co=0;
    while(head!=NULL){
        co++;
        head=head->next;
    }
    return co;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int co=count(head);
    struct ListNode*prev=NULL;
    struct ListNode* curr=head;
    struct ListNode* temp;
    int c=0;
    while(curr!=NULL && c<k){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        c++;
	}
    if(temp!=NULL && (co-c)>=k){
        head->next=reverseKGroup(temp,k);
    }
    else{
        head->next=temp;
    }
    return prev;
}