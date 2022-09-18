
/*
97. Interleaving String Medium

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m non-empty substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 

Follow up: Could you solve it using only O(s2.length) additional memory space?
*/

class Solution {
public:
    
    /*
    Runtime: 6 ms, faster than 57.84% of C++ online submissions for Interleaving String.
Memory Usage: 7.2 MB, less than 44.36% of C++ online submissions for Interleaving String.
    */
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        
        
        //need to set the size to +1 because once we finish for one string, we will call its index + 1
        dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solve(s1, s2, s3, 0, 0 );
    }
    //O(nm) n = s1 length, m = s2 length
    bool solve(string &s1, string &s2, string &s3, int idx1, int idx2) {
        
        //once we reach to the end of both string s1, s2 that means we got s3
        // return true
        /*for input "" "" "a" -> it will give true but it is false*/
        if(idx1 == s1.size() && idx2 == s2.size()) return true;
        
        //idx1 & idx2 will never be greater then s1.size & s2.size() respectively 
        
        int idx3 = idx1 + idx2;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        bool r1 = false, r2 = false;
        if(idx1 < s1.size() && s1[idx1] == s3[idx3]) {
            r1 = solve(s1, s2, s3, idx1+1, idx2);
            if(r1 == true) {
                dp[idx1][idx2] = true;
                return true;
            }
        }
        if(idx2 < s2.size() && s2[idx2] == s3[idx3]) {
            r2 = solve(s1, s2, s3, idx1, idx2 + 1);
            if(r2 == true) {
                dp[idx1][idx2] = true;
                return true;
            }
        }
        dp[idx1][idx2] = false;
        return false;
    }
};