class Node{
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int key,int val){
            this->key=key;
            this->val=val;
            prev=nullptr;
            next=nullptr;
        }
};

class LRUCache {
    int cap;
    unordered_map<int,Node *>map;
    int key,val;
    Node *head;
    Node *tail;

    void insert(Node *node){
        if(tail==nullptr){
            tail=node;
            head=node;
            return;
        }
        tail->next=node;
        node->prev=tail;
        node->next=nullptr;
        tail=node;
    }

    void remove(Node *node){
        if(head==tail){
            head=nullptr;
            tail=nullptr;
        }
        else if(node==head){
            head=head->next;
            head->prev=nullptr;
        }
        else if(node==tail){
            tail=tail->prev;
            tail->next=nullptr;       
        }
        else{
            node->prev->next=node->next;
            node->next->prev=node->prev;
        }
        
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=nullptr;
        tail=nullptr;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()){
            return -1;
        }
        else{
            Node *newnode=map[key];
            remove(newnode);
            insert(newnode);
            
            return newnode->val;
            
        }
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            remove(map[key]);
            map.erase(key);
        
        }
        Node *newnode=new Node(key,value);
        map.insert({key,newnode});
        insert(newnode);

        if(map.size()>cap){
            map.erase(head->key);
            remove(head);  
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */