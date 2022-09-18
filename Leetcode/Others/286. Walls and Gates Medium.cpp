/*
286. Walls and Gates Medium


You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

 

Example 1:


Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
Example 2:

Input: rooms = [[-1]]
Output: [[-1]]
 

Constraints:

m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 231 - 1.
*/
class Solution {
public:
    /*
    Runtime: 67 ms, faster than 43.70% of C++ online submissions for Walls and Gates.
Memory Usage: 14.4 MB, less than 69.57% of C++ online submissions for Walls and Gates.
    */
    //O(MN) space MN maximum MN cell we push
    void wallsAndGates(vector<vector<int>>& rooms) {
        /*
        
        WE HAVE TO UPDATE THE MATRIX WHEN WE PUSH IT TO QUEUE
        UPDATE DEPTH THEN PUSH
        THIS WAY WE WON'T PUSH DUPLICATE ITEMS TO QUEUE
        
        */
        int INF = 2147483647;
        int row = rooms.size();
        int col = rooms[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < rooms.size(); i++) {
            for(int j = 0; j < rooms[i].size(); j++) {
                //cout<<i<<" "<<j<<endl;
                if(rooms[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }
        
        int depth = 0;
        int d = 0;
        while(!q.empty()) {
            int size = q.size();
            //cout<<" ==================== "<<d++<<endl;
            for(int i = 0; i < size; i++) {
                
                auto cell = q.front();
                q.pop();
                
                int r = cell.first;
                int c = cell.second;

                depth = rooms[r][c] + 1;
                //cout<<r<<" "<<c<<" "<<depth<<endl;
                //can't use rooms[r+1][c] == INF
                //
                if(r + 1 < row && rooms[r+1][c] == INF) {
                    rooms[r+1][c] = depth;
                    q.push(make_pair(r+1, c));
                }
                if(r - 1 >= 0 && rooms[r-1][c] == INF) {
                    rooms[r-1][c] = depth;
                    q.push(make_pair(r-1, c));
                }
                if(c + 1 < col && rooms[r][c+1] == INF) {
                    rooms[r][c+1] = depth;
                    q.push(make_pair(r, c + 1));
                }
                if(c - 1 >= 0 && rooms[r][c-1] == INF) {
                    rooms[r][c-1] = depth;
                    q.push(make_pair(r, c - 1));
                }
            }
        }
    }
    
    
};