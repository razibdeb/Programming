/*
95. Unique Binary Search Trees II Medium

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 8
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
Runtime: 39 ms, faster than 16.93% of C++ online submissions for Unique Binary Search Trees II.
Memory Usage: 15.9 MB, less than 65.85% of C++ online submissions for Unique Binary Search Trees II.
*/
class Solution {
public:
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
                
        result = DFS(1, n);
        return result;
    }
    
    vector<TreeNode*> DFS(int start, int end) {
        vector<TreeNode*> result;
        
        if(start > end) {
            return result;
        }

        for(int i = start; i <= end; i++) {

            vector<TreeNode*> leftArray = DFS(start, i - 1);
            
            vector<TreeNode*> rightArray = DFS(i + 1, end);
            
            if(leftArray.size() == 0 && rightArray.size() == 0) {
                TreeNode * node = new TreeNode(i);
                node->left = nullptr;
                node->right = nullptr;
                result.push_back(node);
                //return result;
            }
            else if(leftArray.size() == 0 || rightArray.size() == 0) {
                if(leftArray.size() == 0) {
                    for(int j = 0; j < rightArray.size(); j++) {
                        TreeNode * node = new TreeNode(i);
                        node->right = rightArray[j];
                        node->left = nullptr;
                        result.push_back(node);
                    }
                } else {
                    for(int j = 0; j < leftArray.size(); j++) {
                        TreeNode * node = new TreeNode(i);
                        node->left = leftArray[j];
                        node->right = nullptr;
                        result.push_back(node);
                    }
                }
                //return result;
            } else {
                for(int l = 0; l < leftArray.size(); l++) {
                    for(int r = 0; r < rightArray.size(); r++) {
                        TreeNode * node = new TreeNode(i);
                        node->left = leftArray[l];
                        node->right = rightArray[r];
                        result.push_back(node);
                    }
                }
            }
         }
        return result;
    }
    
};