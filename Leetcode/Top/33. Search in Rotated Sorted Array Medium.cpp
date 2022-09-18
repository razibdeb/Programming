/*
33. Search in Rotated Sorted Array Medium

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
Accepted
1,657,846
Submissions
4,323,302
*/
class Solution {
public:
    /*
    Runtime: 10 ms, faster than 26.63% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 11.1 MB, less than 29.48% of C++ online submissions for Search in Rotated Sorted Array.
    */
    int search(vector<int>& nums, int target) {
        //two way to solve this problem, 
        //first search for the mismatch point, then binary search
        //another way to search one time
        
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end) {
            
            int mid = start + (end - start) / 2;
            //cout<<start<<" "<<mid<<" "<<end<<endl;
            if(nums[mid] == target) return mid;
            /*
            [3,1]
            1
            <=
            0 0 1 3 3 1 -> left portion 3 3 -> sorted for this we need <= 
            1 0 1
            1 1 1
            <
            0 0 1
            0 0 -1
            */
            //check if left portion is sorted
            //this needs to be <= for [3,1]
            if(nums[start] <= nums[mid]) {
                //check if target is in this portion
                if(nums[start] <= target && target <= nums[mid]) { //have to check including start & end
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else { //right portion is sorted
                //target is in this portion
                if(nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            //cout<<start<<" "<<mid<<" "<<end<<endl<<endl;
        }
        return -1;
    }
};