/*
105. Construct Binary Tree from Preorder and Inorder Traversal Medium

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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
class Solution {
public:

    /*
    Runtime: 27 ms, faster than 72.19% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 26.4 MB, less than 43.41% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
    */
    unordered_map<int, int> indexMap;
        /*
    Runtime: 54 ms, faster than 32.02% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 25.9 MB, less than 92.39% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

without saving the index in hashmap
    */
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //saving index
        for(int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }
        
        
        //without saving index
        int preIndex = 0;
        return solve(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }
    
    TreeNode * solve(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inStart, int inEnd) {
        if(preIndex >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode * node = new TreeNode(preorder[preIndex]);

        int found = indexMap[preorder[preIndex]];
        /*
        //we should save the index in hashmap so that we don't need to search each time
        // 54 ms,
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == preorder[preIndex]) {
                found = i;
                break;
            }
        }
        
        */
        preIndex++;
        
        if(found != -1) {
            node->left = solve(preorder, inorder, preIndex, inStart, found-1);
            node->right = solve(preorder, inorder, preIndex, found+1, inEnd);
        }
        
        
        return node;
    }
};