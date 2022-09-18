/*
34. Find First and Last Position of Element in Sorted Array Medium 

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    /*
    Runtime: 7 ms, faster than 91.58% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 13.7 MB, less than 63.54% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size() - 1;
        int index = -1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) {
                index = mid;
                break;
            } else if(nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid  + 1;
            }
        }
        if(index == -1) {
            return {-1, -1};
        }
        int lowerBound = searchLowerBound(nums, target, index);
        int higherBound = searchUpperBound(nums, target, index);
        
        return {lowerBound, higherBound}; 
        
    }
    
    int searchLowerBound(vector<int> & nums, int target, int index) {
        int start = 0;
        int result = index;
        int end = index - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
    int searchUpperBound(vector<int> & nums, int target, int index) {
        int start = index + 1;
        int result = index;
        int end = nums.size() - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) {
                result = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return result;
    }
};