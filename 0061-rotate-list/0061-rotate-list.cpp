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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 1;
        ListNode *temp = head;

        if(temp == nullptr) return nullptr;

        while(temp->next != nullptr){
            temp = temp->next;
            count++;
        }

        temp->next = head;

        temp = head;

        k = k%count;

        int steps = count - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        ListNode* res = newTail->next;
        newTail->next = nullptr;

        return res;
    }
};