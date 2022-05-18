/*
You are given an even number of people numPeople that stand around a circle and each person shakes hands with someone else so that there are numPeople / 2 handshakes total.

Return the number of ways these handshakes could occur such that none of the handshakes cross.

Since the answer could be very large, return it modulo 109 + 7.

 

Example 1:


Input: numPeople = 4
Output: 2
Explanation: There are two ways to do it, the first way is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].
Example 2:


Input: numPeople = 6
Output: 5
 

Constraints:

2 <= numPeople <= 1000
numPeople is even.

Amazon
*/

/*
Runtime: 112 ms, faster than 14.08% of C++ online submissions for Handshakes That Don't Cross.
Memory Usage: 6 MB, less than 88.15% of C++ online submissions for Handshakes That Don't Cross.
*/

class Solution {
public:
    /*
    approach:
    
    1. have to choose the other person in such a way that, left side & right side have valid persons-> even number of persons
    2. after choosing whole input is devided into two sub problem
    3. result will be leftSide X right side
    4. base case if only two person then we can do this only 1 way
    5. we have to choose next person loop to 1 again
    */
    
    int dp[1001] = {0};
    
    long M = 1e9 + 7; //this has to be long, if it is int then error
    
    int numberOfWays(int numPeople) {
        if(numPeople <= 2) return 1;
        if(dp[numPeople] != 0) return dp[numPeople];
        long sum = 0;
        for(int i = 2; i <= numPeople; i+=2) {
            sum += ((numberOfWays(i - 2) % M) * (numberOfWays(numPeople - i) % M) ) % M;
            sum = sum % M;
        }
        //cout<<"For "<<numPeople<<" "<<sum<<endl;
        dp[numPeople] = sum;
        return sum;
    }
};
