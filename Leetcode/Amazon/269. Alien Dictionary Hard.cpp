/*
269. Alien Dictionary Hard
There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there is no solution, return "". If there are multiple solutions, return any of them.

A string s is lexicographically smaller than a string t if at the first letter where they differ, the letter in s comes before the letter in t in the alien language. If the first min(s.length, t.length) letters are the same, then s is smaller if and only if s.length < t.length.

 

Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:

Input: words = ["z","x"]
Output: "zx"
Example 3:

Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of only lowercase English letters.
*/
class Solution {
public:
    
    /*
    Runtime: 8 ms, faster than 50.03% of C++ online submissions for Alien Dictionary.
Memory Usage: 9.9 MB, less than 38.16% of C++ online submissions for Alien Dictionary.
    */
    //O(N) N the total number of chars in all words
    string alienOrder(vector<string>& words) {
        //value depends on key
        unordered_map<char, unordered_set<char>> dict;
        //generate the dict, which depends on what
        
        //to store uniqueue chars
        unordered_set<char> chars;
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                chars.insert(words[i][j]);
            }
        }
        
        
        for(int i = 1; i < words.size(); i++) {
            string prev = words[i - 1];
            string cur = words[i];
            int idx;
            for(idx = 0; idx < prev.size() && idx < cur.size(); idx++) {
                if(prev[idx] != cur[idx]) {
                    //cur depends on prev
                    //cout<<cur[idx] << " <- "<<prev[idx]<<endl;
                    dict[cur[idx]].insert(prev[idx]);
                    break;
                }
            }
            //if there is input like abcd and abc then it is not valid, return ""
            
            if(idx == cur.size() && prev.size() > cur.size()) return "";
        }
        
        //BFS 
        //maintain a queue with items which has no dependency
        queue<char> q;
        string result = "";
        for(auto ch: chars) {
            if(dict[ch].size() == 0) {
                q.push(ch);
            }
        }
        
        //topological sort O(V+E)
        while(!q.empty()) {
            char ch = q.front();
            q.pop();
            //cout<<ch<<endl;
            result.push_back(ch);
            for(auto & item : dict) { //must take the reference??????????
                if(item.second.find(ch) != item.second.end()) {
                    //cout<<"1Found at "<<item.first<<" Size "<<item.second.size()<<endl;
                    item.second.erase(ch);
                    //cout<<"2Found at "<<item.first<<" Size "<<item.second.size()<<endl;
                    if(item.second.size() == 0) {
                        q.push(item.first);
                    }
                }
            }
        }
        
        if(result.size() == chars.size()) return result;
        else return "";
    }
};