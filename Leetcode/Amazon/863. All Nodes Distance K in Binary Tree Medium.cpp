/*
863. All Nodes Distance K in Binary Tree
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Runtime: 15 ms, faster than 25.11% of C++ online submissions for All Nodes Distance K in Binary Tree.
Memory Usage: 13 MB, less than 59.86% of C++ online submissions for All Nodes Distance K in Binary Tree.
*/
class Solution {
public:
    unordered_map<int, TreeNode *> parentDict; //pointer as key does not work
    
    vector<int> result;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == nullptr || target == nullptr) return result;
        
        visit(root, nullptr);
        unordered_set<int> seen;
        
        queue<TreeNode *> q;
        q.push(target);
        
        //cout<<parentDict[target]->val<<endl;
        
        int depth = 0;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            if(depth == k) break;
            depth++;
            
            while(size-- > 0) {
                TreeNode * node = q.front();
                q.pop();
                seen.insert(node->val);
                //cout<<" visiting "<<node->val<<endl;
                if(node->left != nullptr && seen.find(node->left->val) == seen.end()) q.push(node->left);
                if(node->right != nullptr && seen.find(node->right->val) == seen.end()) q.push(node->right);
                if(parentDict[node->val] != nullptr && seen.find(parentDict[node->val]->val) == seen.end()) {
                    q.push(parentDict[node->val]);
                    //cout<<"\t adding parent "<<parentDict[node]->val<<endl;
                }
            }
        }
        
        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
    
    void visit(TreeNode * node, TreeNode * parent) {
        if(node == nullptr) return;
        parentDict[node->val] = parent;
        visit(node->left, node);
        visit(node->right, node);
    }
};