/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109
 

Follow-up: Could you find a solution with O(n) time complexity?
*/
class Solution {
public:
    /*
    Runtime: 37 ms, faster than 61.53% of C++ online submissions for Sum of Subarray Ranges.
Memory Usage: 11.5 MB, less than 18.51% of C++ online submissions for Sum of Subarray Ranges.
    */
    //O(n)
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev_smaller_idx(n, -1);
        vector<int> next_smaller_idx(n, n);
        //if we know immediate prev smaller idx, that means we know in middle all elements are bigger then current item, and this is the smallest item in ranges created from last smaller index to this
        stack<int> smallStack;
        
        for(int i = 0; i < n; i++) {
            while(!smallStack.empty() && nums[smallStack.top()] >= nums[i]) {
                smallStack.pop();
            }
            
            if(smallStack.empty()) {
                prev_smaller_idx[i] = -1;
            } else {
                prev_smaller_idx[i] = smallStack.top();
            }
            smallStack.push(i);
        }
        
        while(!smallStack.empty()) smallStack.pop();
        
        for(int i = n - 1; i >= 0; i--) {
            while(!smallStack.empty() && nums[smallStack.top()] > nums[i] )
                smallStack.pop();
            
            if(smallStack.empty()) {
                next_smaller_idx[i] = n;
            } else {
                next_smaller_idx[i] = smallStack.top();
            }
            smallStack.push(i);
        }
        
        long long minSum = 0;
        for(int i = 0; i < n ; i++) {
            int leftCount = i - prev_smaller_idx[i];
            int rightCount = next_smaller_idx[i] - i;
            
            long long totalCount = leftCount * rightCount;
            
            minSum += nums[i] * totalCount;
        }
        
        //cout<<"Min Sum "<<minSum<<endl;
        
        //////////////////////////
        vector<int> prev_bigger_idx(n, -1);
        vector<int> next_bigger_idx(n, n);
        
        while(!smallStack.empty()) smallStack.pop();
        
        for(int i = 0; i < n; i++) {
            while(!smallStack.empty() && nums[smallStack.top()] <= nums[i]) {
                smallStack.pop();
            }
            
            if(smallStack.empty()) {
                prev_bigger_idx[i] = -1;
            } else {
                prev_bigger_idx[i] = smallStack.top();
            }
            smallStack.push(i);
        }
        

        while(!smallStack.empty()) smallStack.pop();
        
        for(int i = n - 1; i >= 0; i--) {
            while(!smallStack.empty() && nums[smallStack.top()] < nums[i] )
                smallStack.pop();
            
            if(smallStack.empty()) {
                next_bigger_idx[i] = n;
            } else {
                next_bigger_idx[i] = smallStack.top();
            }
            smallStack.push(i);
        }
       
        long long maxSum = 0;
        for(int i = 0; i < n ; i++) {
            int leftCount = i - prev_bigger_idx[i];
            int rightCount = next_bigger_idx[i] - i;
            
            long long totalCount = leftCount * rightCount;
            
            maxSum += nums[i] * totalCount;
        }
        //cout<<"Max Sum: "<<maxSum<<endl;
        return maxSum - minSum;
    }
    //O(n^2)
    /*
    Runtime: 128 ms, faster than 39.29% of C++ online submissions for Sum of Subarray Ranges.
Memory Usage: 10.4 MB, less than 71.25% of C++ online submissions for Sum of Subarray Ranges.
    */
    
    long long subArrayRanges1(vector<int>& nums) {
        int n = nums.size();
        
        long long range = 0;
        for(int i = 0; i < n; i++) {
            long long mx = nums[i];
            long long mn = nums[i];
            
            for(int j = i + 1; j < n; j++) {
                mx = max(mx, (long long) nums[j]);
                mn = min(mn, (long long) nums[j]);
                
                range += mx - mn;
            }
        }
        
        return range;
    }
};

/*
1 2 3

1 = 0   min 1 max 1
2 = 0   min 2 max 2
3 = 0   min 3 max 3

1 2     min 1 max 2
2 3     min 2 max 3
1 2 3   min 1 max 3



we can get sum of all mins & sum of all maxs 
then get difference, which will reduce it to n

1 2 1 3
1 2
2 1
1 3
1 2 1
2 1 3
1 2 1 3

*/