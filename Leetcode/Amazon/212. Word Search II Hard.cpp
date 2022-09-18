/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/
class Trie{
  public:
    bool isWord;
    Trie * next[26];
    string word;
    Trie() {
        isWord = false;
        for(int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

void addWord(Trie * root, string word) {
    for(int i = 0; i< word.size(); i++) {
        int idx = word[i] - 'a';
        if(root->next[idx] == nullptr) {
            root->next[idx] = new Trie();
        }
        root = root->next[idx];
    }
    root->isWord = true;
    root->word = word;
    //cout<<"added "<<root->word<<endl;
}

bool searchWord(Trie *  root, string word) {
    for(int i = 0; i < word.size(); i++) {
        int idx = word[i] - 'a';
        if(root->next[idx] == nullptr) return false;
        root = root->next[idx];
    }
    
    if(root->isWord) {
        cout<<"Found "<<root->word<<endl;
        return true;
    } else {
        cout<<"Not found "<<word<<endl;
        return false;
    }
}

class Solution {
public:
    Trie * root;
    int maxLength = 0;
    unordered_set<string> result; //need set to take one word at most once
    
    //O(M * N * 3 ^ L)
    /*
    Runtime: 1448 ms, faster than 29.82% of C++ online submissions for Word Search II.
Memory Usage: 13.3 MB, less than 44.59% of C++ online submissions for Word Search II.
    */
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Trie();
        
        for(int i = 0; i < words.size(); i++) {
            addWord(root, words[i]);
            //searchWord(root, words[i]);
            maxLength = max(maxLength, (int)words[i].size());
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                //cout<<" "<<i<<" "<<j<<"   --------"<<endl;
                visit(board, i, j, root, 0);
                
            }
        }
        vector<string> resultVector;
        for(auto it: result) {
            resultVector.push_back(it);
        }
        return resultVector;
    }
    //O(3^L) L = maximum length of a word
    void visit(vector<vector<char>>& board, int r, int c, Trie * node, int depth) {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return;
        
        if(board[r][c] == -1) return;
        
        int idx = board[r][c] - 'a';
        
        if(node == nullptr) return;

        if(node->next[idx] == nullptr) return;
        
        if(depth == maxLength) return;
        
        node = node->next[idx];
        
        //cout<<r <<" "<<c<<" "<<board[r][c]<<endl;
        //we have to put this checking after previous line, otherwise same word will be added multipe times
        if(node->isWord) {
            //cout<<"word "<<node->word<<endl;
            result.insert(node->word);
        }
        //making this so no one comes visit this cell again
        board[r][c] = -1;
        visit(board, r + 1, c, node, depth + 1);
        visit(board, r - 1, c, node, depth + 1);
        visit(board, r, c + 1, node, depth + 1);
        visit(board, r, c - 1, node, depth + 1);
        board[r][c] = idx + 'a';
    }
};