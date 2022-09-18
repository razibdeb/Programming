/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/
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
    
    /*
    approach: 
    each node's copy will be in nodes next
    copy node's next will be cur node's next
    
    A -> B -> C
    A ->a -> B -> b -> C->c
    a b c is copy
    
    
    */
    /*
    Runtime: 16 ms, faster than 39.47% of C++ online submissions for Copy List with Random Pointer.
Memory Usage: 11.3 MB, less than 27.11% of C++ online submissions for Copy List with Random Pointer.
    */
    Node* copyRandomList(Node* head) {
        
        Node *cur = head;
        while(cur != nullptr) {
            Node *copyNode = new Node(cur->val);
            
            Node *originalNext = cur->next;
            
            cur->next = copyNode;
            copyNode->next = originalNext;
            cur = originalNext;
        }
        
        cur = head;
        //set the random
        while(cur != nullptr) {
            
            Node * copyNode = cur->next;
            
            Node * originalRandom = cur->random;
            if(originalRandom != nullptr)
                copyNode->random = originalRandom->next;
            
            cur = cur->next->next;
        }
        
        cur = head;
        Node *result = nullptr;
        Node *copyCur = result;
        while(cur != nullptr) {
            
            if(result == nullptr) {
                result = cur->next;
                copyCur = result;
            } else {
                copyCur->next = cur->next;
                copyCur = copyCur->next;
            }
            
            if(cur->next != nullptr) {
                Node *curNext = cur->next->next;
                cur->next = curNext;
                cur = curNext;
            }
            else 
                break;
        }
        return result;
    }
    /*
    approach: 
    store each node's copy node in hash map
    then visit and assign next & random node
    Extra N space
    */
    /*
    Runtime: 6 ms, faster than 93.74% of C++ online submissions for Copy List with Random Pointer.
Memory Usage: 11.3 MB, less than 59.85% of C++ online submissions for Copy List with Random Pointer.
    */
    Node* copyRandomList2(Node* head) {
        unordered_map<Node*, Node*> data;
        Node * cur = head;
        while(cur != nullptr) {
            Node * newNode = new Node(cur->val);
            data[cur] = newNode;
            cur = cur->next;
        }
        
        cur = head;
        Node * copy;
        while(cur != nullptr) {
            
            copy = data[cur];
            Node * next = cur->next;
            Node * random = cur->random;
            
            if(next!= nullptr) {
                copy->next = data[next];
            }
            if(random != nullptr) {
                copy->random = data[random];
            }
            cur = cur->next;
        }
        return data[head];
    }
};