/*
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit Medium

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= limit <= 109
*/
class Solution {
public:
    /*
    Runtime: 139 ms, faster than 87.17% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.
Memory Usage: 49.9 MB, less than 91.78% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.
    */
    //O(N)
     int longestSubarray(vector<int>& nums, int limit) {
         //https://www.youtube.com/watch?v=LDFZm4iB7tA
         //we will store maximum & minimum
         //for maximum we will keep a queue, where first item is maximum
         //if new item is bigger then that, remove it, push bigger
         //if new item is smaller then just push it
         //decreasing queue
         // we will push index
         // two pointer,
         //queue will contain maximum & minimum from start to end
         
         /*
         for 8 2 4 7
         
         queue is empty push 8
         2 is smaller then 8, push
         4 is bigger then back, pop 2 and push 4
         
         */
         
         deque<int> maxQueue, minQueue;
        
         int startIndex = 0;
         int endIndex = 0;
         int answer = 1;
         while(endIndex < nums.size()) {
             
             int item = nums[endIndex];
             //max queue will have biggest item at front, 
             //and will have decreasing items
             //so if now item is sma
             while(maxQueue.size() > 0 && nums[maxQueue.back()] <= item) maxQueue.pop_back();
             
             while(minQueue.size() > 0 && nums[minQueue.back()] >= item) minQueue.pop_back();
             
             maxQueue.push_back(endIndex);
             minQueue.push_back(endIndex);
             
             int maxi = nums[maxQueue.front()];
             int mini = nums[minQueue.front()];
             //cout<<"start "<<startIndex<<" end "<<endIndex<<" diff "<<maxi - mini<<endl;
             if(maxi - mini > limit) {
                 startIndex++;
                 if(maxQueue.front() < startIndex) maxQueue.pop_front();
                 if(minQueue.front() < startIndex) minQueue.pop_front();
             } else {
                 answer = max(answer, endIndex - startIndex + 1);
             }
            endIndex++;
        }
         
         return answer;
    }
    
    //timelimit excedded  N^2
    int longestSubarray2(vector<int>& nums, int limit) {
        int maxLen = 1;
        for(int i = 0; i < nums.size(); i++) {
            int minimum = nums[i];
            int maximum = nums[i];
            for(int len = 1; i + len < nums.size(); len++ ) {
                minimum = min(minimum, nums[i + len]);
                maximum = max(maximum, nums[i + len]);
                
                if(maximum - minimum <= limit) {
                    maxLen = max(maxLen, len+1);
                } else {
                    break;
                }
            }
        }
        return maxLen;
    }
};

/*

10 1 2 4 7 2


increamenting dqueue will give min at front
decreamenting dequeu will give max at front

min 10 
max 10

*/