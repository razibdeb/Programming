/*
78. Subsets Medium

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
class Solution {
public:
    /*
    Runtime: 7 ms, faster than 36.24% of C++ online submissions for Subsets.
Memory Usage: 16 MB, less than 20.25% of C++ online submissions for Subsets.
    */
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        solve(nums, 0, subset);
        return result;
    }
    
    void solve(vector<int> & nums, int index, vector<int> subset) {
        if(index == nums.size()) {
            result.push_back(subset);
            return;
        }
        solve(nums, index+1, subset);
        subset.push_back(nums[index]);
        solve(nums, index+1, subset);
    }
    
    //8 ms  ------ Iterative
    vector<vector<int>> subsetsIterative(vector<int>& nums) {
        vector<vector<int>> resultSet;
        int n = nums.size();
        //if n is bigger then 32 it won't work
        for(int i = 0; i < (1 << n); i++) {
            vector<int> tempResult;
            //check for each bit of I, which is 32
            for(int j = 0; j < 32; j++){
                if( i & (1 << j)) {
                    //cout<<i<<" "<< (1<<j) <<endl;
                    //cout<<"\t"<<j<<endl;
                    tempResult.push_back(nums[j]);
                }
            }
            resultSet.push_back(tempResult);
        }
        return resultSet;
    }
};