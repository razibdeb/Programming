/*
763. Partition Labels Medium

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/
/*
Runtime
3 ms
Beats
92.69%
Memory
6.8 MB
Beats
48.85%
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> indexMap;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            indexMap[ch] = i;
        }

        int start = 0;
        int end = 0;
        int index = 0;

        vector<int> result;
        while(index < s.size()) {
            char ch = s[index];
            start = index;
            end = indexMap[ch];
            index++;
            while(index <= end) {
                char ch = s[index];
                end = max(end, indexMap[ch]);
                index++;
            }

            result.push_back(end - start + 1);
        }
        return result;
    }
};