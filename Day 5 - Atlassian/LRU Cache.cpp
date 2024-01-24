class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
public:

    int left_capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;

    LRUCache(int capacity) {
        left_capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void add_node(Node* new_node) {
        
        Node* tail_prev = tail->prev;

        tail_prev->next = new_node;
        new_node->prev = tail_prev;
        new_node->next = tail;
        tail->prev = new_node;
    }

    void delete_node(Node* del_node) {
        Node* prev = del_node->prev;
        Node* next = del_node->next;

        prev->next = next;
        next->prev = prev;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            delete_node(node);
            add_node(node);

            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;

            delete_node(node);
            add_node(node);
        } else {
            if(left_capacity == 0) {
                Node* least_recent_node = head->next;
                cache.erase(least_recent_node->key);
                delete_node(least_recent_node); 
            }

            Node* new_node = new Node(key, value);
            add_node(new_node);
            cache[key] = new_node;

            left_capacity -= left_capacity == 0 ? 0 : 1;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
