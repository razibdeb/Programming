/*
395. Longest Substring with At Least K Repeating Characters Medium

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105
*/
class Solution {
public:
/*
Runtime 8 ms Beats 57.56%
Memory 6.7 MB Beats70.26%
*/
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }
    //devide the calls if we get any character which doesn't meet the requirements
    // count is less then k
    int solve(string &s, int start, int end, int k) {
        cout<<start<<" "<<end<<endl;
        if(start > end) return 0;
        if(end - start + 1 < k) return 0;
        
        unordered_map<char, int> dict;
        
        for(int i = start; i <= end; i++) dict[s[i]]++;
        unordered_set<char> notPossible;
        for(auto item: dict) {
            if(item.second < k) notPossible.insert(item.first);
        }
        if(notPossible.size() == 0) return end - start + 1;
        int lastPosition = start;
        int maxResult = 0;
        for(int i = start; i <= end; i++) {
            if(notPossible.find(s[i]) != notPossible.end()) {
                int res = solve(s, lastPosition, i - 1, k);
                lastPosition = i + 1;
                maxResult = max(maxResult, res);
            }
        }
        //for the last case it wont call
        //like lastPosition is 3 and we are at 10, and between 3 & 10 result exists
        // we need to call this case
        if(lastPosition < end) {
            int res = solve(s, lastPosition, end, k);
            maxResult = max(maxResult, res);
        }

        return maxResult;
    }
};

/*
"bbaaacbd"
3

*/