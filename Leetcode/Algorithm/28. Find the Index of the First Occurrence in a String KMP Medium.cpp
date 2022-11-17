/*

28. Find the Index of the First Occurrence in a String Medium

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/
class Solution {
public:
    /*
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Index of the First Occurrence in a String.
Memory Usage: 6.4 MB, less than 9.10% of C++ online submissions for Find the Index of the First Occurrence in a String.
    */
    int strStr(string haystack, string needle) {
        vector<int> table(needle.size(), 0);
        
        /*
        
        table will hold the at index i 
        value = longes prefix which is also a suffix
        
        a b c a b y
        0 0 0 1 2 0
        
        matching:
        
        if match increase both character INPUT Pattern-> P
        if not
            loop untill p > 0 &&  table[p-1] != input[i]
                p = table[p-1]
            
            finally if now match with pattern input[i] == pattern[p] then incrase both poiinter
            else only increase i pointer and p will autmatically set to zero
            
        */
        
        int i = 0, j = 1;
        while(j < needle.size()) {
            if(needle[i] == needle[j]) {
                table[j] = i + 1;
                i++;
                j++;
            } else {
                while(i > 0 && needle[j] != needle[i]) {
                    i = table[i - 1];
                }
                if(needle[j] == needle[i]) {
                    table[j] = i + 1;
                    i++;
                }
                j++;
            }
        }
        /*
        for(int a = 0; a < needle.size(); a++) {
            cout<<table[a]<<" ";
        }
        cout<<endl;
        vector<int> lps(needle.size(),0);
        for(int i=1;i<needle.size();i++){
            int j=lps[i-1];
            while(j>0 && needle[i]!=needle[j]){
                j=lps[j-1];
            }
            if(needle[i]==needle[j]){
                j++;
            }
            lps[i]=j;
        }
        for(int a = 0; a < needle.size(); a++) {
            cout<<lps[a]<<" ";
        }
        cout<<endl;
        
        */
        int a = 0, b = 0;
        while(b < haystack.size()) {
            if(haystack[b] == needle[a]) {
                a++;
                b++;
            } else {
                if(a != 0) {
                    a = table[a - 1];
                } else {
                    b++;
                }
            }
            if(a == needle.size()) {
                    return b - a;
            }
        }
        return -1;
    }
};

/*

"mississippi"
"issip"

"aabaaabaaac"
"aabaaac"


"ababcaababcaabc"
"ababcaabc"

*/