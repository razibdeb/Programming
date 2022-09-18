
/*
200. Number of Islands
Medium

14416

340

Add to List

Share
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

class Solution {
public:
    /*
    Runtime: 56 ms, faster than 42.78% of C++ online submissions for Number of Islands.
Memory Usage: 12.3 MB, less than 84.17% of C++ online submissions for Number of Islands.
    */
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    visit(grid, i, j);
                }
            }
        }
        return count;
    }
    
    void visit(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size())
            return;
        if(grid[r][c] == '0') return;
        
        grid[r][c] = '0';
        
        visit(grid, r + 1, c);
        visit(grid, r - 1, c);
        visit(grid, r, c + 1);
        visit(grid, r, c - 1);
    }
};