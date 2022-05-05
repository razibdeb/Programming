/*
370. Range Addition

You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

You have an array arr of length length with all zeros, and you have some operation to apply on arr. In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

Return arr after applying all the updates.

Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]

Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
Output: [0,-4,2,2,2,4,4,-4,-4,-4]

Constraints:

1 <= length <= 105
0 <= updates.length <= 104
0 <= startIdxi <= endIdxi < length
-1000 <= inci <= 1000

Amazon|36
Citadel|9
VMware|2
Visa|2
*/
class Solution {
public:
    /*
    Runtime: 28 ms, faster than 91.61% of C++ online submissions for Range Addition.
Memory Usage: 16.5 MB, less than 60.48% of C++ online submissions for Range Addition.
    */
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);
        /*
        think this as sqare wave
        we will only store the difference in index
        original 0 0 0 0  0 0
        after    0 5 5 5  0 0 => this should be after operation
        we store 0 5 0 0 -5 0
        then after applying all diff go through the whole array again and generate final result
        
        Time:
        O(n + k)
        
        n = length
        k = number of operation
        Space:
        
        
        */
        for(int i = 0; i < updates.size(); i++) {
            int startIndex = updates[i][0];
            int endIndex = updates[i][1];
            int inc = updates[i][2];
            
            result[startIndex] += inc;
            if(endIndex+1 < length)
                result[endIndex+1] -= inc;
        }
        
        for(int i = 1; i < length; i++) {
            result[i] = result[i] + result[i-1];
        }
        return result;
    }
};
