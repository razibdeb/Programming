/*
Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

The left subtree values are less than the value of their parent (root) node's value.
The right subtree values are greater than the value of their parent (root) node's value.
Note: A subtree must include all of its descendants.

 

Example 1:



Input: root = [10,5,15,1,8,null,7]
Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.
Example 2:

Input: root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-104 <= Node.val <= 104

Facebook 6
ByteDance
Amazon
Microsoft

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
approach: 

one function which will return the size of the BST on this node, -1 if not

check left sub tree-> get size
check right sub tree-> get size
if current value is in range
    if  both positive then size is sum of left right + 1
else set invalid range

*/

/*
Runtime: 4 ms, faster than 98.85% of C++ online submissions for Largest BST Subtree.
Memory Usage: 21.2 MB, less than 37.86% of C++ online submissions for Largest BST Subtree.
*/

class Solution {
public:
    int maxSize;
    
    int largestBSTSubtree(TreeNode* root) {
        if(root == nullptr) return 0;
        maxSize = 1;
        int max, min;
        getMaxBST(root, max, min);
        return maxSize;
    }
    
    int getMaxBST(TreeNode * root, int &maxx, int &minn) {
        if(root == nullptr) {
            maxx = INT_MIN;
            minn = INT_MAX;
            return 0;
        }
        int size = -1;
        int lMax, lMin, rMax, rMin;
        
        int l = getMaxBST(root->left, lMax, lMin);
        int r = getMaxBST(root->right, rMax, rMin);
        
        
        //cout<<"For Node "<<root->val<<" lMax "<<lMax <<"  rMin "<<rMin<<endl;
        
        if(lMax < root->val && root->val < rMin) {
            size = l + r + 1;
            
            if(maxSize < size) maxSize = size;
            
            minn = min(root->val, lMin);
            maxx = max(root->val, rMax);

            //cout<<"For Node parent"<<root->val<<" max "<<maxx <<"  min "<<minn<<endl;
        } else {
            maxx = INT_MAX;
            minn = INT_MIN;
        }
        //[2,3,null,1]
        return size;
    }
    
};