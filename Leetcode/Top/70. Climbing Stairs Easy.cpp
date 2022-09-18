/*
70. Climbing Stairs Easy

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/
class Solution {
public:
    /*
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
Memory Usage: 6.2 MB, less than 15.85% of C++ online submissions for Climbing Stairs.
    */
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++ ) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    // recursive: 4 ms 6 MB
    /*
    vector<int> dp;
    int climbStairs(int n) {
        dp = vector<int>(n + 1, -1);
        return solve(n);
    }
    int solve(int n) {
        if(n == 1) {
            return 1;
        } else if(n == 0) {
            return 1;
        }
        if(dp[n] != -1) return dp[n];
        dp[n] = solve(n-1) + solve(n - 2);
        return dp[n];
    }
    */
};