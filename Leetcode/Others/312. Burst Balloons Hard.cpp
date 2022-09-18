/*
312. Burst Balloons Hard

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/
/*
Runtime: 868 ms, faster than 28.66% of C++ online submissions for Burst Balloons.
Memory Usage: 10.4 MB, less than 18.39% of C++ online submissions for Burst Balloons.
*/
class Solution {
public:
    vector<vector<int>> dp;
    vector<int> coins;
    int maxCoins(vector<int>& nums) {
        //let'ssay we brust an ballon i
        // so we can calculate like nums[i-1]* nums[i] * nums[i+1]
        //then our array is devided into 0toi-1 & i+1 to n
        //we will need to travarse from i-1 to i+1 to find unbrusted baloon for right coin
        //will increase another n times complexity, and hard to implement
        /*
        bruteforse
        
        for each baloon at each step, we have two option either to brust it, or not
        each time we will devide the input array two 
        complexity will be 2^N
        
        
        what we can do is, instead of brusting at begining, we will choose to brust 
        a balloon at last, we will devide the input by 0toi-1 & i+1 to n
        calculate that, and then brust ith baloon
        this case we will pass the corner balloon coin at begining
        corner will be -1 & n + 1 this case
        
        */
        
        // we will add 1 to start & end at first so it will make our coding easy
        
        coins.push_back(1);
        for(int i = 0; i < nums.size(); i++)
            coins.push_back(nums[i]);
        coins.push_back(1);
        
        dp = vector<vector<int>> (coins.size(), vector<int>(coins.size(), -1));
        
        return DFS(1, coins.size() - 2);
    }
    //from left to right, one by one we will brust at end
    //O(N^3)
    //it will start from left to right
    // will brust each baloon, but in the end
    // i will be from left to right
    // it will brust left to i - 1 first, then i+1 to right then it will brust Ith
    // so during calculation if ith, 
    // it will be the item left-1 * ith * right + 1
    int DFS(int left, int right) {
        if(left > right) {
            return 0;
        }
        if(dp[left][right] != -1) return dp[left][right];
        
        //dp[left][right] = 0;
        int maxCoin = 0;
        for(int i = left; i <= right; i++) {
            int count = 0;
            count = coins[left-1] * coins[i]* coins[right+1]; //<= from left to i - 1 is already brust
            //so for i, we will take left -1 & right + 1
            count += DFS(left, i-1) + DFS(i+1, right); 
            maxCoin = max(maxCoin, count);
        }
        dp[left][right] = maxCoin;
        return dp[left][right];
    }
};
/*
3 5 8

15
5 8
15+40+8



*/