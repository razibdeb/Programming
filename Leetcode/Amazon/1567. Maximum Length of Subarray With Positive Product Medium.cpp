/*
1567. Maximum Length of Subarray With Positive Product Medium
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

 

Example 1:

Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.
Example 2:

Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
Example 3:

Input: nums = [-1,-2,-3,0,1]
Output: 2
Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
class Solution {
public:
    
    /*
    Runtime: 218 ms, faster than 19.22% of C++ online submissions for Maximum Length of Subarray With Positive Product.
Memory Usage: 57.8 MB, less than 78.16% of C++ online submissions for Maximum Length of Subarray With Positive Product.
    */
    /*
    if we only go from left to right, then it won't work, have to try from right to left as well
    [5,-20,-20,-39,-5,0,0,0,36,-32,0,-7,-10,-7,21,20,-12,-34,26,2]
    [-7,-10,-7,21,20,-12,-34,26,2]
    from left to right, we will include -7, and result will be 6
    but if we exclude -7, result will be 8
    */
    int getMaxLen(vector<int>& nums) {
        int negativeCount = 0;
        int start = 0;
        int maxLen = 0;
        int consecutivePositiveCount = 0;
        for(int i = 0; i < nums.size();) {
            while(i < nums.size() && nums[i] == 0) i++;
            start = i;
            negativeCount = 0;
            consecutivePositiveCount = 0;
            while(i < nums.size() && nums[i] != 0) {
                if(nums[i] < 0) {
                    negativeCount++;
                    consecutivePositiveCount = 0;
                } else {
                    consecutivePositiveCount++;
                    maxLen = max(maxLen, consecutivePositiveCount);
                }
                
                if(negativeCount % 2 == 0) {
                    maxLen = max(maxLen, i - start + 1);
                }
                ++i;
            }
            
        }

        consecutivePositiveCount = 0;
        
        for(int i = nums.size() - 1; i >= 0;) {
            while(i >= 0 && nums[i] == 0) i--;
            start = i;
            negativeCount = 0;
            consecutivePositiveCount = 0;
            while(i >= 0 && nums[i] != 0) {
                if(nums[i] < 0) {
                    negativeCount++;
                    consecutivePositiveCount = 0;
                } else {
                    consecutivePositiveCount++;
                    maxLen = max(maxLen, consecutivePositiveCount);
                }
                
                if(negativeCount % 2 == 0) {
                    maxLen = max(maxLen, start - i + 1);
                }
                --i;
            }
            
        }
        
        return maxLen;
    }
};