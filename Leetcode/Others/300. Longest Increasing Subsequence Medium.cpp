/*
300. Longest Increasing Subsequence Medium

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/
class Solution {
public:
    /*
    Runtime: 12 ms, faster than 86.83% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 10.4 MB, less than 87.63% of C++ online submissions for Longest Increasing Subsequence.
    */
    
    //O(NLogN)
    int lengthOfLIS(vector<int>& nums) {
        /*
        
        lengthArray = > index 1 will contain the minimum number with longest sub sequence with 1 length
        maxLen => maximum length so far found
        */
        
        vector<int> lengthArray;
        int maxLen = 1;
        lengthArray.push_back(nums[0]);
        
        //O(n) number of items
        for(int i = 1; i < nums.size(); i++) {
            int start = 0;
            int end = maxLen - 1;
            int foundIndex = maxLen;
            
            //this is Log(n)
            while(start <= end) {
                
                //find the last item which is smaller then this
                int mid = ( start + end ) / 2;
                
                if(lengthArray[mid] < nums[i]) {
                    start = mid + 1;
                    foundIndex = mid;
                } else {
                    end = mid - 1;
                }
            }
            if(foundIndex == maxLen)//that means no items in result array found who is smaller then this item, that means it is the smallest
            {
                lengthArray[0] = nums[i];
            }
            else if(foundIndex == maxLen - 1) { // or last item is smaller then this item
                lengthArray.push_back(nums[i]);
                maxLen++;
            }
            else if(lengthArray[foundIndex+1] > nums[i]) {
                lengthArray[foundIndex+1] = nums[i];
            }
            
            /*cout<<"For i: "<<i<<" item: "<< nums[i]<<" FoundIndex "<<foundIndex<<endl;
            for(int k = 0; k < maxLen; k++) {
                cout<<lengthArray[k]<<" ";
            }
            cout<<endl;*/
        }
        
        return maxLen;
    }
};

//another
 /*
    Runtime: 12 ms, faster than 85.58% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 10.6 MB, less than 44.12% of C++ online submissions for Longest Increasing Subsequence.
    */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int maxLen = 0;
        vector<int> result(n, 1);
        result[0] = nums[0];
        maxLen++;
        for(int i = 1; i < n; i++) {
            int start = 0;
            int end = maxLen - 1;
            
            while(start <= end) {
                int mid = (start + end) / 2;
                if(result[mid] < nums[i]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            //start will point to the item which is next to item which is smaller ten this item
            
            if(start == maxLen) {
                maxLen++;
                result[start] = nums[i];
            } else {
                if(result[start] > nums[i])
                    result[start] = nums[i];
            }
            
            // cout<<"for item "<<nums[i]<<endl;
            // for(int j = 0; j < maxLen; j++) {
            //     cout<<result[j]<<" ";
            // }
            // cout<<endl;
        }
        return maxLen;
    }