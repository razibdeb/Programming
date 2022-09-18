/*
1597. Build Binary Expression Tree From Infix Expression Hard

A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with 2 children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

For each internal node with operator o, the infix expression it represents is (A o B), where A is the expression the left subtree represents and B is the expression the right subtree represents.

You are given a string s, an infix expression containing operands, the operators described above, and parentheses '(' and ')'.

Return any valid binary expression tree, whose in-order traversal reproduces s after omitting the parenthesis from it.

Please note that order of operations applies in s. That is, expressions in parentheses are evaluated first, and multiplication and division happen before addition and subtraction.

Operands must also appear in the same order in both s and the in-order traversal of the tree.

 

Example 1:


Input: s = "3*4-2*5"
Output: [-,*,*,3,4,2,5]
Explanation: The tree above is the only valid tree whose inorder traversal produces s.
Example 2:


Input: s = "2-3/(5*2)+1"
Output: [+,-,1,2,/,null,null,null,null,3,*,null,null,5,2]
Explanation: The inorder traversal of the tree above is 2-3/5*2+1 which is the same as s without the parenthesis. The tree also produces the correct result and its operands are in the same order as they appear in s.
The tree below is also a valid binary expression tree with the same inorder traversal as s, but it not a valid answer because it does not evaluate to the same value.

The third tree below is also not valid. Although it produces the same result and is equivalent to the above trees, its inorder traversal does not produce s and its operands are not in the same order as s.

Example 3:

Input: s = "1+2+3+4+5"
Output: [+,+,5,+,4,null,null,+,3,null,null,1,2]
Explanation: The tree [+,+,5,+,+,null,null,1,2,3,4] is also one of many other valid trees.
 

Constraints:

1 <= s.length <= 100
s consists of digits and the characters '+', '-', '*', and '/'.
Operands in s are exactly 1 digit.
It is guaranteed that s is a valid expression.
*/
/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Build Binary Expression Tree From Infix Expression.
Memory Usage: 7 MB, less than 61.80% of C++ online submissions for Build Binary Expression Tree From Infix Expression.
    */
    Node* expTree(string s) {
        /*
        approach: 
        fron infix convert to post fix
        from post fix create a tree
        */    
        
        string postfix = infixToPostFix(s);
        
        return postFixToTree(postfix);

    }
    
    Node *postFixToTree(string &postfix) {
        stack<Node*> st;
        
        for(char ch: postfix) {
            if(isdigit(ch)) {
                Node * node = new Node(ch);
                st.push(node);
            } else { //operator
                //"3*4-2*5"
                //post fix 34*25*-
                // at first 3 & 4 will be added then, *
                Node * right = st.top(); st.pop();
                Node * left = st.top(); st.pop();
                
                Node *node = new Node(ch);
                node->left = left;
                node->right = right;
                st.push(node);
                
            }
        }
        return st.top();
    }
    
    int getPriority(char c) {
        if(c == '+' || c == '-') return 1;
        else if(c == '*' || c == '/') return 2;
        
        return 0;
    }
    
    string infixToPostFix(string &s) {
        /*
        maintain a stack
        if digit add to postfix 
        if ( push
        if operator -> if stack top operator is lower priority then push
        if stack top is higher or same priority, then pop and add to post fix -> keep going
        if ) -> pop from stack until we get ( and add to postfix
        */
        
        stack<char> st;
        string postfix;
        
        for(char ch : s) {
            if(isdigit(ch)) {
                postfix.push_back(ch);
            } else if(ch == '(' ) {
                st.push('('); //just push, we will check when we get )
            } else if(ch == ')') {
                 while(st.top() != '(') {
                        char ch = st.top();
                        st.pop();
                        
                        postfix.push_back(ch);
                 }
                 st.pop();//finally pop the (
            } else { //operator
                while(!st.empty() && getPriority(st.top()) >= getPriority(ch)) {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()) {
            postfix.push_back(st.top());
            st.pop();
        }
        
        return postfix;
    }
};