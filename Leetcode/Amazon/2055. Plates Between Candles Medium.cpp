/*
2055. Plates Between Candles Medium

There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.

You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.

 

Example 1:

ex-1
Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]
Explanation:
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.
Example 2:

ex-2
Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
Output: [9,0,0,0,0]
Explanation:
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.
 

Constraints:

3 <= s.length <= 105
s consists of '*' and '|' characters.
1 <= queries.length <= 105
queries[i].length == 2
0 <= lefti <= righti < s.length
*/

class Solution {
public:
    /*
    Runtime: 721 ms, faster than 48.90% of C++ online submissions for Plates Between Candles.
Memory Usage: 160.4 MB, less than 13.90% of C++ online submissions for Plates Between Candles.
    */
    //O(N+M) n = string length M = queries length
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        /*
        approach:
        we can try each time for each query but that won't be efficiant
        we need to somehow store the plates 
        we can store number of plates so far in an array -> plates 
        
        now for each index, if we can have immidiate left candle, & right candle
        then from previous plates array we can find plates between this two candle's index
        
        lefCandle -> 
        from 0 to end
        if it is candle then save it
        if not then get the last index
        
        for first time, index should be -1 if it is not a candle
        
        */
        int n = s.size();
        vector<int> platesSum(n, 0);
        
        if(s[0] == '*') platesSum[0] = 1; 
        else platesSum[0] = 0;
        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '*') platesSum[i] = platesSum[i-1] + 1;
            else platesSum[i] = platesSum[i-1];
        }
        
        vector<int> leftCandleIndex(n, -1);
        if(s[0] == '|') leftCandleIndex[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '|') leftCandleIndex[i] = i;
            else leftCandleIndex[i] = leftCandleIndex[i-1];
        }
        
        vector<int> rightCandleIndex(n, -1);
        if(s[n-1] == '|') rightCandleIndex[n-1] = 0;
        for(int i = n-2; i >= 0; i--) {
            if(s[i] == '|') rightCandleIndex[i] = i;
            else rightCandleIndex[i] = rightCandleIndex[i+1];
        }
        vector<int> answer(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++) {
            auto q = queries[i];
            int left = q[0];
            int right = q[1];
            if(left < 0 || right >= n) continue;
            
            int rightMostCandleOfLeft = rightCandleIndex[left];
            int leftMostCandleOfRight = leftCandleIndex[right];
            
            
            // rightMostCandleOfLeft < leftMostCandleOfRight is important
            //because lets say query is 4 5 
            //but we got 8 & 2 
            //thats not proper
            if(rightMostCandleOfLeft != -1 && leftMostCandleOfRight != -1 && rightMostCandleOfLeft < leftMostCandleOfRight) {
                answer[i] = platesSum[leftMostCandleOfRight] - platesSum[rightMostCandleOfLeft];
            }
            
        }
        return answer;
    }
};