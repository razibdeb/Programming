/*
926. Flip String to Monotone Increasing Medium

A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

 

Example 1:

Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
Example 2:

Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
Example 3:

Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
*/
class Solution {
public:
    /*
    Runtime: 52 ms, faster than 33.25% of C++ online submissions for Flip String to Monotone Increasing.
Memory Usage: 11 MB, less than 78.77% of C++ online submissions for Flip String to Monotone Increasing.

O(n)
    */
    int minFlipsMonoIncr(string s) {
        //NOT WORK
        //"10011111110010111011"
        //start from left
        //if it is one, then start calculation
        //if one incrase one counter
        //if zero, increase zero counter
        //finally minimum one is the result
        
        //new approach:
        // if it is one, we increase oneCount
        //now if it is zero, that means, we need to flip,
        //for flip-> if one count is zero that means no need to flip
        //if previously there were one, now we have to keep flipping zero untill 
        // we reach end, or zero count become bigger then one Count
        // we can think of this one flip we are cancelling one One
        //so reduce oneCount
        //if oneCount is zero, that means we are in equal state
        
        int oneCount = 0;
        int flip = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') oneCount++;
            else if(oneCount > 0) {
                flip++;
                oneCount--;
            }
        }
        
        return flip;
    }
};
/*
010110"

1 1 1 2 1
0 1 0 1 0
*/