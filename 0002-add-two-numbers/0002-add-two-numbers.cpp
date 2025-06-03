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
        ListNode *prev=nullptr;
        ListNode *curr=head;
        ListNode *nxt=nullptr;
        while(curr!=nullptr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res=nullptr;
        ListNode *curr=nullptr;
        int sum;
        int c=0;
        while(l1!=nullptr || l2!=nullptr || c!=0){
            sum=c;
            if(l1!=nullptr){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                sum+=l2->val;
                l2=l2->next;
            }
            c=sum/10;
            ListNode *newnode=new ListNode(sum%10);

            if(curr==nullptr){
                curr=newnode;
                res=curr;
            }
            else{
                curr->next=newnode;
                curr=curr->next;
            }
            
        }
        return res;
    }
};