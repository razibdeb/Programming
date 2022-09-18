/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/
class Solution {
public:
    int jump2(vector<int>& nums) {
        if(nums.size() == 1) return 0; //no jump needed
        int canGo = nums[0];
        int idx = 1;
        int maxReach = canGo;
        int jump = 1;
        while(idx < nums.size()) {
            if(canGo >= nums.size() - 1) {
                return jump;
            }
            for(; idx <= canGo && idx < nums.size(); idx++) {
                maxReach = max(maxReach, idx + nums[idx]);
            }
            if(idx > maxReach) return 0; //not possible to reach
            
            jump++;
            canGo = maxReach;
        }
        
        return jump;
    }
    /*
    Runtime: 12 ms, faster than 96.65% of C++ online submissions for Jump Game II.
Memory Usage: 16.6 MB, less than 81.01% of C++ online submissions for Jump Game II.
    */
    int jump(vector<int> & nums) {
        if(nums.size() == 1) return 0;//no need to jump
        
        int currentSteps = nums[0];
        int maxReach = currentSteps;
        int jumps = 1; //already made a jump
        for(int i = 1; i < nums.size()-1; i++) { //remember this is n - 1
            if(maxReach < i + nums[i]) maxReach = i + nums[i];
            
            currentSteps--;
            
            if(currentSteps == 0) {
                if(maxReach <= i ) return -1;
                currentSteps = maxReach - i;
                jumps++;
                
                if(maxReach >= nums.size() - 1) return jumps;
            }
            
        }
        return jumps;
    }
};