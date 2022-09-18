/*
42. Trapping Rain Water

-> same problem exists on algeexpert

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105*/
/*
Amazon|44

Goldman Sachs|43

Facebook|21

Bloomberg|18

Microsoft|10

Google|9

Apple|8

Adobe|7

Qualtrics|4

Uber|3

Oracle|3

Paypal|3

Tesla|3

Intuit|2

Intel|2

Citadel|2

National Instruments|2
*/
class Solution {
public:
    /*
    Runtime: 30 ms, faster than 23.43% of C++ online submissions for Trapping Rain Water.
Memory Usage: 20.5 MB, less than 15.76% of C++ online submissions for Trapping Rain Water.
    */
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int>leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            int mx = max(height[i], leftMax[i-1]);
            leftMax[i] = mx;
        }
        rightMax[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; i--) {
            int mx = max(rightMax[i+1], height[i]);
            rightMax[i] = mx;
        }

        int water = 0;
        
        for(int i = 1; i < n - 1; i++) {
            int mm = min(leftMax[i-1], rightMax[i+1]);
            if(mm > height[i]) {
                water += mm - height[i];
            }
        }
        
        return water;
    }
};

/*
best solutin
Time complexity: O(n)O(n). Single iteration of O(n)O(n).
Space complexity: O(1)O(1) extra space. Only constant space required for \text{left}left, \text{right}right, \text{left\_max}left_max and \text{right\_max}right_max.

int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}
*/