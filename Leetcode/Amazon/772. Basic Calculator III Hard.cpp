/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1+1"
Output: 2
Example 2:

Input: s = "6-4/2"
Output: 4
Example 3:

Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21
 

Constraints:

1 <= s <= 104
s consists of digits, '+', '-', '*', '/', '(', and ')'.
s is a valid expression.
*/


/*
Runtime: 6 ms, faster than 60.36% of C++ online submissions for Basic Calculator III.
Memory Usage: 7.8 MB, less than 47.35% of C++ online submissions for Basic Calculator III.
*/

class Item {
public:
    bool isOperator;
    int value;
    char op;
    Item(char ch) {
        isOperator = true;
        op = ch;
    }
    Item(int v) {
        value = v;
        isOperator = false;
    }
};
class Solution {
public:
    int calculate(string s) {
        vector<Item> postFix = infixToPostfix(s);
        
        return evaluate(postFix);
    }
    
    int evaluate(vector<Item> postfix) {
        stack<Item> st;
        int result = 0;

        for(Item it: postfix) {
            if(it.isOperator == false) {
                st.push(it);
            } else {
                
                int b = st.top().value;
                st.pop();
                int a = st.top().value;
                st.pop();
                
                
                switch(it.op){   
                case '+':
                    st.push(Item(a + b));
                    break;
                case '-': 
                     st.push(Item(a - b)); 
                    break;
                case '*':
                    st.push(Item(a * b));
                    break;
                case '/':
                    st.push(Item(a / b));
                    break;
                }
            }
        }
        return st.top().value;
    }
    int getPreference(Item item) {
        return getPreference(item.op);
    }
    int getPreference(char ch) {
        if(ch == '+' || ch == '-' ) {
            return 1;
        } else if(ch == '*' || ch == '/') {
            return 2;
        }
        return 0;
    }
    vector<Item> infixToPostfix(string s) {
        vector<Item> result;
        string digitStr = "";
        stack<Item> st;
        
        for(char ch: s) {
            if(isdigit(ch)) {
                digitStr.push_back(ch);
            } else if(ch == '(') {
                if(digitStr.size() > 0) {
                    int value = stoi(digitStr);
                    result.push_back(Item(value));
                    digitStr = "";
                }
                st.push(Item(ch));
            } else if(ch == ')') {
                 if(digitStr.size() > 0) {
                    int value = stoi(digitStr);
                    result.push_back(Item(value));
                    digitStr = "";
                }
                
                while(!st.empty()) {
                    Item top = st.top();
                    if(top.isOperator == true && top.op == '(')
                        break;
                    st.pop();
                    result.push_back(top);
                }
                st.pop();
            } else {
                if(digitStr.size() > 0) {
                    int value = stoi(digitStr);
                    result.push_back(Item(value));
                    digitStr = "";
                }
                int pref = getPreference(ch);
                
                while(!st.empty() && getPreference(st.top()) >= pref ) {
                    
                    Item top = st.top();
                    result.push_back(top);
                    st.pop();
                }
                st.push(Item(ch));
            }
        }
        if(digitStr.size() > 0) {
            int value = stoi(digitStr);
            result.push_back(Item(value));
            digitStr = "";
        }
            
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        /*
        for(int i = 0; i < result.size(); i++) {
            Item it = result[i];
            if(it.isOperator) {
                cout<<it.op;
            } else {
                cout<<it.value;
            }
            //cout<<(it.isOperator ? it.op : it.value) <<endl;            
        }*/
        //cout<<endl<<"----"<<endl;
        return result;
    }
};