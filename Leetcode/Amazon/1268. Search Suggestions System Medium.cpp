/*
1268. Search Suggestions System Medium

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 

Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
*/
class Trie {
public:
    bool isWord;
    Trie * next[26];
    Trie() {
        isWord = false;
        for(int i = 0; i < 26;i++) next[i] = nullptr;
    }
};

void insert(Trie * root, string word) {
    for(int i = 0; i < word.size(); i++) {
        int next = word[i] - 'a';
        if(root->next[next] == nullptr) {
            root->next[next] = new Trie();
        }
        root = root->next[next];
    }
    root->isWord = true;
}

class Solution {
public:
    
    /*
    
    Runtime: 1521 ms, faster than 7.14% of C++ online submissions for Search Suggestions System.
Memory Usage: 658.8 MB, less than 5.00% of C++ online submissions for Search Suggestions System.
    
    Runtime: 2077 ms, faster than 5.01% of C++ online submissions for Search Suggestions System.
Memory Usage: 658.9 MB, less than 5.00% of C++ online submissions for Search Suggestions System.
    */
    Trie * trie = nullptr;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        trie = new Trie();
        
        //O(N) number of total characters
        for(int i = 0; i < products.size(); i++) {
            string word = products[i];
            insert(trie, word);
        }
        
        
        /*
        ["havana"]
        "tatiana"
        
        output should be [[],[],[],[],[],[],[]]
        */
        vector<vector<string>> result(searchWord.size());
        
        string prefix = "";
        
        for(int i = 0; i < searchWord.size(); i++) {
            prefix.push_back(searchWord[i]);
            char next = searchWord[i] - 'a';
            if(trie->next[next] != nullptr) {
                trie = trie->next[next];
            }
            else {
                break;
            }
            vector<string>resultSingle;
            DFS(trie, prefix, resultSingle);

            result[i] = resultSingle;

        }
        
        return result;
    }
    
    void DFS(Trie * node, string prefix, vector<string> &result) {
        if(result.size() == 3) return;
        if(node->isWord == true) {
            result.push_back(prefix);
        }

        for(int i = 0; i < 26; i++) {
            if(node->next[i] != nullptr) {
                char ch = i + 'a';
                DFS(node->next[i], prefix + ch, result);
            }
        }
    }
};