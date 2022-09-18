/*
140. Word Break II Hard
https://www.youtube.com/watch?v=fNVs1J2KCyo

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 

Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Break II.
Memory Usage: 7.1 MB, less than 82.93% of C++ online submissions for Word Break II.
*/
class Trie {
public:
    Trie * next[26] = {nullptr};
    bool isWord;
    Trie() {
        isWord = false;
    }
};

class Solution {
public:
    Trie *root;
    vector<string> result;
    /*
    approach:
    store the list of words in trie -> better then in set, map
    now from input string, start searching from begining to end
    at each index, if prefix is found in trie/word dict, partition it, and recursively 
    perform same operation for rest of the string
    
    complexity: O(N + 2^L)
    N = total number of characters in word list
    L = length of the input string
    */
    
    void insertWord(string word) {
        Trie * node = root;
        for(int i = 0; i < word.size(); i++) {
            int ch = word[i] - 'a';
            if(node->next[ch] == nullptr) {
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        
        node->isWord = true;
    }
    
    
    bool searchWord(string word) {
        //cout<<"Searching for "<<word<<endl;
        Trie * node = root;
        for(int i = 0; i < word.size(); i++) {
            int ch = word[i] - 'a';
            if(node->next[ch] == nullptr) {
                return false;
            }
            node = node->next[ch];
        }
        //cout<<"\t"<<"found "<<node->isWord<<endl;
        return node->isWord;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new Trie();
        
        for(int i = 0; i < wordDict.size(); i++) {
            insertWord(wordDict[i]);
        }
        string resultStr = "";
        solve(s, resultStr, 0);
        return result;
    }
    
    void solve(string input, string resultStr, int index) {
        if(index == input.size()) {
            result.push_back(resultStr);
            return;
        }
        string temp = "";
        for(int i = index; i < input.size(); i++) {
            temp += input[i];
            if(searchWord(temp)) {
                if(resultStr.size() != 0) {
                    string tempResult = resultStr + " " + temp;
                    solve(input, tempResult, i + 1);
                } else {
                    solve(input, temp, i + 1);
                }
            }
        }
    }
    
};