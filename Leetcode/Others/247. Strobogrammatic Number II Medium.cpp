/*
247. Strobogrammatic Number II Medium

Given an integer n, return all the strobogrammatic numbers that are of length n. You may return the answer in any order.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

 

Example 1:

Input: n = 2
Output: ["11","69","88","96"]
Example 2:

Input: n = 1
Output: ["0","1","8"]
 

Constraints:

1 <= n <= 14
*/
class Solution {
public:
    /*
    Runtime: 109 ms, faster than 15.97% of C++ online submissions for Strobogrammatic Number II.
Memory Usage: 35.2 MB, less than 29.98% of C++ online submissions for Strobogrammatic Number II.
    */
    
    //O(N*5^(N/2 - 1))
    //as N, from 1 to N, we will add 2 items, so N/2 levels
    // each level we add 5 items
    
    vector<string> findStrobogrammatic(int n) {
        /*
        we have fixed pairs
        00 11 69 88 96
        if n is even that means left & right is same, we keep adding one by one untill we reach n
        like 
        00 -> 1001 -> 610019
        11 -> 1111 -> 611119
        
        if odd then we add 0 1 8 at middle then keep adding pairs on both side
        
        0 -> 000 -> 10001 -> 6100019
        similarly for 1 & 9
        
        we will maintain a q, update the q items
        
        we have to keep in mind that at begining we can't put 0
        
        */
        
        vector<pair<string, string>> pairList;
        pairList.push_back(make_pair("0", "0"));
        pairList.push_back(make_pair("1", "1"));
        pairList.push_back(make_pair("6", "9"));
        pairList.push_back(make_pair("8", "8"));
        pairList.push_back(make_pair("9", "6"));
        
        queue<string> q;
        int len;
        
        if(n%2 == 0) {
            len = 0;
            q.push(""); //we need this
        } else {
            q.push("0");
            q.push("1");
            q.push("8");
            len = 1;
        }
        
        while(len < n) {
            len += 2;
            
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                string str = q.front();
                q.pop();
                
                for(auto pr: pairList) {
                    if(len != n || pr.first != "0") {
                        q.push(pr.first + str + pr.second);
                    }
                }
                
            }
            
        }
        
        vector<string> result;
        while(!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        
        return result;
    }
};

/*
0 0
1 1
6 9
8 8
9 6     
*/