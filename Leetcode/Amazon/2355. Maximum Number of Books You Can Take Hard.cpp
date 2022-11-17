/*

2355. Maximum Number of Books You Can Take Hard

You are given a 0-indexed integer array books of length n where books[i] denotes the number of books on the ith shelf of a bookshelf.

You are going to take books from a contiguous section of the bookshelf spanning from l to r where 0 <= l <= r < n. For each index i in the range l <= i < r, you must take strictly fewer books from shelf i than shelf i + 1.

Return the maximum number of books you can take from the bookshelf.

 

Example 1:

Input: books = [8,5,2,7,9]
Output: 19
Explanation:
- Take 1 book from shelf 1.
- Take 2 books from shelf 2.
- Take 7 books from shelf 3.
- Take 9 books from shelf 4.
You have taken 19 books, so return 19.
It can be proven that 19 is the maximum number of books you can take.

Example 2:

Input: books = [7,0,3,4,5]
Output: 12
Explanation:
- Take 3 books from shelf 2.
- Take 4 books from shelf 3.
- Take 5 books from shelf 4.
You have taken 12 books so return 12.
It can be proven that 12 is the maximum number of books you can take.

Example 3:

Input: books = [8,2,3,7,3,4,0,1,4,3]
Output: 13
Explanation:
- Take 1 book from shelf 0.
- Take 2 books from shelf 1.
- Take 3 books from shelf 2.
- Take 7 books from shelf 3.
You have taken 13 books so return 13.
It can be proven that 13 is the maximum number of books you can take.

 

Constraints:

    1 <= books.length <= 105
    0 <= books[i] <= 105



*/

class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        /*
        
        if we want to get the maximum result then, for our result, last item, we have to take 
        all of the books
        lets say from l to r, we will take all books of books[r], then 
        books[r-1] - 1
        books[r-2] - 2 and so on, 
        if books[r-1] is less then books[r-1] - 1, then we will take all of  books from that index

        here we can think that we are solving same problem DP

        so let's say for index i, we took all the books
        now if i-1 has books which is less then books[i] - 1, then we can't take it
        we need to find next smaller index where we can take all of the books of that index

        in middle, even though there are more books we won't be able to take them,

        if we take all the books of j index, then we can get that result dp[j]
        and for middle we can get the sum of middle items

        (first value + secondValue) * n / 2
        last value = books[i]
        first value = books[i] - (i -j )
        n = (i - j) + 1
        
        i = 7
        j = 5
        3 4 5

        to get previous smaller index, we can use monotonic stack

        stack will contain the next min index
        if cur item > st top then push
        if curItem < st.top, pop untill st empty

        instead of just smaller we have to calculate the diff
        smaller means (item - diff) 

        0 1 2 3 4
        8 2 4 5 6
        at index 4, our previous minimum/ st.top item will be index 1, item 2
        at index 1 it should be 6 - (4 - 1) = 3
        B = item - (it's index - smaller items' index)
        so result will be  sum of 
            1. DP[smalleritem index] -> because will calculate taking all of it's books
            2. sum with 6 - sum of the item it should be(B)
        */

        int n = books.size();

        stack<int> st; //stack of index, bigger push

        vector<long long> dp(n, 0);
        long long maxBooks = 0;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && books[st.top()] > books[i] - (i - st.top()))
                st.pop();

            if(st.empty()) {
                if(books[i] >= i+1) {
                    long long beforeItem = books[i] - i - 1;
                    //Line 67: Char 38: runtime error: signed integer overflow: 100000 * 100001 cannot be represented in type 'int'
                    long long curItem = books[i];
                    dp[i] = curItem * (curItem + 1) / 2 - beforeItem * (beforeItem + 1) / 2;
                } else {
                    //runtime error: signed integer overflow: 50000 * 50001 cannot be represented in type 'int' (solution.cpp)
                    long long curItem = books[i];
                    dp[i] = curItem * (curItem + 1) / 2;
                }   
                
            } else {
                long long beforeItem = books[i] - (i - st.top() );
                dp[i] = dp[st.top()];
                long long curItem = books[i];
                long long curSum = curItem * (curItem + 1) / 2 - beforeItem * (beforeItem + 1) / 2;
                dp[i] = dp[st.top()] + curSum;
            }
            maxBooks = max(maxBooks, dp[i]);
            st.push(i);
        }
        return maxBooks;
    }
};