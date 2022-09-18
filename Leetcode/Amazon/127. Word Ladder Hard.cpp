/* 
127. Word Ladder Hard

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/
class Solution {
public:
    unordered_set<string> wordSet;
    int minWordCount = INT_MAX;
    //TLE: DFS
    
    /*
    Runtime: 121 ms, faster than 85.43% of C++ online submissions for Word Ladder.
Memory Usage: 14.1 MB, less than 68.27% of C++ online submissions for Word Ladder.
    */
    
    //O(N * L^2)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        for(int i = 0; i < wordList.size(); i++) {
            wordSet.insert(wordList[i]);
        }
        
        //BFS
        /*
        take word
        find all next word
        check if they exists on set
        then add to q, remove it from set
        
        */
        
        queue<string> q;
        q.push(beginWord);
        
        int depth = 0;
        while(!q.empty()) {
            int size = q.size();
            
            depth++;
            //O(N) -> number of word, can be maximum
            while(size-- > 0) {
                string str = q.front();
                q.pop();
                
                if(str == endWord) {
                    return depth;        
                }
                
                //O(L * 26 * L) L = length of string
                //first L is for, for loop, second L is to create hash
                for(int i = 0; i < str.size(); i++) {
                    char original = str[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        str[i] = ch;
                        if(wordSet.find(str) != wordSet.end()) {
                            q.push(str);
                            wordSet.erase(str);
                        }
                    }
                    str[i] = original;
                }
                
            }
        }
        
        
        return 0;
        //TLE
        //solve(beginWord, endWord, 1); //begin word is also in thie list
        //if(minWordCount == INT_MAX) return 0;
        //else return minWordCount;
    }
    
    void solve(string curWord, string & endWord, int curCount) {
        //cout<<curWord<<endl;
        if(curCount > minWordCount) return;
        
        if(curWord == endWord && curCount < minWordCount) {
            minWordCount = curCount;
            return;
        } 
        
        wordSet.erase(curWord);
        
        string tempStr = curWord;
        for(int i = 0; i < curWord.size(); i++) {
            for(int j = 0; j < 26; j++) {
                tempStr[i] = 'a' + j;
                //cout<<"\t"<<tempStr<<endl;
                if(wordSet.find(tempStr) != wordSet.end()) {
                    solve(tempStr, endWord, curCount+1);
                }
            }
            tempStr[i] = curWord[i];
        }
        
        wordSet.insert(curWord);
        
    }
    
};