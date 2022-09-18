/*
994. Rotting Oranges Medium
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/
class Solution {
public:
    /*
    Runtime: 20 ms, faster than 16.08% of C++ online submissions for Rotting Oranges.
Memory Usage: 13.3 MB, less than 31.08% of C++ online submissions for Rotting Oranges.
    */
    //O(N) time & space
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;
        
        int rotten = 0;
        int fresh = 0;
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) {
                    rotten++;
                    q.push(make_pair(i, j));
                }
            }
        }
        
        while(!q.empty()) {
            
            int size = q.size();
            bool anyRottedThisTime = false;
            while(size-- > 0) {
                auto pr = q.front();
                q.pop();
                
                //get neighbours
                //if good, make bad, push to q
                vector<pair<int,int>> neighbours = getGoodNeighbours(grid, pr.first, pr.second);
                
                for(auto pr: neighbours) {
                    q.push(pr);
                    grid[pr.first][pr.second] = 2;
                    fresh--;
                    anyRottedThisTime = true;
                }
            
            }
            if(anyRottedThisTime)
                minute++;
            //cout<<"minute "<<minute<<" freshleft " <<fresh << "q size "<<q.size()<<endl;
        }
        
        if(fresh > 0) return -1;
        else return minute;
    }
    
    vector<pair<int,int>> getGoodNeighbours(vector<vector<int>> &grid, int r, int c) {
        vector<pair<int,int>> result;
        
        if(r + 1 < grid.size() && grid[r+1][c] == 1) {
            result.push_back(make_pair(r+1, c));
        }
        
        if(r - 1 >= 0 && grid[r-1][c] == 1) {
            result.push_back(make_pair(r-1, c));
        }
        if(c + 1 < grid[r].size() && grid[r][c+1] == 1) {
            result.push_back(make_pair(r, c + 1));
        }
        
        if(c - 1 >= 0 && grid[r][c-1] == 1) {
            result.push_back(make_pair(r, c-1));
        }
        
        
        return result;
    }
};