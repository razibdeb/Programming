/*
329. Longest Increasing Path in a Matrix Hard

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg
 
Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/

class Solution {
public:
    
    /*
    Runtime: 66 ms, faster than 66.02% of C++ online submissions for Longest Increasing Path in a Matrix.
Memory Usage: 15.9 MB, less than 79.30% of C++ online submissions for Longest Increasing Path in a Matrix.
    */
    vector<vector<int>> dp;
    //vector<vector<bool>> visited;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp = vector<vector<int>>(matrix.size(), vector<int> (matrix[0].size(), -1));
        //visited is not needed, because, we only move to bigger items,
        //and came from smaller items
        //visited = vector<vector<bool>>(matrix.size(), vector<int> (matrix[0].size(), false));
        int result = 0;
        for(int i = 0; i< matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                int d = getMaxDepthDFS(matrix, i, j);
                result = max(result, d);
            }
        }
        return result;
    }
    int getMaxDepthDFS(vector<vector<int>>& matrix, int r , int c) {
        //if(r < 0 ||  c < 0 || r >= matrix.size() || c >= matrix[r].size()) return 0;
        
        if(dp[r][c] != -1) return dp[r][c];
        
        
        int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
        int curValue = matrix[r][c];
        
        if(r + 1 < matrix.size() && curValue > matrix[r + 1][c]) {
            d1 = getMaxDepthDFS(matrix, r+1, c);
        }
        if(r - 1 >= 0 && curValue > matrix[r - 1][c]) {
            d2 = getMaxDepthDFS(matrix, r - 1, c);
        }
        if(c + 1 < matrix[r].size() && curValue > matrix[r][c+1]) {
            d3 = getMaxDepthDFS(matrix, r, c+1);
        }
        if(c - 1 >= 0 && curValue > matrix[r][c-1]) {
            d4 = getMaxDepthDFS(matrix, r, c-1);
        }
        dp[r][c] = max(max(d1, d2), max(d3, d4)) + 1; //1 for this cell
        return dp[r][c];
    }
};