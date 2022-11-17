/*
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

/*
Runtime: 3 ms, faster than 92.81% of C++ online submissions for Alien Dictionary.
Memory Usage: 9.8 MB, less than 40.40% of C++ online submissions for Alien Dictionary.
*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        unordered_set<char> uniqueChars;
        
        for(auto w: words) {
            for(auto ch: w) {
                uniqueChars.insert(ch);
            }
        }
        
        for(int i = 0; i + 1 < words.size(); i++) {
            string prev = words[i];
            string cur = words[i+1];
            int len = 0;
            for(; len < prev.size() && len < cur.size(); len++) {
                if(prev[len] == cur[len]) continue;
                else {
                    //cout<<prev[len]<<" -> "<<cur[len]<<endl;
                    adj[cur[len]].push_back(prev[len]);
                    indegree[prev[len]]++;
                    break;
                }
            }
            
            if(len == cur.size() && len < prev.size()) return ""; //abcd abc            
        }
        queue<char> q;
        for(auto item: uniqueChars) { 
            if(indegree[item] == 0) q.push(item);
        }
        
        string result = "";
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                char front = q.front();
                q.pop();
                //cout<<front<<endl;
                result.push_back(front);
                
                for(int i = 0; i < adj[front].size(); i++) {
                    char to = adj[front][i];
                    indegree[to]--;
                    if(indegree[to] == 0) {
                        q.push(to);
                    }
                }
            }
        }
        reverse(result.begin(), result.end());
        if(result.size() == indegree.size()) return result;
        else return "";
        
    }
};