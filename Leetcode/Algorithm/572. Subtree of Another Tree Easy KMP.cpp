/*

572. Subtree of Another Tree Easy


Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 

Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
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
Runtime
37 ms
Beats
73.36%
Memory
30.7 MB
Beats
5.28%

O (m + n)
m = size of root 
n = size of subRoot

interesting way to solve this problem, serialize the tree then perform KMP

*/
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string input, pattern;
        serialize(root, input);
        serialize(subRoot, pattern);
        /*
"ababcaababcaabc"
"ababcaabc"
        */
        vector<int> lps(pattern.size(), 0);

        int k = 0;
        int len = 1;
        while(len < pattern.size()) {
            while(pattern[len] != pattern[k] && k != 0) {
                k = lps[k-1];
            }
            if(pattern[len] == pattern[k]) {
                k++;
            }
            lps[len] = k;
            len++;
        }
        // for(int i = 0; i < lps.size(); i++) {
        //     cout<<lps[i]<<" ";
        // }
        cout<<endl;
        int index = 0;
        k = 0;
        while(index < input.size()) {
            while(k > 0 && input[index] != pattern[k]) {
                k = lps[k-1];
            }
            if(input[index] == pattern[k]) {
                k++;
            }
            if(k == pattern.size()) {
                return true;
            }
            index++;
        }
        return false;
    }

    void serialize(TreeNode*root, string &str) {
        if(root == nullptr) {
            str += "#null";
            return;
        }
        str += "&"+to_string(root->val);
        serialize(root->left, str);
        serialize(root->right, str);
    }
};