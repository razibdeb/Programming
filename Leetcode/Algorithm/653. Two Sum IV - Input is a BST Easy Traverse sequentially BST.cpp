/*
653. Two Sum IV - Input is a BST Easy



Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
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
113 ms
Beats
13.38%
Memory
36.9 MB
Beats
66.75%

memory -> O(height of the tree)
time (N) worst case not found

*/
    stack<TreeNode*> st1, st2;
    int getNextBigger() {
        int result;
        if(st1.empty()) {
            return INT_MIN;
        }
        result = st1.top()->val;

        TreeNode *curNode = st1.top();
        st1.pop();
        if(curNode->right != nullptr) {
            st1.push(curNode->right);
            while(true) {
                curNode = st1.top();
                if(curNode->left != nullptr) {
                    st1.push(curNode->left);
                    curNode = curNode->left;
                } else {
                    break;
                }
            }
        }
        return result;
    }

    int getNextSmaller() {
        if(st2.empty()) return INT_MAX;
        TreeNode *node = st2.top();
        int result = node->val;
        st2.pop();
        if(node->left != nullptr) {
            
            node = node->left;

            st2.push(node); //pushing the left

            node = node->right; //moving to right and will keep going
            while(node != nullptr) {
                st2.push(node);
                node = node->right;
            }
        }
        return result;
    }
    void initializeStack(TreeNode* root) {
        TreeNode *node = root;
        while(node != nullptr) {
            st1.push(node);
            node = node->left;
        }

        node = root;

        while(node != nullptr) {
            st2.push(node);
            node = node->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        initializeStack(root);

        // while(true) {
        //     int res = getNextSmaller();
        //     if(res == INT_MAX) break;
        //     cout<<res<<endl;
        // }

        int fromLeft =  getNextBigger();
        int fromRight = getNextSmaller();
        while(fromLeft < fromRight) {
            int sum = fromLeft + fromRight;
            if(sum > k) {
                fromRight = getNextSmaller();
            } else if(sum < k){
                fromLeft = getNextBigger();
            } else {
                return true;
            }
        }
        return false;
    }
};