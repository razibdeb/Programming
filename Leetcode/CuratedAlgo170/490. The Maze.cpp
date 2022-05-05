/*
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).

 

Example 1:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
Example 2:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
Example 3:

Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false
 

Constraints:

m == maze.length
n == maze[i].length
1 <= m, n <= 100
maze[i][j] is 0 or 1.
start.length == 2
destination.length == 2
0 <= startrow, destinationrow <= m
0 <= startcol, destinationcol <= n
Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
The maze contains at least 2 empty spaces.
*/


/*
Amazon|4
Google|3
Snapchat|3
ByteDance|3
*/


class Solution {
public:
    /*
    no help
    Runtime: 90 ms, faster than 32.84% of C++ online submissions for The Maze.
Memory Usage: 20.7 MB, less than 51.33% of C++ online submissions for The Maze.
    */
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        
        q.push(make_pair(start[0], start[1]));
        
        while(!q.empty()) {
            
            pair<int,int> point = q.front();
            q.pop();
            
            if(point.first == destination[0] && point.second == destination[1]) return true;
            
            if(visited[point.first][point.second] == true) continue;
            
            visited[point.first][point.second] = true;
            
            auto neighbours = getNeighbour(maze, point.first, point.second);
            
            for(auto it: neighbours) {
                q.push(it);
            }
            
        }
        return false;
    }
    
    vector<pair<int,int>> getNeighbour(vector<vector<int>> &maze, int a, int b) {
        int r = maze.size();
        int c = maze[0].size();
        vector<pair<int,int>> result;
        //top
        int x = a, y = b;
        while(x-1 >= 0 && maze[x-1][b] == 0) x--;
        if(x != a) result.push_back(make_pair(x, b));
        
        //down
        x = a;
        while(x+1 < r && maze[x+1][b] == 0) x++;
        if(x != a) result.push_back(make_pair(x, b));
        
        
        //right
        x = b;
        while(x+1 < c && maze[a][x+1] == 0) x++;
        if(x != b) result.push_back(make_pair(a, x));
        
        //left
        x = b;
        while(x-1 >= 0 && maze[a][x-1] == 0) x--;
        if(x != b) result.push_back(make_pair(a, x));
        
        return result;
    }
};