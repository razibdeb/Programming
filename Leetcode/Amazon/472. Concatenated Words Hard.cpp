/*
472. Concatenated Words Hard

Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

 

Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
 

Constraints:

1 <= words.length <= 104
1 <= words[i].length <= 30
words[i] consists of only lowercase English letters.
All the strings of words are unique.
1 <= sum(words[i].length) <= 105
*/
/*

Runtime: 171 ms, faster than 97.31% of C++ online submissions for Concatenated Words.
Memory Usage: 40.2 MB, less than 87.63% of C++ online submissions for Concatenated Words.
*/

class Solution {
public:
    unordered_set<string> data;
    unordered_set<string> found;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        int smallestSize = INT_MAX;
        for(int i = 0; i < words.size(); i++) {
            data.insert(words[i]);
            smallestSize = min(smallestSize, (int)words[i].size());
        }
        for(int i = 0; i < words.size(); i++) {
            search(words[i], 0, 0);
        }
        return vector<string>(found.begin(), found.end());
    }
    
    void search(string word, int index, int totalFound) {
        if(index == word.size()) {
            if(totalFound >= 2) found.insert(word);
            return;
        }
        if(found.find(word) != found.end()) return;
        
        string temp = "";
        int count = 0;
        for(int i = index; i < word.size(); i++) {
            temp.push_back(word[i]);
            if(data.find(temp) != data.end()) {
                search(word, i + 1, totalFound + 1 );
            }
        }
    }
};