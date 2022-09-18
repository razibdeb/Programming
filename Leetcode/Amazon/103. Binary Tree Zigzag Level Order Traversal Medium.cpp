/*
103. Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12.4 MB, less than 9.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
    */
    
    //idea is to travarse BFS normally for this tree
    //then each level, push the nodes to a deque
    //this deque holds the normal order, left to right
    //based on flag we will take item from deque, either from front or back
    //and push it to vector which will be added to result later
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == nullptr) return result;
        
        queue<TreeNode*> q;
        
        q.push(root);
        bool flag = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> item;
            deque<int> qq;
            
            while(size-- > 0) {
                TreeNode * node = q.front();
                q.pop();
                qq.push_back(node->val);
                if(node->left != nullptr) {
                    q.push(node->left);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                }
                
            }
            
            if(flag == false) {
                while(!qq.empty()) {
                    item.push_back(qq.back());
                    qq.pop_back();
                }
            } else {
                 while(!qq.empty()) {
                    item.push_back(qq.front());
                    qq.pop_front();
                }
            }
            flag = !flag;
            result.push_back(item);
        }
        
        return result;
    }
};
/*
[1,2,3,4,null,null,5]
        1
    2         3
4     null  null 5
*/