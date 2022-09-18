/*
341. Flatten Nested List Iterator Medium

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the NestedIterator class:

NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
int next() Returns the next integer in the nested list.
boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.
Your code will be tested with the following pseudocode:

initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
If res matches the expected flattened list, then your code will be judged as correct.

 

Example 1:

Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 

Constraints:

1 <= nestedList.length <= 500
The values of the integers in the nested list is in the range [-106, 106].
*/


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*
Runtime: 30 ms, faster than 29.14% of C++ online submissions for Flatten Nested List Iterator.
Memory Usage: 14.2 MB, less than 39.10% of C++ online submissions for Flatten Nested List Iterator.
*/
class NestedIterator {
public:

    stack<NestedInteger> st;
    
    void addToStack(vector<NestedInteger> & list) {
        for(int i = list.size() - 1; i >= 0; i--) 
            st.push(list[i]);
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        addToStack(nestedList);
    }
    
   
    
    int next() {
        NestedInteger top = st.top();
        st.pop();
        return top.getInteger();
    }
    
    bool hasNext() {
        while(!st.empty()) {
            NestedInteger ni = st.top();
            if(ni.isInteger() == true) {
                return true;
            }
            st.pop();
            addToStack(ni.getList());
        }
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */