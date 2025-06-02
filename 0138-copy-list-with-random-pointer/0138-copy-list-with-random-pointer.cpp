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
        if(!head) return nullptr;
        Node *copyHead=new Node(head->val);
        Node *oldtemp=head->next,*newtemp=copyHead;
        unordered_map<Node*,Node*>map;
        map[head]=copyHead;

        while(oldtemp!=nullptr){
            Node *temp=new Node(oldtemp->val);
            map[oldtemp]=temp;
            newtemp->next=temp;
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        oldtemp=head;
        newtemp=copyHead;
        while(oldtemp!=nullptr){
            newtemp->random=map[oldtemp->random];
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }

        return copyHead;
    }
};