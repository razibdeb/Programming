/*
49. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/
class Solution {
public:
    
    /*
    Runtime: 64 ms, faster than 39.02% of C++ online submissions for Group Anagrams.
Memory Usage: 24.9 MB, less than 12.63% of C++ online submissions for Group Anagrams.
    */
    
    //O(NL) N = number of strings, L = maximum length of a string
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> dict;
        
        for(int i = 0; i < strs.size(); i++) {
            vector<char> original(26, 0);
            string ss = strs[i];
            string key = getHash(ss);
            dict[key].push_back(ss);
        }
        
        vector<vector<string>> result;
        for(auto it: dict) {
            result.push_back(it.second);
        }
        return result;
    }
    //O(L)  L = maximum length of strings 
    string getHash(string input) {
        //in case there are more then english characters
        //make hash with #2 => 2 a 
        string result = "00000000000000000000000000";
        
        for(int i = 0; i < input.size(); i++) {
            char ch = input[i];
            
            result[ch-'a']++;
        }
        //cout<<input<<endl<<result<<endl;
        return result;
    }
};