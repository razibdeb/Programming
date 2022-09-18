/*
424. Longest Repeating Character Replacement Medium

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/
class Solution {
public:
    /*
    Runtime: 50 ms, faster than 13.62% of C++ online submissions for Longest Repeating Character Replacement.
Memory Usage: 7.1 MB, less than 12.56% of C++ online submissions for Longest Repeating Character Replacement.
    */
    int characterReplacement(string s, int k) {
        /*
        brute force
        find all subsequence
        for all subsequence
        find the maximum frequence of a character
        other character count = total length - maximum frequencey
        if other character count <= k then length of this subsequnce could be an answer
        update answer
        
        complexity O(N^2)
        
        sliding window
        start & end point to start
        maintain a map to store the count of a character in this subsequence
        get the maximum char count => go through the map, 26 max
        if (end - start + 1) - maximum frequency <= k then this could be anser
        update it
        increate end
        if it was bigger then k then we have to increase the start
        doing that, we have to reduce the count in map as well
        complexity O(26N)
        */
        
        int start = 0;
        int end = 0;
        unordered_map<char, int> charCount;
        int answer = 0;
        charCount[s[end]]++; //we have to update this variable only when end or start is updated
        while(end < s.size()) {
            //cout<<start<<" "<<end<<"  "<<s[end]<<endl;
            int maxCount = getMaximumCount(charCount);
            if( ((end - start + 1) - maxCount ) <= k) {
                //cout<<"\t maxC"<<maxCount<<endl;
                answer = max(answer, (end - start + 1));
                end++;
                charCount[s[end]]++;
            } else {
                charCount[s[start]]--;
                start++;
            }
            //cout<<"\t"<<answer<<endl;
        }

        return answer;
    }
    //O(26)
    int getMaximumCount(unordered_map<char, int> &charCount) {
        int maxCount = 0;
        for(auto it: charCount) {
            if(it.second > maxCount) maxCount = it.second;
            //cout<<"\t"<<it.first<<" : "<<it.second<<endl;
        }
        return maxCount;
    }
};