/*
76. Minimum Window Substring Hard

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/
/*
Runtime: 29 ms, faster than 58.54% of C++ online submissions for Minimum Window Substring.
Memory Usage: 7.8 MB, less than 68.81% of C++ online submissions for Minimum Window Substring.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return "";
        
        unordered_map<char, int> have, need;
        unordered_set<char> uniqueChars;
        int requiredScore = 0, score = 0;
        int start = 0, end = 0;
        
        for(int i = 0; i < t.size(); i++) {
            need[t[i]]++;
            uniqueChars.insert(t[i]);
        }
        requiredScore = uniqueChars.size();
        int minLen = INT_MAX;
        
        int resultStart;
        //O(N) N = size of s
        while(end < s.size()) {
            char currentChar = s[end];
            //if this char does not exists in pattern then we just ignore
            if(uniqueChars.find(currentChar) == uniqueChars.end()) {
                end++;
                continue;
            }
            //increase the count of this char
            have[currentChar]++;
            
            //if we do compare with == that means it will only increase the score, ONLY when 
            //it will match the required
            //if we use >= then we have to store another variable for this char, when we will reduce this
            if(have[currentChar] == need[currentChar]) {
                score++;
            }
            //keep shrining untill required score == score
            while(start <= end && requiredScore == score) {
                
                
                int curLen = end - start + 1;
                if(curLen < minLen) {
                    minLen = curLen;
                    resultStart = start;
                    //result = s.substr(start, curLen); ////O(L) L = lenght of t //if we do it outside loop then complexity will reduce
                }

                char startChar = s[start];
                if(uniqueChars.find(startChar) == uniqueChars.end()) {
                    start++;
                    continue;
                }
                
                have[startChar]--;
                
                if(have[startChar] < need[startChar]) {
                    score--;
                }
                start++;
            }
            
            end++;
        }
        //O(L) l = size of t
        if(minLen == INT_MAX) return "";
        else {
            return s.substr(resultStart, minLen);
        }
    }
};