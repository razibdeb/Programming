/*
3. Longest Substring Without Repeating Characters Medium

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
class Solution {
public:
    /*
    Runtime: 20 ms, faster than 64.74% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.1 MB, less than 81.99% of C++ online submissions for Longest Substring Without Repeating Characters.
    */
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> charCount;
        
        int start = 0; 
        int end = 0;
        int n = s.size();
        //vector<bool> seen(n, false); can't use it as it can have all type of characters
        
        //seen[s[end] - 'a'] = true;
        int result = 0;
        
        while(end < s.size()) {
            //
            if(charCount.find(s[end]) != charCount.end() && charCount[s[end]] == true) { //can't take
                while(start < end && s[start] != s[end]) {
                    charCount[s[start]] = false;
                    start++;
                }
                //previous loop breaks when it was same, need to point to next
                start++;
            }
            charCount[s[end]] = true;
            int len = end - start + 1;
            if(len > result) result = len;
            end++;
        }
        
        return result;
    }
    
    /*
    editorial: easy to implement
    Time complexity : O(2n) = O(n)O(2n)=O(n). In the worst case each character will be visited twice by ii and jj.
     int lengthOfLongestSubstring(string s) {
        unordered_set<char, int> chars;

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
    //////////////////////
    Time complexity : O(n)O(n). Index jj will iterate nn times.

Space complexity : O(min(m, n))O(min(m,n)). Same as the previous approach.

    class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = int(s.length()), res = 0;
        unordered_map<char, int> mp;

        for (int j = 0, i = 0; j < n; j++){
            if(mp[s[j]] > 0) {
                i = max(mp[s[j]], i);
            }
            res = max(res, j - i + 1);
            mp[s[j]] = j + 1;
        }
        return res;
    }
};
    */
};