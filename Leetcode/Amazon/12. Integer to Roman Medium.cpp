/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999

Amazon |30

Microsoft|5

Google|4

Apple|4

Bloomberg|3

Capital One|3

LinkedIn|2

tiktok|2
*/

class Solution {
public:
    /*
    Runtime: 8 ms, faster than 73.16% of C++ online submissions for Integer to Roman.
Memory Usage: 9.4 MB, less than 18.68% of C++ online submissions for Integer to Roman.
    */
    string intToRoman(int num) {
        vector<pair<int, string>> dict(13);
        dict[0] = make_pair(1000, "M");
        dict[1] = make_pair(900, "CM");
        dict[2] = make_pair(500, "D");
        dict[3] = make_pair(400, "CD");
        dict[4] = make_pair(100, "C");
        dict[5] = make_pair(90, "XC");
        dict[6] = make_pair(50, "L");
        dict[7] = make_pair(40, "XL");
        dict[8] = make_pair(10, "X");
        dict[9] = make_pair(9, "IX");
        dict[10] = make_pair(5, "V");
        dict[11] = make_pair(4, "IV");
        dict[12] = make_pair(1, "I");
        string result = "";
        //while(num > 0) {
            for(int i = 0; i < 13 && num > 0; i++) {
                int div = num / dict[i].first;
                while( div > 0) {
                    result += dict[i].second;
                    div--;
                }
                num = num % dict[i].first;
            }
        //}
        
        return result;
    }
};