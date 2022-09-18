/*
297. Serialize and Deserialize Binary Tree Hard

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
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
class Codec {
public:

    /*
    Runtime: 84 ms, faster than 48.14% of C++ online submissions for Serialize and Deserialize Binary Tree.
Memory Usage: 35 MB, less than 37.86% of C++ online submissions for Serialize and Deserialize Binary Tree.
    */
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        
        DFS(root, result);
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> list = splitString(data);
        int index = 1; //first item is empty as we split by #
        return DFSGenerate(list, index);
    }
    
    vector<string> splitString(string &input) {
        vector<string> result;
        string tempChar = "";
        for(char ch: input) {
            if(ch == '#') {
                result.push_back(tempChar);
                tempChar = "";
            } else {
                tempChar.push_back(ch);
            }
        }
        if(tempChar.size() > 0)
            result.push_back(tempChar);
        return result;
    }
    //PREORDER ROOT, LEFT RIGHT
     void DFS(TreeNode* root, string &result) {
        if(root == nullptr) {
            result += "#null";
            return;
        }
        result += "#"+to_string(root->val);
        DFS(root->left, result);
        DFS(root->right, result);
    }

    //ACCESS PREORDER ROOT, LEFT, RIGHT
    TreeNode* DFSGenerate(vector<string> &data, int &index) {
        if(data[index] == "null" || index >= data.size()) {
            index++;
            return nullptr;
        } else {
            TreeNode * node = new TreeNode();
            //cout<<index<<" making a node for "<<data[index]<<endl;
            node->val = stoi(data[index]);
            index++;
            
            node->left = DFSGenerate(data, index);
            node->right = DFSGenerate(data, index);
            return node;
        }
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));