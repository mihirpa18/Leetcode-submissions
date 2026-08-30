class Node{
    public:
        int key;
        int val;
        Node *prev;
        Node *nxt;

        Node(int x,int y) : key(x),val(y),prev(nullptr),nxt(nullptr){}
};

class LRUCache {
public:
    unordered_map<int,Node*>mp;
    int cap;
    int key,val;
    Node *head,*tail;

    void insert(Node *node){
        if(!head){
            head = node;
            tail = node;
            head->nxt = nullptr;
            tail->nxt = nullptr;
            return;
        }

        node->nxt = head;
        head -> prev = node;
        head = node;
        return;
    }

    void remove(Node *node){
        if(node == head){
            head = node->nxt;
            if(head) head->prev = nullptr;
        }
        else if(node == tail){
            tail = tail->prev;
            tail->nxt = nullptr;
        }
        else{
            node->prev->nxt = node->nxt;
            node->nxt->prev = node->prev;
        }
    }

    LRUCache(int capacity) {
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }

        remove(mp[key]);
        insert(mp[key]);

        return mp[key]->val;

    }
    
    void put(int key, int value) {
        if(!mp.count(key)){
            Node *node = new Node(key,value);
            mp[key] = node;
            insert(node);

            if(mp.size() > cap){
                Node *end = tail;
                mp.erase(end->key);
                remove(end);
            }
        }
        else{
            mp[key]->val = value;
            remove(mp[key]);
            insert(mp[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */