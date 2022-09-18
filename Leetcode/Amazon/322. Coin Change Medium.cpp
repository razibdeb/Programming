/*

322. Coin Change Medium

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/
class Solution {
public:
    /*
    Runtime: 197 ms, faster than 27.19% of C++ online submissions for Coin Change.
Memory Usage: 14.5 MB, less than 54.56% of C++ online submissions for Coin Change.
    */
    //O(s*n)
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1, INT_MAX); //minimum number of coins required to make index
        
        dp[0] = 0; // for zero
        
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(coins[j] <= i && dp[i - coins[j]] != INT_MAX) { //[2,5] 11
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        
        if(dp[amount] != INT_MAX) return dp[amount];
        else return -1;
    }
};