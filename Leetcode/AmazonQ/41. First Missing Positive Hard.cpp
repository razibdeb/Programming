/*
41. First Missing Positive Hard
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
*/
class Solution {
public:
    
    /*
    Runtime: 176 ms, faster than 90.19% of C++ online submissions for First Missing Positive.
Memory Usage: 83 MB, less than 77.70% of C++ online submissions for First Missing Positive.
    */
    int firstMissingPositive(vector<int>& nums) {
        /*
        
        approach 1:
        search for 1 to N
        mark all negative values to 0-> because we are not considering zero as answer
        we can't make zero cause we will mark values to negative which index is exists
        mark all negative values to 1, -> but have to look for 1 first, if it doesn't exits
        then it is the answer
        mark all numbers bigger then N+1 -> as it will never be an anser *****
        otherwise we know 1 exists, no no problem marking all zero & negative to 1
        
        
        */
        
        int n = nums.size();
        bool isOneExists = false;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                isOneExists = true;
                break;
            }
        }
        
        if(isOneExists == false) return 1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }
        
        for(int i = 0; i < n; i++) {
            int value = abs(nums[i]) - 1;
            if(nums[value]  > 0 ) {
                nums[value] = -1 * nums[value];
            }
            
        }
        int idx = 0;
        
        for(; idx < n; idx++) {
            //cout<<nums[idx]<<endl;
            if(nums[idx] > 0) {
                return idx + 1;
            }
        }
        return idx + 1;
        
    }
};