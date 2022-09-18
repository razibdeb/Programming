/*
91. Decode Ways Medium


A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/
class Solution {
public:
    int numDecodings(string s) {
        /*
        approach:
        if just one char -> one way
        if two char -> two way 11-> AA or K
        if we know the result for index i
        now if we add index + 1, there could be two scenario
            new is added to previous like ZX12 -> L -> in this case result is result of index-1 (X)
        or seperately ZX12-> AB result = result of index (1)
        **we have to check the numeric value -> if it is bigger then 26 then 1st way not possible and if it is less then 10 then also not possible (06 - > 6) adding zero in front won't work 
        */
        
        int n = s.size();
        
        /*
        
        zero will always be after 1 & 2 (10, 20)
        it won;t be before something like 01 02 04
        so if it is 101 then it means 10 & 11
        if 607 -> not valid because 60 > 26
        203 -> 20 & 3
        */
        /*
        "10101923"
        "1010192" = 2 ways 10 10 19 2 & 10 10 1 9 2
        "10101923" = 4 ways ???
        */
        

        if(s[0] == '0') return 0; //s contains only digits and may contain leading zero(s).
        
        if(n == 1) { //we have to put it after zero cheking, otherwise if input is "0" it will return 1
            return 1;
        }
        
        //now it's length is 2
        
        vector<int> dp(n, 0);
        dp[0] = 1; //it's not zero, bcoz first index is not 0
        
        //for dp we need i-1 & i -2, so we need to calculate for 1 index too
        
        int d = (s[0] - '0') * 10 + (s[1] - '0');
        
        if((s[1] - '0') == 0 ) { // means it is zero
            if(d > 26) return 0; //301
            dp[1] = 1; //29 -> BI
        } else if(d <= 26) {
            dp[1] = 2; //11 -> AA or K
        } else {
            dp[1] = 1; //99 or 27
        }
        /*
        "10011" => 0
        */
        for(int i = 2; i < n; i++) {
            char curChar = s[i];
            char lastChar = s[i - 1];
            //if current char is zero, we won't be able to create new, it has to add with previous char, so result will be previous previous char result "1010" index - 2
            
            
            int digit = (lastChar - '0') * 10 + curChar - '0';
            
            
            //"2101"
            /*
            2101
            2 => 1
            21=> 2, 21 => 2
            210=> 2, 10 => 2 -> we have to attach 0 with preivous char so result = index - 2
            
            "230" => 0
            
            
            */
            if(curChar == '0') { 
                if(lastChar == '0') return 0; //"10011" -> not possible
                else if(digit > 26) return 0; //"230"
                dp[i] = dp[i-2];
                continue;
            }
            
            
            
            if(digit <= 26 && digit >= 10) {
                dp[i] = dp[i-2] + dp[i-1]; //112 -> 1 12 & 1 1 2 & 11 2  -> last char was not zero
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};