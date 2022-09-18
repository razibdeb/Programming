/*

2272. Substring With Largest Variance Hard


The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aababbb"
Output: 3
Explanation:
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.
Example 2:

Input: s = "abcde"
Output: 0
Explanation:
No letter occurs more than once in s, so the variance of every substring is 0.
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
*/
class Solution {
public:
    /*
    Runtime: 232 ms, faster than 50.30% of C++ online submissions for Substring With Largest Variance.
Memory Usage: 7.1 MB, less than 39.93% of C++ online submissions for Substring With Largest Variance.
    */
    int largestVariance(string s) {
        /*
        approach:
        https://leetcode.com/problems/substring-with-largest-variance/discuss/2297768/Java-or-Kadane's-Algorithm-or-Easy-to-understand
        first thing that need to hit is that we have to check for any TWO chars
        aabbbccccc
        a = 2
        b = 3
        c = 5
        result will be c - a = 5 - 2 = 3
        whole string 
        c in middle, we wont consider
        
        
        as we have to check for TWO, we can check for all pairs
        and from start to end, 
        for each pair, 
            we get count for both char, 
            get difference
            if difference is bigger then update result
            
            we will check this thing, for first one is big & second is smaller,
            because in whole iteration, later, same pair will come
            (a, b) later (b, a)
        
        complexity will be 26 x 26 x length of string max
        we can loop instead of 26 to unique characters we can find
        */
        /*
        aababb
        
        at index 0: 
        a
        a = 1
        b = 0
        result = 0
        
        at index 1:
        aa
        a = 2
        b = 0
        result = 0
        
        at index 2:
        aab
        a = 2
        b = 1
        result = 2 - 1 = 1
        
        at index 3:
        aaba
        a = 3
        b = 1
        Result = 2
        
        at index 4:
        aabab
        a = 3
        b = 2
        localResult = 1
        result = 2
        
        
        */
        
        unordered_map<char, int> charCount;
        for(char ch: s)
            charCount[ch]++;
        
        int result = 0;
        int lastResult = 0;
        //a is bigger then b
        for(int a = 0; a < 26; a++) {
            for(int b = 0; b < 26; b++) {
                //if one of a or b does not exists then we skip, as for being pair both need to exists
                if(a == b || charCount[a + 'a'] == 0 || charCount[b + 'a'] == 0) continue;
                int countA = 0, countB = 0;

                int countBRemain = charCount[b + 'a'];
                /*
                
                a : 0  b : 1 -> this is resetting value, we need to skip resetting if it is the last one
                a : 1  b : 0
                a : 2  b : 0
                
                b : 1  a : 0
                b : 1  a : 1
                b : 1  a : 2
                */
                for(char c: s) {
                    if(c - 'a' == a) { countA++;}
                    if(c - 'a' == b) { countB++; countBRemain--;} //we are reducing the bleft
                    //because we won't reset the counts if there is no more b left, 
                    //if we reset b and after that there is no b exists 
                    //then b will always be zero
                    //bba 
                    //frst  a 0 b 1 -> reest countA < countB
                    //      a 0 b 1 -> reset    countA < countB 
                    //      a 1 b 1 -> not result
                    //      next
                    //      b 1 a 0
                    //      b 2 a 0
                    //      b 2 a 1
                    
                    /*
                    abb
                    a : 1  b : 0
                    a : 1  b : 1
                    a : 1  b : 2 => reset
                    b : 0  a : 1
                    b : 1  a : 0
                    b : 2  a : 0
                    
                    */
                   // aabaabaab
                    
                    //cout<<char(a +'a')<<" : "<<countA<<"  "<<char(b + 'a')<<" : "<<countB<<endl;
                    if(countA < countB && countBRemain > 0) {
                        countA = 0;
                        countB = 0;
                    } else if(countA > 0 && countB > 0){
                        result = max(result, countA - countB);
                    }
                    
                }
            }
        }
        
        return result;
    }
};