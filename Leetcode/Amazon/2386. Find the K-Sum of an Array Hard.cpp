/*
2386. Find the K-Sum of an Array Hard


You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.

We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).

Return the K-Sum of the array.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Note that the empty subsequence is considered to have a sum of 0.

 

Example 1:

Input: nums = [2,4,-2], k = 5
Output: 2
Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
- 6, 4, 4, 2, 2, 0, 0, -2.
The 5-Sum of the array is 2.
Example 2:

Input: nums = [1,-2,3,4,-10,12], k = 16
Output: 10
Explanation: The 16-Sum of the array is 10.
 

Constraints:

n == nums.length
1 <= n <= 105
-109 <= nums[i] <= 109
1 <= k <= min(2000, 2n)

*/
class Solution {
public:
    /*
    Runtime: 429 ms, faster than 22.21% of C++ online submissions for Find the K-Sum of an Array.
Memory Usage: 64.2 MB, less than 52.01% of C++ online submissions for Find the K-Sum of an Array.
    */
    long long kSum(vector<int>& nums, int k) {
        /*
        first get a sum of all positivie nubmer which will be largest
        
        next remove all combination of items whose sum is smallest 
        trick is, there are some negative items, at first we won't add them
        later we make them postiive and remove by this way we actually adding them to sum 
        
        positive sum = 10
        negative item -2, smallest item 1
        we can get 10 - 1 = 9 removing 1
        10 + (-2) = 8 Adding -2 
        
        we will sort after getting sum and making each of them positive
        
        now will remove each combination of items from smaller ones
        as we need to sort them we will use priority queue
        
        from total we remove 0 item and push to queue [total-item, index]
        
        pop from queue -> which is maximum
        we will push with [total - newItem, index + 1] -> we are removing first one, to make a combination
        & total - item - newItem, index
        
        next we will do again total-
        let's say toatal was 10 and lowest items are 1 2 3
        1=> 10 - 1 = [9, 0]
        pop 
        
        
        */
        
        long long total = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                total += nums[i];
            } else {
                nums[i] = -1* nums[i];
            }
        }
        if(k == 1) return total;
        k--;
        
        sort(nums.begin(), nums.end());
        //cout<<"Afer sort "<<nums[0]<<" "<<nums[1]<<endl;
        // priority_queue< 
        //     pair<long long, int>, 
        //     vector<pair<long long, int>>, 
        //     greater<pair<long long, int>>
        // > pq;
        
        priority_queue<pair<long, long>> pq;
        
        //pair<ll,int>,vector<pair<long long,int>>, greater<pair<long long,int>
        
        pq.push(make_pair(total - nums[0], 0));
        
        long long answer = total- nums[0];
        
        while(k > 0) {
            auto top = pq.top();
            pq.pop();
            //long long needed to solve integer overflow
            long long curSum = top.first;
            int index = top.second;
            //cout<<curSum<<endl;
            answer = curSum;
            
            if(index + 1 < n) {
                //cout<<"\t"<<curSum + nums[index] - nums[index+1]<<" "<<curSum - nums[index+1]<<endl;
                pq.push(make_pair(curSum + nums[index] - nums[index+1], index+1));
                pq.push(make_pair(curSum - nums[index+1], index + 1));
            }
            k--;   
        }
        return answer;
    }
};