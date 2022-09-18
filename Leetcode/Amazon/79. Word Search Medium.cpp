/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

class Solution {
public:
    /*
    Runtime: 822 ms, faster than 28.63% of C++ online submissions for Word Search.
Memory Usage: 8 MB, less than 35.71% of C++ online submissions for Word Search.
    */
    
    /*
    we can improve it by checking the char count 
    */
    bool exist(vector<vector<char>>& board, string word) {
        
        if(word.size() == 0 )return false;
        if(board.size() == 0) return false;
        
        if(word.size() > board.size() * board[0].size()) return false;
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    bool found = bfs(board, word, i, j, 0);
                    if(found == true) return true;
                }
            }
        }
        
        return false;
    }
    
    bool bfs(vector<vector<char>>& board, string word, int r, int c, int l) {
        if(l >= word.size()) return false;
        
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return false;
        
        if(board[r][c] != word[l]) return false;
        
        if(l == word.size() - 1) return true;
        
        board[r][c] = 0;
        
        bool status = bfs(board, word, r + 1, c, l + 1) ||
            bfs(board, word, r, c + 1, l+ 1) ||
            bfs(board, word, r - 1, c, l + 1) ||
            bfs(board, word, r , c - 1, l + 1);
        
        board[r][c] = word[l];
        
        return status;
    }
};