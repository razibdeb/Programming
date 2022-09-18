/*
You are given a string s consisting only of lowercase English letters.

In one move, you can select any two adjacent characters of s and swap them.

Return the minimum number of moves needed to make s a palindrome.

Note that the input will be generated such that s can always be converted to a palindrome.

 

Example 1:

Input: s = "aabb"
Output: 2
Explanation:
We can obtain two palindromes from s, "abba" and "baab". 
- We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
- We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
Thus, the minimum number of moves needed to make s a palindrome is 2.
Example 2:

Input: s = "letelt"
Output: 2
Explanation:
One of the palindromes we can obtain from s in 2 moves is "lettel".
One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
Other palindromes such as "tleelt" can also be obtained in 2 moves.
It can be shown that it is not possible to obtain a palindrome in less than 2 moves.
 

Constraints:

1 <= s.length <= 2000
s consists only of lowercase English letters.
s can be converted to a palindrome using a finite number of moves.
*/

class Solution {
public:
    /*
    Runtime: 20 ms, faster than 78.23% of C++ online submissions for Minimum Number of Moves to Make Palindrome.
Memory Usage: 6.8 MB, less than 41.99% of C++ online submissions for Minimum Number of Moves to Make Palindrome.
    */
    int minMovesToMakePalindrome(string s) {
        /*
        approach:
        start from left -> get char
        look for the character from end-> found
            swap it with end 
            distance += end - index where it is found
        if not found that means it will go to middle 
            we will skip it now, and in the end we will add it's count
            otherwise this will cause problem
            https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/discuss/1847011/c-2-pointers-with-detail-proof-and-explanation
            abcc d dzba
            mid char is z
            if we move it to middle
            abcc z ddba
            we are moving d from left to right, which is not needed
            , you should avoid trying to swap the 'z' to the center before the whole process ends. That is because at this time you can't guarantee all the swap you do is necessary. See the example below. The green 'd' is swapped to the right side of 'z' which is an unnecessary cost, because it should be on the left size at the end. However, when you do this after the whole process ends, you won't have this problem.
            
        
        as it is said we can select any two adjacent chars to swap, so total moves will be 
        distance
        */
        
        int start = 0;
        int end = s.size() - 1;
        
        //"skwhhaaunskegmdtutlgtteunmuuludii"
        //"scpcyxprxxsjyjrww"
        //cout<<s<<endl;
        int midCharIndex = -1;
        int move = 0;
        while(start < s.size() / 2) {
            if(s[start] != s[end]) {
                //check if same char found or not
                int r = end;
                int newIndex = -1;
                while(r >= start && s[start] != s[r]) {
                    r--;
                }
                if(r == start) { // not found
                    midCharIndex = r;
                    start++;
                    continue;
                }
                else {
                    for(int i = r; i < end; i++) {
                        s[i] = s[i + 1];
                        move++;
                    }
                    s[end] = s[start];
                   // move++;
                    start++;
                    end--;
                }
            }  else {
                start++;
                end--;
            }
            //ut<<s<<endl;
        }
        if(midCharIndex != -1) {
            move += s.size() / 2 - midCharIndex;
        }
        return move;
    }
};