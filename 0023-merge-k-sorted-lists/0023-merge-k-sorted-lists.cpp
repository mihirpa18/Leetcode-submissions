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
    ListNode *merge(ListNode *l1,ListNode *l2){
        ListNode *res=new ListNode(0);
        ListNode *curr=res;
        ListNode *head1=l1;
        ListNode *head2=l2;
        while(head1 && head2){
            if(head1->val <= head2->val){
                curr->next=head1;
                head1=head1->next;
                curr=curr->next;
            }
            else{
                curr->next=head2;
                head2=head2->next;
                curr=curr->next;
            }
        }
        while(head1){
            curr->next=head1;
            head1=head1->next;
            curr=curr->next;
        }
        while(head2){
            curr->next=head2;
            head2=head2->next;
            curr=curr->next;
        }
        return res->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return nullptr;
        if(n==1) return lists[0];
        ListNode *res=new ListNode(0);
        
        for(int i=0;i<n;i++){
            res=merge(res,lists[i]);
        }
        return res->next;
    }
};