/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA=headA,*currB=headB;
        unordered_map<ListNode *,int>map;
        if(!currA || !currB) return nullptr;
        while(currA){
            map[currA]++;
            if(map[currA]>1) return currA;
            currA=currA->next;
        }
        while(currB){
            map[currB]++;
            if(map[currB]>1) return currB;
            currB=currB->next;
        }
        

        return nullptr;
    }
};