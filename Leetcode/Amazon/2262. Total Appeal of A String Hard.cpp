/*
2262. Total Appeal of A String Hard

The appeal of a string is the number of distinct characters found in the string.

For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.
Given a string s, return the total appeal of all of its substrings.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abbca"
Output: 28
Explanation: The following are the substrings of "abbca":
- Substrings of length 1: "a", "b", "b", "c", "a" have an appeal of 1, 1, 1, 1, and 1 respectively. The sum is 5.
- Substrings of length 2: "ab", "bb", "bc", "ca" have an appeal of 2, 1, 2, and 2 respectively. The sum is 7.
- Substrings of length 3: "abb", "bbc", "bca" have an appeal of 2, 2, and 3 respectively. The sum is 7.
- Substrings of length 4: "abbc", "bbca" have an appeal of 3 and 3 respectively. The sum is 6.
- Substrings of length 5: "abbca" has an appeal of 3. The sum is 3.
The total sum is 5 + 7 + 7 + 6 + 3 = 28.
Example 2:

Input: s = "code"
Output: 20
Explanation: The following are the substrings of "code":
- Substrings of length 1: "c", "o", "d", "e" have an appeal of 1, 1, 1, and 1 respectively. The sum is 4.
- Substrings of length 2: "co", "od", "de" have an appeal of 2, 2, and 2 respectively. The sum is 6.
- Substrings of length 3: "cod", "ode" have an appeal of 3 and 3 respectively. The sum is 6.
- Substrings of length 4: "code" has an appeal of 4. The sum is 4.
The total sum is 4 + 6 + 6 + 4 = 20.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/
class Solution {
public:
    /*
    Runtime: 39 ms, faster than 70.87% of C++ online submissions for Total Appeal of A String.
Memory Usage: 10.5 MB, less than 77.03% of C++ online submissions for Total Appeal of A String.
    */
    long long appealSum(string s) {
        /*
        
        abcdb
        at index 0
        a -> 1
        Total = 1
        
        at index 1
        b ->   0 + 1
        ab ->  1 + 1 => first one is the result for previous a, 2nd one as b in unique
        Total = 1 + 2 = 3
        
        at index 2
        c   -> 0 + 1
        bc  -> 1 + 1
        abc -> 2 + 1 = first 2 is for ab, then as c is unique
        total = 3 + 3 => first 3 is total of previous result + 3 -> total unique
        
        at index 3
        b   -> 0 + 1
        cb  -> 1 + 1
        bcb -> 2 + 0
        abcb-> 3 + 0
        total = 6 + 2 -> 2nd 2 is total unique in this 
        2 = 
            1 -> for just this item
            last index of b => 3
            previous index of b => 1
            items in between 3 - 1 -1 = 1
        
        at some index result = result at previous index + current's items index - current items's previous index
        */
        vector<int> lastIndex(26, -1);
        long long prevResult = 0;
        long long sumResult = 0;
        for(int i = 0; i < s.size(); i++) {
            int resultForThisIndex = prevResult + i - lastIndex[s[i] - 'a'];
            lastIndex[s[i] - 'a'] = i;
            prevResult = resultForThisIndex;
            //cout<<"index "<<i<<" "<<prevResult<<endl;
            sumResult += prevResult;
        }
        
        return sumResult;
        
    }
};