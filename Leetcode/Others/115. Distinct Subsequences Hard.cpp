/*
115. Distinct Subsequences Hard


Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/
class Solution {
public:
    /*
    approach:
    we will try to match current char of t with s
    if it matches 
        then we can consider this char of S could be a way to reach end 
    where all chars of T will match
        we might find another way to reach end for this char of T, which will match with
        another char of S in future
    if not match
        then we wil chech with next char of S with current char of T
    
    */
    /*
    Runtime: 48 ms, faster than 69.65% of C++ online submissions for Distinct Subsequences.
Memory Usage: 18.5 MB, less than 48.74% of C++ online submissions for Distinct Subsequences.
    */
    
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int> (t.size() + 1, -2));
        
        return solve(s, t, 0, 0, dp);
    }
    /*
    "abbdcacbabacbabbacaddabbbaaadaadcbcababbbcdccaac"
    "dabca"
    
    "dbadabaababbbbdcbbdbdbdbacbcbddabddbadbcac"
    "dbddd"
    */
    int solve(string &s, string &t, int idx1, int idx2, vector<vector<int>> &dp) {
        //if we reach the end of t, that means we found one way to reach here, return 1
        if(idx2 == t.size()) {
            return 1;
        }
        // we reached the end of parent string, can't find any more
        if(idx1 == s.size()) return 0;
        
        if(dp[idx1][idx2] != -2) return dp[idx1][idx2];
        
        if(s[idx1] == t[idx2]) {
            dp[idx1][idx2] = solve(s, t, idx1 + 1, idx2 + 1, dp) + solve(s, t, idx1 + 1, idx2, dp);
        } else {
            dp[idx1][idx2] = solve(s, t, idx1 + 1, idx2, dp);
        }
        
        return dp[idx1][idx2];
    }
};