/*
2193. Minimum Number of Moves to Make Palindrome Hard

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
    Runtime: 23 ms, faster than 78.56% of C++ online submissions for Minimum Number of Moves to Make Palindrome.
Memory Usage: 6.8 MB, less than 79.21% of C++ online submissions for Minimum Number of Moves to Make Palindrome.
    */
    int minMovesToMakePalindrome(string s) {
        int start = 0; 
        int end = s.size() - 1;
        
        int minSwaps = 0;
        
        while(start < end) {
            if(s[start] == s[end]) {
                start++;
                end--;
                continue;
            }
            
            int index = end - 1;
            while(s[index] != s[start]) index--;
            
            if(index == start) { //that means no other char found, this is for middle index
                swap(s[start], s[start+1]);
                minSwaps++;
            } else {
                for(int i = index; i + 1 <= end; i++){
                    swap(s[i], s[i+1]);
                    minSwaps++;
                }
                start++;
                end--;
            }
        }
        //"scpcyxprxxsjyjrww"
        return minSwaps;
    }
    //doesn't work
    int minMovesToMakePalindromeOld(string s) {
        
        if(s.length() % 2 != 0) {
            unordered_map<char, int> countMap;
            for(int i = 0; i < s.size(); i++) {
                countMap[s[i]]++;
            }
            
            char singleChar;
            for(auto item: countMap) {
                if(item.second % 2 == 1) {
                    singleChar = item.first;
                    //break;
                }
                cout<<item.first<<" "<<item.second<<endl;
            }
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == singleChar) {
                    if(i < s.size() / 2) {
                        //reverse(s.begin(), s.end());
                    } 
                    break;
                }
            }
        }
        int start = 0; 
        int end = s.size() - 1;
        int swapCount = 0;
        
        cout<<s<<endl;
        cout<<"---"<<endl;
        while(start < end) {
            if(s[start] == s[end]) {
                start++;
                end--;
                continue;
            }
            //find nearest char from last
            int index = end - 1;
            while(index > start && s[start] != s[index]) index--;
            
            swapCount += end - index;
            
            for(int i = index; i + 1 <= end; i++) 
                swap(s[i], s[i+1]);
            start++;
            end--;
            cout<<swapCount<<" "<<s<<endl;
        }
        
        return swapCount;
    }
};