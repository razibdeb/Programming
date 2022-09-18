/*
17. Letter Combinations of a Phone Number Medium

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    
    /*
    
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.7 MB, less than 18.35% of C++ online submissions for Letter Combinations of a Phone Number.
    */
    
    unordered_map<char, vector<char>> digitMap;
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;
        
        digitMap['2'] = {'a', 'b', 'c'};
        digitMap['3'] = {'d', 'e', 'f'};
        digitMap['4'] = {'g', 'h', 'i'};
        digitMap['5'] = {'j', 'k', 'l'};
        digitMap['6'] = {'m', 'n', 'o'};
        digitMap['7'] = {'p', 'q', 'r', 's'};
        digitMap['8'] = {'t', 'u', 'v'};
        digitMap['9'] = {'w', 'x', 'y', 'z'};
        
        solve(digits, 0, "");
        
        return result;
    }
    //4^L L is length of digit
    void solve(string &digits, int index, string output) {
        if(index == digits.size()) {
            result.push_back(output);
            return;
        }
        
        for(char ch: digitMap[digits[index]]) {
            solve(digits, index + 1, output + ch);
        }
    }
};