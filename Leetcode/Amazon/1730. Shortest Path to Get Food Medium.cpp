/*
1730. Shortest Path to Get Food Medium
You are starving and you want to eat food as quickly as possible. You want to find the shortest path to arrive at any food cell.

You are given an m x n character matrix, grid, of these different types of cells:

'*' is your location. There is exactly one '*' cell.
'#' is a food cell. There may be multiple food cells.
'O' is free space, and you can travel through these cells.
'X' is an obstacle, and you cannot travel through these cells.
You can travel to any adjacent cell north, east, south, or west of your current location if there is not an obstacle.

Return the length of the shortest path for you to reach any food cell. If there is no path for you to reach food, return -1.

 

Example 1:


Input: grid = [["X","X","X","X","X","X"],["X","*","O","O","O","X"],["X","O","O","#","O","X"],["X","X","X","X","X","X"]]
Output: 3
Explanation: It takes 3 steps to reach the food.
Example 2:


Input: grid = [["X","X","X","X","X"],["X","*","X","O","X"],["X","O","X","#","X"],["X","X","X","X","X"]]
Output: -1
Explanation: It is not possible to reach the food.
Example 3:


Input: grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["X","X","X","X","X","X","X","X"]]
Output: 6
Explanation: There can be multiple food cells. It only takes 6 steps to reach the bottom food.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
grid[row][col] is '*', 'X', 'O', or '#'.
The grid contains exactly one '*'.
*/

/*
Runtime: 242 ms, faster than 17.22% of C++ online submissions for Shortest Path to Get Food.
Memory Usage: 31.2 MB, less than 19.20% of C++ online submissions for Shortest Path to Get Food.
*/
class Solution {
public:
    pair<int, int> me;
    vector<pair<int,int>> food;
    vector<pair<int,int>> getNeighbour(vector<vector<char>>& grid, int r, int c) {
        vector<pair<int,int>> result;
        if(r + 1 < grid.size()) {
            result.push_back(make_pair(r+1, c));
        }
        if(c + 1 < grid[r].size()) {
            result.push_back(make_pair(r, c+1));
        }
        if(r-1 >= 0) {
             result.push_back(make_pair(r-1, c));
        }
        if(c-1 >= 0) {
             result.push_back(make_pair(r, c-1));
        }
        return result;
    }
    int getFood(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '*') {
                    me.first = i;
                    me.second = j;
                }
            }
        }
        
        queue<pair<int,int>> q;
        q.push(make_pair(me.first, me.second));
        grid[me.first][me.second] = 'X';
        int depth = 0;
        while(!q.empty()) {
            
            int size = q.size();
            depth++;
            
            while(size-- > 0) {
                pair<int,int> current = q.front();
                q.pop();
                
                auto neighbours = getNeighbour(grid, current.first, current.second);
                for(auto n: neighbours) {
                    if(grid[n.first][n.second] == '#') {
                        return depth;
                    } else if(grid[n.first][n.second] == 'O') {
                        grid[n.first][n.second] = 'X';
                        q.push(n);
                    }
                }
                
            }
        }
        return -1;
    }
};