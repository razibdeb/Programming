/*
909. Snakes and Ladders Medium

You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

 

Example 1:


Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1
 

Constraints:

n == board.length == board[i].length
2 <= n <= 20
grid[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 do not have any ladders or snakes.

*/
class Solution {
public:
//DFS is not going to work, we have to use BFS
    int snakesAndLadders(vector<vector<int>>& board) {
        int n  = board.size();
        vector<bool> visited(n*n + 1, false);

        queue<int> q;

        q.push(1);
        visited[1] = true;
        int steps = 0;
        while(!q.empty() && steps <= n * n) {

            int size = q.size(); 
            while(size-- > 0) {
                int curIndex = q.front();
                q.pop();
                //cout<<"cur index "<<curIndex<<" step: "<<steps<<endl;
                if(curIndex == n*n) return steps;

                for(int i = curIndex + 1; i <= n * n && i <= curIndex + 6; i++) {
                    if(visited[i] == false && true) {
                        visited[i] = true;
                        int row, col;
                        getRowCol(i, n, row, col);
                        
                        if(board[row][col] == -1) {
                            q.push(i);
                            //cout<<"\tcur index "<<i<<" next index"<<i<<" step: "<<steps<<endl;
                        } 
                        else {
                            q.push(board[row][col]);
                            //cout<<"\tcur index "<<i<<" next index"<<board[row][col]<<" step: "<<steps<<endl;
                        }
                            
                       
                    }
                }
                
            }
            steps++;
        }

        return -1;

        // vector<int> dp(board.size() * board.size() + 1, -1);
        // vector<bool> visited(board.size() * board.size() + 1, false);
        // int minSteps = getMinSteps(board, 1, visited, dp);
        // if(minSteps == INT_MAX) return -1;
        // else return minSteps;
    }
    
    void getRowCol(int index, int n, int &r, int &c) {
        /* 
        1 => 5 0
        2 => 5 1
        6 => 5 5

        7 => 4 5

        1 ~ n => n-1 item-1

    
        index--;

        row number from down = index / n -> from zero 

        rowIndex = n-1 - rowNumber 

        if row number odd 
            start from left
            col index = index % n
        if row number even 
            start from right
            col = n - 1 - index % n
        */

        int rowNumber = (index - 1) / n + 1; // this will give row number 1 to 6
        index--;
        
        int rowIndex = n - rowNumber; // this will give index 
        int colIndex;
        if(rowNumber % 2 != 0) { // if odd, then starts from left, & as index is already decreased
            colIndex = index % n;
        } else {
            colIndex = n - 1 - index % n; // starts from right
        }
        //cout<<"\t\t "<<index+1<<" row number "<<rowNumber<<" rowindex "<<rowIndex<<" "<<colIndex<<endl;;
        r = rowIndex;
        c = colIndex;
    }
    //DOES NOT WORK
    //DFS is going to make infinite loop
    int getMinSteps(vector<vector<int>>& board, int index,vector<bool> &visited, vector<int> &dp) {
        cout<<index<<endl;
        int n = board.size();
        if(index == n*n) return 0;

        if(visited[index] == true) return INT_MAX;
        visited[index] = true;
        
        if(dp[index] != -1) return dp[index];
        cout<<"\tcalculating"<<endl;
        int rowIndex, colIndex;
        getRowCol(index, n, rowIndex, colIndex);
        cout<<"\tfor index "<<index<<" r "<<rowIndex<<" "<<colIndex<<endl;
        if(board[rowIndex][colIndex] != -1) {
            cout<<"\tjumping"<<endl;
            int minSteps = getMinSteps(board, board[rowIndex][colIndex], visited, dp);
            if(minSteps != INT_MAX) {
                dp[index] = minSteps+1;
            }
            else {
                dp[index] = INT_MAX;
            }
            cout<<"for "<<index<<" result: "<<dp[index]<<endl;
            return dp[index];
        }

        int minSteps = INT_MAX;
        for(int i = index+1; i <= index + 6 && i <= n*n; i++) {
            minSteps = min(minSteps, getMinSteps(board, i, visited, dp));
        }
        if(minSteps != INT_MAX) {
            dp[index] = minSteps + 1;
        } else {
            dp[index] = INT_MAX;
        }
        cout<<"for "<<index<<" result: "<<dp[index]<<endl;
        return  dp[index];
    }
};
/*
0 L
1 R
2 L 
3 R
4 L


*/