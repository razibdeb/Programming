/*
359. Logger Rate Limiter
Easy

1232

162

Add to List

Share
Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:

Logger() Initializes the logger object.
bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.
 

Example 1:

Input
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output
[null, true, true, false, false, false, true]

Explanation
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
 

Constraints:

0 <= timestamp <= 109
Every timestamp will be passed in non-decreasing order (chronological order).
1 <= message.length <= 30
At most 10^4 calls will be made to shouldPrintMessage.


Google|19
Atlassian|13
Microsoft|4
Netflix|3
Apple|2
Amazon|2

*/


/*
Runtime: 93 ms, faster than 57.98% of C++ online submissions for Logger Rate Limiter.
Memory Usage: 34.8 MB, less than 12.22% of C++ online submissions for Logger Rate Limiter.

*/

class Node {
    public:
    Node * next;
    int time;
    string msg;
    Node * prev;
    
    Node(int t, string m) {
        time = t;
        next = nullptr;
        prev = nullptr;
        msg = m;
    }
};

class Logger {
public:
    Node * head, *tail;
    unordered_map<string, Node *> data;
    
    Logger() {
        head = nullptr;
        tail = nullptr;
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        //cout<<"checking "<<message<<endl;
        if(head == nullptr) {
            head = new Node(timestamp, message);
            tail = head; 
            data[message] = head;
            return true;
        }
        
        if(data.find(message) != data.end()) {
            if( abs(data[message]->time - timestamp) < 10) {
                //cout<<" node "<<data[message]->time<<" t: "<<timestamp<<endl;
                return false;
            } else {
                Node *n = data[message];
                n->time = timestamp;
                
                if(n != tail) {
                    if(n == head) {
                        head = head->next;
                        head->prev = nullptr;
                    }
                    
                    tail->next = n;
                    n->prev = tail;
                    tail = n;
                }
            }
        } else {
            Node * t = new Node(timestamp, message);
            tail->next = t;
            t->prev = tail;
            tail = t;
            data[message] = t;
        }
        
        
        while(head->next != nullptr && abs(head->time - timestamp) > 10) {
            Node *t = head;
            
            data.erase(t->msg);
            head = head->next;
            delete t;
        }
        
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */