/*
1155. Number of Dice Rolls With Target Sum Medium

You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
 

Constraints:

1 <= n, k <= 30
1 <= target <= 1000
*/
class Solution {
public:
    int MOD = 1e9+7;
    int face;
    int numRollsToTarget(int n, int k, int target) {
        face = k;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(n, target, dp);
    }
    
    int solve(int n, int target, vector<vector<int>> &dp) {
        //have to check the target first, or
        // for 1 0 it will return 1, but that is not possible
        if(target <= 0) {
            return 0;
        }
        if(n == 1) {
            if(target > face) return 0;
            else return 1; //if just one dice then we can make faces amount in just 1 ways
        }

        
        if(dp[n][target] != -1) return dp[n][target];
        
        int result = 0;
        for(int i = 1; i <= face; i++) {
            
            result = result % MOD +  solve(n - 1, target - i, dp) % MOD;
            result = result % MOD;
        }
        
        dp[n][target] = result;
        return result;
    }
};