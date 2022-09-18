/*
2222. Number of Ways to Select Buildings Medium 

You are given a 0-indexed binary string s which represents the types of buildings along a street where:

s[i] = '0' denotes that the ith building is an office and
s[i] = '1' denotes that the ith building is a restaurant.
As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.
Return the number of valid ways to select 3 buildings.

 

Example 1:

Input: s = "001101"
Output: 6
Explanation: 
The following sets of indices selected are valid:
- [0,2,4] from "001101" forms "010"
- [0,3,4] from "001101" forms "010"
- [1,2,4] from "001101" forms "010"
- [1,3,4] from "001101" forms "010"
- [2,4,5] from "001101" forms "101"
- [3,4,5] from "001101" forms "101"
No other selection is valid. Thus, there are 6 total ways.
Example 2:

Input: s = "11100"
Output: 0
Explanation: It can be shown that there are no valid selections.
 

Constraints:

3 <= s.length <= 105
s[i] is either '0' or '1'.
*/
class Solution {
public:
    /*
    Runtime: 129 ms, faster than 84.09% of C++ online submissions for Number of Ways to Select Buildings.
Memory Usage: 24.3 MB, less than 90.39% of C++ online submissions for Number of Ways to Select Buildings.
    */
    long long numberOfWays(string s) {
        /*
        There can be only two types of selections: 101 or 010

        -> Iterate over the string and in each iteration,
            If current character is '0', it can be the middle of "101" slection
                add how many selections can be there with this '0' as the middle element
                (this is, numbers of ones on the left * number of ones on the right)
            If current character is '1', it can be the middle of "010" selection
                add how many selections can be there with this '1' as the middle element
                (this is, numbers of zeros on the left * number of zeros on the right)
        -> return ans
        */
        int count0 = 0, count1 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') count0++;
            else count1++;
        }
        
        long long left0 = 0, left1 = 0;
        long long answer = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                answer += left1 * (count1 - left1);
                left0++;
            } else {
                answer += left0 * (count0 - left0);
                left1++;
            }
        }
        return answer;
    }
    vector<vector<vector<int>>> dp;
    
    long long numberOfWaysDP(string s) {
        int n = s.size();
        dp = vector<vector<vector<int>>> (n, vector<vector<int>>(4, vector<int> (2, -1)));
        cout<<s.size()<<endl;
        long long result = 0; 
        result += solve(s, 0, 0, 0);
        result += solve(s, 0, 0, 1);
        return result;
    }
    //this DP will cause TLE
    //
    long long solve(string &s, int offset, int taken, int take) {
        if(taken == 3) return 1;
        if(offset == s.size()) return 0;
        
        if(dp[offset][taken][take] != -1) return dp[offset][taken][take];
        
        //cout<<offset<<" "<<taken<<" "<<take<<endl;
        
        long long result = 0; 
        if(take == 0) {
            for(int i = offset; i < s.size(); i++) {
                if(s[i] == '0') {
                    result += solve(s, i + 1, taken + 1, 1);
                }
            }
        } else {
            for(int i = offset; i < s.size(); i++) {
                if(s[i] == '1') {
                    result += solve(s, i + 1, taken + 1, 0);
                }
            }
        }
        dp[offset][taken][take] = result;
        return result;
    }
};