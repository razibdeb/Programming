/*
973. K Closest Points to Origin Medium
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 < xi, yi < 104
*/
class Solution {
public:
    /*
    Runtime: 388 ms, faster than 50.49% of C++ online submissions for K Closest Points to Origin.
Memory Usage: 74.5 MB, less than 30.58% of C++ online submissions for K Closest Points to Origin.
    */
    //O(NLogK) N = number of points
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        if(k == points.size()) return points;
        
        auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
            int distance1 = lhs[0] * lhs[0] + lhs[1] * lhs[1];
            int distance2 = rhs[0] * rhs[0] + rhs[1] * rhs[1];
            return distance1 < distance2;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        int size = 0;
        while(size < k) {
            pq.push(points[size]);
            size++;
            //cout<<pq.top()[0]<<" "<<pq.top()[1]<<endl;
        }
        
        
        for(int i = k; i < points.size(); i++) {
            int topDistance = getDistance(pq.top());
            int d = getDistance(points[i]);
            if(topDistance > d) {
                pq.pop();
                pq.push(points[i]);
            }
        }
        
        vector<vector<int>> result;
        
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
        
    }
    int getDistance(vector<int> arr) {
        return arr[0] * arr[0] + arr[1] * arr[1];
    }
};