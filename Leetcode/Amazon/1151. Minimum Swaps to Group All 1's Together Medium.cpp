/*
1151. Minimum Swaps to Group All 1's Together Medium


Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.

 

Example 1:

Input: data = [1,0,1,0,1]
Output: 1
Explanation: There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
Example 2:

Input: data = [0,0,0,1,0]
Output: 0
Explanation: Since there is only one 1 in the array, no swaps are needed.
Example 3:

Input: data = [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
 

Constraints:

1 <= data.length <= 105
data[i] is either 0 or 1.
*/
class Solution {
public:
    /*
    Runtime: 94 ms, faster than 90.32% of C++ online submissions for Minimum Swaps to Group All 1's Together.
Memory Usage: 68.8 MB, less than 24.18% of C++ online submissions for Minimum Swaps to Group All 1's Together.
    */
    int minSwaps(vector<int>& data) {
        //we have to find a place where densitiy of one is most
        //not necessarily it is at begining or end
        //to do that, we can find the number of ones first
        //then make a sliding window, shift from left to right,
        //and find a window where number of ones is most
        
        int ones = 0;
        for(int i = 0; i < data.size(); i++) {
            ones += data[i];
        }
        
        int start = 0; 
        int end = 0;
        int count = 0;
        
        
        while(end < ones) {
            count += data[end];
            end++;
        }
        
        int maxCount = count;
        //end is pointing to new index, now
        while(end < data.size()) {
            count -= data[start];
            count += data[end];
            end++;
            start++;
            if(count > maxCount) maxCount = count;
        }
        
        return ones - maxCount;
    }
};