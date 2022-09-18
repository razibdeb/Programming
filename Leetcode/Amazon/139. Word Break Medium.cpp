/*
139. Word Break Medium

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/
class Solution {
public:
    /*
    Runtime: 6 ms, faster than 85.48% of C++ online submissions for Word Break.
Memory Usage: 8.4 MB, less than 75.07% of C++ online submissions for Word Break.
    */
    unordered_set<string> stringSet;
    vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(int i = 0; i < wordDict.size(); i++) {
            stringSet.insert(wordDict[i]);
        }
        dp = vector<int>(s.size(), -1);
        return solve(s, 0);
    }
    
    bool solve(string &s, int index) {
        if(index == s.size()) return true;
        if(dp[index]!=-1) return dp[index];
        string temp = "";
        for(int i = index; i < s.size(); i++) {
            temp.push_back(s[i]);
            if(stringSet.find(temp) != stringSet.end()) {
                //cout<<temp<<endl;
                if(solve(s, i+1) == true) {
                    dp[index] = true;
                    //cout<<i+1<<" "<<true<<endl;
                    return true;
                }
            }
        }
        dp[index] = false;
        return false;
    }
};