/*

450. Delete Node in a BST Medium

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Runtime: 66 ms, faster than 31.69% of C++ online submissions for Delete Node in a BST.
Memory Usage: 32.8 MB, less than 41.81% of C++ online submissions for Delete Node in a BST.
*/
class Solution {
public:
    
    int getNextAndDelete(TreeNode * node) { //successor
        TreeNode *parent = node;
        node = node->right;
        while(node->left != nullptr) {
            parent = node;
            node = node->left;
        }
        int value = node->val;
        if(node->right == nullptr) {
            if(parent->right == node)
                parent->right = nullptr;
            else
                parent->left = nullptr;
        }
        else {
            if(parent->right == node)
                parent->right = node->right;
            else 
                parent->left = node->right;
        }
        return value;
    }
    
    int getPrevAndDelete(TreeNode * node) {
        TreeNode * parent = node;
        
        node = node->left;
        
        while(node->right != nullptr) {
            parent = node;
            node = node->right;
        }
        int value = node->val;
        
        if(node->left == nullptr) {
            if(parent->left == node) parent->left = nullptr;
            else parent->right = nullptr;
        }
        else {
            if(parent->right == node)
                parent->right = node->left;
            else 
                parent->left = node->left;
        }
        return value;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        
        if(root->val < key) { 
            root->right = deleteNode(root->right, key);
            return root;
        }
        else if(root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        
        if(root->left == nullptr && root->right == nullptr) return nullptr;
        
        if(root->left != nullptr) {
            int value = getPrevAndDelete(root);
            root->val = value;
        } else {
            int value = getNextAndDelete(root);
            root->val = value;
        }
        return root;
        /*
        TreeNode *node = root;
        //TreeNode * parent = root;
        while(node != nullptr) {
            if(node->val == key) {
                //delete
                if(node->left == nullptr && node->right == nullptr) {
                    node = nullptr;
                    return root;
                } else if(node->left != nullptr) {
                    int value = getPrevAndDelete(node);
                    node->val = value;
                } else if(node->right != nullptr) {
                    int value = getNextAndDelete(node);
                    node->val = value;
                }
            } else if(node->val > key) {
                node = node->left;
            } else if(node->val < key) {
                node = node->right;
            }
        }
        return root;
        */
    }
};