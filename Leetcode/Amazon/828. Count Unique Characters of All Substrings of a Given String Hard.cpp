/*
828. Count Unique Characters of All Substrings of a Given String Hard


Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

 

Example 1:

Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
Example 2:

Input: s = "ABA"
Output: 8
Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
Example 3:

Input: s = "LEETCODE"
Output: 92
 

Constraints:

1 <= s.length <= 105
s consists of uppercase English letters only.
*/
class Solution {
public:
    /*
    Runtime: 142 ms, faster than 25.35% of C++ online submissions for Count Unique Characters of All Substrings of a Given String.
Memory Usage: 39.9 MB, less than 5.13% of C++ online submissions for Count Unique Characters of All Substrings of a Given String.
    */
    int uniqueLetterString(string s) {
        /*
        idea is to apply similar concept of min subarray sum
        subarray-> contiguous
        
        ABCDEF
        with C
        we can get 
        AB on left side 
        DEF on right side
        so total 3*4 = 12 sub array where C exists
        C
        ABC
        BC
        CD
        CDE
        CDEF
        
        ABCD
        ABCDE
        ABCDEF
        
        BCD
        BCDE
        BCDEF
        
        or we can think of where we can put left bracket and right bracket
        [A[B[C]D]E]F] 
        left side 3 place right side 4 place -> total 3*4 = 12 place
        
        if ABCDCEF
        then
        for first C
        [A[B[C]D]CEF left 3 right 2, we can't take 2nd C, if we take that then it won't be a 
        subarray where 3rd C is unique
        
        similar way we can calculate for each charecter
        
        we need to know the index of each character for this
        then for each index, put left bracket & right bracket so that, it doesn't include another same character
        
        we can assume there is an character exists at beginign and end
        so we will insert -1 & n as index
        
        */
        
        unordered_map<char, vector<int>> dict;
        
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(dict.find(ch) == dict.end()) {
                dict[ch].push_back(-1);
            }
            dict[ch].push_back(i);
        }
        int n = s.size();
        
        for(auto it: dict) {
            dict[it.first].push_back(n);
        }
        
        int sum = 0;
        
        for(auto it: dict) {
            vector<int> index = it.second;
            
            for(int i = 1; i < index.size() - 1; i++) {
                int leftBoundary = index[i - 1];
                int rightBoundary = index[i + 1];
                int curIndex = index[i]; //////////// -> we need the current index, i is the index of vector, not index of character
                
                int leftCount = curIndex - leftBoundary;
                int rightCount = rightBoundary - curIndex;
                //cout<<"For "<<it.first<<" "<<leftCount<<" "<<rightCount<<endl;
                
                sum += leftCount * rightCount;
            }
        }
        
        return sum;
    }
};