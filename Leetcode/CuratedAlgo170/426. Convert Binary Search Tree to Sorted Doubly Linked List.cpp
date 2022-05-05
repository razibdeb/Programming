/*
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

 

Example 1:



Input: root = [4,2,5,1,3]


Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

Example 2:

Input: root = [2,1,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
All the values of the tree are unique.

*/



/*
Facebook|73
Amazon|4
ByteDance|3
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
/*
no help
Runtime: 4 ms, faster than 87.55% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.
Memory Usage: 7.6 MB, less than 81.47% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.
*/
class Solution {
public:
    
    Node *head;
    Node *prev;

    Node* treeToDoublyList(Node* root) {
        
        if(root == nullptr) return nullptr;
        
        head = nullptr;
        prev = nullptr;
        
        visit(root);
        
        head->left = prev;
        prev->right = head;
        
        return head;
    }
    
    void visit(Node *root) {
        if(root == nullptr) return;
        
        visit(root->left);
        
        
        Node *right = root->right;
        if(prev == nullptr) {
            head = root;
        } else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        
        
        visit(right);
    }
};


/*

Complexity Analysis

Time complexity : 
O(N)
O(N) since each node is processed exactly once.
Space complexity : 
O(N)
O(N). We have to keep a recursion stack of the size of the tree height, which is 
O(logN)
O(logN) for the best case of completely balanced tree and 
O(N)
O(N) for the worst case of completely unbalanced tree.
*/