/*
22. Generate Parentheses Medium


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    /*
    Runtime: 3 ms, faster than 86.89% of C++ online submissions for Generate Parentheses.
Memory Usage: 15.2 MB, less than 27.51% of C++ online submissions for Generate Parentheses.
    */
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        solve("", n , 0, 0);
        return result;
    }
    void solve(string input, int n, int leftCount, int rightCount) {
        if(leftCount > n || rightCount > n) return;
        if(leftCount == rightCount && leftCount == n) {
            result.push_back(input);
            return;
        }
        
        if(leftCount > rightCount) {
            solve(input + ")", n, leftCount, rightCount+1);
        }
        
        solve(input + "(", n, leftCount + 1, rightCount);
    }
    
    /*Another solution*/
    
    bool isValid(string str) {
        int i = 0, len = str.length();
        stack<char> st;
        
        while(i < len) {
            if(str[i] == '(') st.push(str[i]);
            else{
                if(st.size() == 0 || st.top() != '(') return false;
                st.pop();
            }
            i++;
        }
        if(st.size() > 0) return false;
        
        return true;
    }
    
    void gen(int i, int n, string str, vector<string>& res) {
        if(i >= n*2) {
            if(isValid(str)) res.push_back(str);
            return;
        }
        
        gen(i+1, n, str+'(' , res);
        gen(i+1, n, str+')', res);
    }
    
//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         gen(0, n, "", res);
        
//         return res;
//     }
};