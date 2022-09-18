/*
146. LRU Cache Medium

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/
class Node {
public:
    int val;
    int key;
    Node *prev, *next;
    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
/*
Runtime: 789 ms, faster than 18.37% of C++ online submissions for LRU Cache.
Memory Usage: 165 MB, less than 81.83% of C++ online submissions for LRU Cache.
*/
class LRUCache {
public:
    int capacity;
    int size;
    Node *head, *tail;
    
    unordered_map<int, Node *> data; //key Node
    
    LRUCache(int c) {
        capacity = c;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        // cout<<"GET "<<key<<endl;
        if(data.find(key) == data.end()) return -1;
        
        int result = data[key]->val;
        
        Node *node = data[key];
        if(key == 3) {
            int a = 1;
        }
        promote(node);
        // Node *tmp = head;
        // cout<<"\t";
        // while(tmp != nullptr) {
        //     cout<<tmp->val<<" ";
        //     tmp = tmp->next;
        // }
        // cout<<endl;
        // tmp = tail;
        // while(tmp != nullptr) {
        //     cout<<tmp->val<<" ";
        //     tmp = tmp->prev;
        // }
        // cout<<endl;
        // cout<<"==============="<<endl;
        return  result;
        
    }
    
    void put(int key, int value) {
        if(value == 5) {
            int a = 1;
        }
        // cout<<"PUT "<<key<<" "<<value<<endl;
        
        if(data.find(key) == data.end()) { //add
            Node * node = new Node(key, value);
            if(head == nullptr) {
                // cout<<"First node"<<endl;
                head = node;
                tail = node;
                data[key] = node;
                size++;
                return;
            } 
            node->next = head;
            head->prev = node;
            head = node;
            data[key] = node;
            
            if(size < capacity) {
                size++;
            } else {
                
                Node *newTail = tail->prev;
                if(newTail == nullptr) {
                    
                } else {
                    newTail->next = nullptr;
                }
                data.erase(tail->key);
                delete tail;
                
                tail = newTail;
                //delete tail
            }
        } else {
            Node * node = data[key];
            node->val = value;
            promote(node);
        }
        // Node *tmp = head;
        // cout<<"\t";
        // while(tmp != nullptr) {
        //     cout<<tmp->val<<" ";
        //     tmp = tmp->next;
        // }
        // cout<<endl;
        // tmp = tail;
        // cout<<"\t";
        // while(tmp != nullptr) {
        //     cout<<tmp->val<<" ";
        //     tmp = tmp->prev;
        // }
        // cout<<endl;
        // cout<<"==============="<<endl;
    }
    
    void promote(Node * node) {
        if(node == head) return;
        
        // Node *tmp = tail;
        // cout<<"\t before promote ";
        // while(tmp != nullptr) {
        //     cout<<tmp->val<<" ";
        //     tmp = tmp->prev;
        // }
        // cout<<endl;
        
        if(node == tail) {
            tail = node->prev;
            tail->next = nullptr;
            
            node->next = head;
            node->prev = nullptr;
            head->prev = node;
            head = node;
        } else {
            Node *next = node->next;
            Node *prev = node->prev;
            prev->next = next;
            next->prev = prev;
            
            node->prev = nullptr;
            node->next = head;
            head->prev = node;
            head = node;
        }
        // cout<<"\t after promote ";
        // tmp = tail;
        // while(tmp != nullptr) {
        //     cout<<tmp->val<<" ";
        //     tmp = tmp->prev;
        // }
        // cout<<endl;
        // cout<<"==============="<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */