/*
316. Remove Duplicate Letters Medium

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/
class Solution {
public:
    /*
    Runtime: 24 ms, faster than 5.04% of C++ online submissions for Remove Duplicate Letters.
Memory Usage: 9.1 MB, less than 7.68% of C++ online submissions for Remove Duplicate Letters.
    */
    string removeDuplicateLetters(string s) {
        /*
        0 1 2 3 4 5 6 7 
        c b a c d c b a 
        
        a 2 7
        b 1 6
        c 0 3 5
        d 4
        */
        
        /*
        As we iterate over our string, if character i is greater than character i+1 and another occurrence of character i exists later in the string, deleting character i will always lead to the optimal solution. Characters that come later in the string i don't matter in this calculation because i is in a more significant spot. Even if character i+1 isn't the best yet, we can always replace it for a smaller character down the line if possible.
        */
        
        //monotonicly increasing stack
        //pop from stack if
        // 1. top of stack is bigger then current, 
        // AND 2. top char exists in future AND 3. this char does not exists in stack
        // then we will pop it
        //if top is smaller then current char, and current char is not in stack 
        //we push current char
        //
        stack<int> st;
        unordered_map<char, int> charCount;
        //if count of the char is zero, then we won't remove it from stack
        //if we remove it from stack, then it won't be added to result later
        for(int i = 0; i < s.size(); i++) {
            charCount[s[i]]++;
        }
        //map to store if char is already exists in stack
        unordered_map<char, bool> seen;
        for(char a = 0; a <= 'z'; a++) {
            seen[a] = false;
        }
        //bcab
        //we are pushing each char maximum once and maximum pop is one
        // so complexity is O(N)
        for(int i = 0; i < s.size(); i++) {
            //already exitst in stack
            
            // cout<<"  i "<<i<<" "<<s[i]<<endl;
            // if(!st.empty()) {
            //     cout<<"Top: "<<s[st.top()]<<" count "<<charCount[s[st.top()]]<<endl;
            // }
            
            //already exitst in stack
            //"abacb" -> && seen[s[i]] == false
            //without this condition
            // result it will pop all when we will get 2nd a
            // result will be acb, where correct is abc
            
            while(
                !st.empty() && 
                s[st.top()] > s[i] && 
                charCount[s[st.top()]] > 0 &&
                seen[s[i]] == false
            ) {
                //we have to mark it false, otherwise it won't be pushed to stack anymore
                // cout<<"Popping "<<s[st.top()]<<endl;
                seen[s[st.top()]] = false;
                st.pop();
            }
            //push only if this char does not exists in stack
            if(seen[s[i]] == false) {
                // cout<<"Adding "<<s[i]<<endl;
                // if(!st.empty())
                //      cout<<"Top "<<s[st.top()]<<endl;
                st.push(i);
                seen[s[i]] = true;
            }
            //we have to reduce the count, once we processed the character
            //"bbcaac"
            charCount[s[i]]--;
        }
        
        string result = "";
        //cout<<"Size "<<st.size()<<endl;
        while(!st.empty()) {
            result = s[st.top()] + result;
            st.pop();
        }
        return result;
    }
};