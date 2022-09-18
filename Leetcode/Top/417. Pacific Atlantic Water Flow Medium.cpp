/*
417. Pacific Atlantic Water Flow Medium

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Example 2:

Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]
 

Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105
*/
class Solution {
public:
    /*
    Runtime: 82 ms, faster than 42.12% of C++ online submissions for Pacific Atlantic Water Flow.
Memory Usage: 19 MB, less than 54.04% of C++ online submissions for Pacific Atlantic Water Flow.
    */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        
        queue<pair<int, int>> queuePacific, queueAtlantic;

        //first row pacific
        for(int i = 0; i < c; i++) 
            queuePacific.push(make_pair(0, i));
        //first col
        for(int i = 0; i < r; i++)
            queuePacific.push(make_pair(i, 0));
        
        auto pacificMatrix = BFS(heights, queuePacific);
        
        
        //last row atlantic
        for(int i = 0; i < c; i++) 
            queueAtlantic.push(make_pair(r-1, i));
        //last col
        for(int i = 0; i < r; i++)
            queueAtlantic.push(make_pair(i, c - 1));
        
        auto atlanticMatrix = BFS(heights, queueAtlantic);
        
        vector<vector<int>> result;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(pacificMatrix[i][j] == true && atlanticMatrix[i][j] == true) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
    vector<vector<bool>> BFS(vector<vector<int>> &input, queue<pair<int, int>> q) {
        int r = input.size();
        int c = input[0].size();
        vector<vector<bool>> matrix(r, vector<bool>(c, false)); 
       
        while(!q.empty()) {
            int rr = q.front().first;
            int cc = q.front().second;
            q.pop();
           // cout<<rr<<" "<<cc<<endl;

            matrix[rr][cc] = true;
            
            if(rr + 1 < r && input[rr][cc] <= input[rr+1][cc] && matrix[rr+1][cc] != true ) {
                //cout<<"\t"<<rr+1<<" "<<cc<<endl;
                q.push(make_pair(rr+1, cc));
            }
            if(rr - 1 >= 0 && input[rr][cc] <= input[rr-1][cc] && matrix[rr-1][cc] != true ) {
               // cout<<"\t"<<rr-1<<" "<<cc<<endl;
                q.push(make_pair(rr-1, cc));
            }
            if(cc+1 < c && input[rr][cc] <= input[rr][cc+1] && matrix[rr][cc+1] != true) {
                //cout<<"\t"<<rr<<" "<<cc+1<<endl;
                q.push(make_pair(rr, cc+1));
            }
            if(cc - 1 >= 0 && input[rr][cc] <= input[rr][cc-1] && matrix[rr][cc-1] != true) {
                //cout<<"\t"<<rr<<" "<<cc-1<<endl;
                q.push(make_pair(rr, cc-1));
            } 
        }
        return matrix;
    }
};