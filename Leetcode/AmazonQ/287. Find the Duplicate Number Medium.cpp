/*
287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // fast goes two step
        //slow goes 1 step
        //if cycle then in future they will meet once
        //let's say, from start to cycle start is X
        //and A is a distance from start, where they both meet
        // cycle is C
        // so fast goes = X + nC + A  n=> number of cycle, it might travel multiple times
        // slow goes X + A
        // as slow goes half
        
        /*
        
        2(X + A) = X + nC + A
        => 2X + 2A = X + nC + A
        => X + A = nC
        => X = nC - A
        
        nC - A is the distance, slow need to travel to reach the cycle point,
        so if both one start to travel same pace, they will meet at X
        that is the cycle point
        */
        
        
        
        /*
        Approach 2: nLog(n)
        
        let's say we have numbers from 1 to N
        we will binary search for number from 1 to N, for each item,
        count how many numbers are <= OR >=
        let's say <=
        if it is bigger then item, then search left side, 1 to mid
        if it is smaller then item, that means, duplicate items on the other side
        
        
        */
        
        
        /*
        
        Runtime: 245 ms, faster than 23.66% of C++ online submissions for Find the Duplicate Number.
Memory Usage: 61.3 MB, less than 61.25% of C++ online submissions for Find the Duplicate Number.
        */
        int n = nums.size();
        
        int start = 1; 
        int end = n;
        
        while(start < end) {
            int mid = ( start + end ) / 2; //we are giong to search for all items less then this
            int count = 0; 
            
            for(int i = 0; i < n; i++) {
                if(nums[i] <= mid) count++;
            }
            
            if(count > mid) { //lesser items count is more then this item, that means duplicate item is between 1 to mid
                end = mid;
            } else {
                start = mid + 1; //if count == mid, that means from start to end, proper items, 
                //if count < mid, that means next item will never be mid, but could be mid + 1
            }
            
        }
        //think this 
        return start;
    }
};