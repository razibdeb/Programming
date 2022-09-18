/*
694. Number of Distinct Islands Medium

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands.

 

Example 1:


Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1
Example 2:


Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

class Solution {
public:
    unordered_set<string> islands;
    int numDistinctIslands(vector<vector<int>>& grid) {
        
        //for  BFS
        // BFS(grid);
        // return islands.size();
        
        //for DFS
        /*
        Runtime: 64 ms, faster than 57.08% of C++ online submissions for Number of Distinct Islands.
Memory Usage: 27.6 MB, less than 65.72% of C++ online submissions for Number of Distinct Islands.
        */
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    string hash = "";
                    DFS(grid, i, j, hash, "S");
                    islands.insert(hash);
                }
            }
        }
        return islands.size();
    }
    /*
    https://leetcode.com/problems/number-of-distinct-islands/discuss/2232579/C%2B%2B-2-ideas-for-hashing-shape-Detailed-Explanation
    
     Other option is to save the direction of traversal during DFS. We use the following symbols:
    S = start, B = Backtrack, U = Up, D = Down, R = Right, L = Left.
    Each time we take a step during DFS, pass the appropriate direcyion alongside. Now the reason we have B as a dircetion is because
    with just the 4 directions, diff shapes might give the same traversal order.
    S                      
    |
    D
    |
    D-R
    |
    D
    
    S
    |
    D
    |
    D
    |
    D-R
    
    Both the shapes will give SDDDR without B.
    With B, shape 1: SDDDBRBBBB, shape 2: SDDDRBBBBB
    */
    void DFS(vector<vector<int>>& grid, int r, int c, string &hash, string direction) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size() || grid[r][c] != 1) 
            return;
        hash += direction;
        grid[r][c] = -1;
        DFS(grid, r + 1, c, hash, "D"); //down
        DFS(grid, r - 1, c, hash, "U");
        DFS(grid, r, c + 1, hash, "R");
        DFS(grid, r, c - 1, hash, "L");  
        hash += "B";
    }
    /*
    add the cell coordinates to traversal. We standarize the coordinates by bringing it to 
    to common reference. In this case, the start node is put to the top left cell i.e (0, 0)
    and all the cells of the islands are offset and moved to left and up by (row, col) of start node
    */
    void BFS(vector<vector<int>>& grid) {
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] != 1) continue;
                
                queue<pair<int, int>> q;
                int startRow = i;
                int startCol = j;
                string hash = "";
                q.push(make_pair(i, j));
                
                while(!q.empty()) {
                    auto rc = q.front();
                    q.pop();
                    
                    int r = rc.first;
                    int c = rc.second;
                    grid[r][c] = -1;
                    
                    if(r + 1 < grid.size() && grid[r+1][c] == 1) {
                        q.push(make_pair(r+1, c));
                    }
                    if(r - 1 >= 0 && grid[r-1][c] == 1) {
                        q.push(make_pair(r-1, c));
                    }
                    if(c -1 >= 0 && grid[r][c-1] == 1) {
                        q.push(make_pair(r, c - 1));
                    }
                    if(c + 1 < grid[r].size() && grid[r][c+1] == 1) {
                        q.push(make_pair(r, c + 1));
                    }
                    
                    hash = hash + "(" + to_string(r - startRow) + "," + to_string(c - startCol) + "),";
                }
                //cout<<hash<<endl;
                islands.insert(hash);
            }
        }
    }
};

/*
11211
11211

*/