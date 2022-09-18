/*
39. Combination Sum Medium


Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
*/
class Solution {
public:
    
    /*
    Runtime: 44 ms, faster than 32.53% of C++ online submissions for Combination Sum.
Memory Usage: 22.3 MB, less than 27.74% of C++ online submissions for Combination Sum.
    */
    
    //https://www.youtube.com/watch?v=GBKI9VSKdGg
    //
    //height of the tree will be Target/minimum value among candidate
    //if minimum value is 1 then height will be T
    // if minimum value is X then height will be T/X
    //at each step we will have N number of choice-> though this will reduce each step
    // complexity N^(T/M + 1) space (T/M)
    
    //the maximal number of nodes in N-ary tree of H height is N^(H+1)

    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curResult;
        DFS(candidates, 0, curResult, 0, target);
        return result;
    }
    /*
    a b c d
    when we are at b, we will only consider items from b to d, not a
    because if we consider a at b, it will be duplicate
    we will discard the previous items in particular index, this way we can discard duplicates
    for a
    aa                  ab                  ac                  ad
    aaa aab  aac aad    aba abb abc abd     aca acb acc acd     ada adb adc add
        ***             *** -> duplicate
    but if we discard previous 
    for b
    bb                  bc      bd
    bbb     bbc   bbd   bcd     X
    bbbb    bbcd   X     X
    no duplicate
    */
    
    void DFS(vector<int>& candidates, int index, vector<int> curResult, int curSum, int target) {
        if(curSum == target) {
            result.push_back(curResult);
            return; 
        }
        if(index == candidates.size() || curSum > target) return; 
        //no negative item, so curSum will always bigger then target, no need to calculate
        
        
        
        //take the same item, and then one by one others
        //at each step, for next loop do not take items before this item
        //if we are at I we will consider items from I to end
        //not items which were before I
        for(int i = index; i < candidates.size(); i++) {
            curResult.push_back(candidates[i]);
            
            DFS(candidates, i, curResult, curSum + candidates[i], target);
            curResult.pop_back();
        }
    }
    
};