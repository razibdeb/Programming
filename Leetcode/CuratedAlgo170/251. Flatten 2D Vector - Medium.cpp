/*
Design an iterator to flatten a 2D vector. It should support the next and hasNext operations.

Implement the Vector2D class:

Vector2D(int[][] vec) initializes the object with the 2D vector vec.
next() returns the next element from the 2D vector and moves the pointer one step forward. You may assume that all the calls to next are valid.
hasNext() returns true if there are still some elements in the vector, and false otherwise.
 

Example 1:

Input
["Vector2D", "next", "next", "next", "hasNext", "hasNext", "next", "hasNext"]
[[[[1, 2], [3], [4]]], [], [], [], [], [], [], []]
Output
[null, 1, 2, 3, true, true, 4, false]

Explanation
Vector2D vector2D = new Vector2D([[1, 2], [3], [4]]);
vector2D.next();    // return 1
vector2D.next();    // return 2
vector2D.next();    // return 3
vector2D.hasNext(); // return True
vector2D.hasNext(); // return True
vector2D.next();    // return 4
vector2D.hasNext(); // return False
 

Constraints:

0 <= vec.length <= 200
0 <= vec[i].length <= 500
-500 <= vec[i][j] <= 500
At most 105 calls will be made to next and hasNext.
 

Follow up: As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/
/*
Runtime: 28 ms, faster than 70.86% of C++ online submissions for Flatten 2D Vector.
Memory Usage: 19.6 MB, less than 54.97% of C++ online submissions for Flatten 2D Vector.



Vector2D(vector<vector<int>>& vec) {
        for(int i = 0; i < vec.size(); i++) {
            for(int j = 0; j < vec[i].size(); j++) {
                data.push_back(vec[i][j]);
            }
        }
    }
    
    int next() {
        return data[offset++];
        
    }
    
    bool hasNext() {
        if(offset >= data.size()) return false;
        else return true;
    }


*/

/*
Runtime: 25 ms, faster than 81.00% of C++ online submissions for Flatten 2D Vector.
Memory Usage: 19.6 MB, less than 39.59% of C++ online submissions for Flatten 2D Vector.

*/
class Vector2D {
public:
    vector<vector<int>> data;
    int row = 0, col = 0;
    Vector2D(vector<vector<int>>& vec) {
        data = vec;
        updatePointer(); //to point to a valid data, in case there are empty vector at beginig
    }
    
    int next() {
        int value = data[row][col++];
        updatePointer();
        return value;
    }
    
    void updatePointer() {
        while(row < data.size() && col == data[row].size()) {
            row++;
            col = 0;
        }
    }
    
    bool hasNext() {
        if(row >= data.size()) return false;
        else return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
