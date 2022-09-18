/*
696. Count Binary Substrings Easy

Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 

Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
*/
class Solution {
public:
    /*
    Runtime: 23 ms, faster than 85.97% of C++ online submissions for Count Binary Substrings.
Memory Usage: 10.5 MB, less than 46.73% of C++ online submissions for Count Binary Substrings.
    */
    int countBinarySubstrings(string s) {
        char prevChar = 'a', curChar;
        int prevCount = 0, curCount = 0;
        int result = 0;
        
        //0011
        
        curChar = s[0];
        curCount = 1;
        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == curChar) {
                curCount++;
            } else {
                result += min(prevCount, curCount);
                prevChar = curChar;
                prevCount = curCount;
                
                curCount = 1;
                curChar = s[i];
            }
        }
        //forgot to check for the last item
        result = result + min(prevCount, curCount);
        return result;
    }
};