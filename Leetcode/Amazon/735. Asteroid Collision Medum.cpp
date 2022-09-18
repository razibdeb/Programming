/*
735. Asteroid Collision Medium

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/
class Solution {
public:
    /*
    Runtime: 31 ms, faster than 19.30% of C++ online submissions for Asteroid Collision.
Memory Usage: 17.5 MB, less than 85.84% of C++ online submissions for Asteroid Collision.
    */
    /*
    
    The for loop runs exactly n times and pushes at most n elements onto the stack in total.
The while loop must pop an element per iteration, so it can't run more than n times, as per (1).
Since the for loop runs at most n times and the while loop runs at most n times, we have O(2n)=O(n)
You get O(n^2) complexity when the inner loop runs n times for each outer loop iteration. Here the inner loop only runs n times in total over the course of all outer loop iterations.
    */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //instead of thinking all of the items, think from left to right
        //if list is empty and we add one -> no colision 
        //if list top is negative and new one is positive no colision
        //if list top is negative and new one is negative no colision
        //if list top is positive and new one is positive no colision
        //if list top is positive and new one is negative then colision
        //      now if both same -> then both gone
        //      now only the bigger one stays
        
        vector<int> result;
        
        for(int i = 0; i < asteroids.size(); i++) {
            
            while(result.size()!=0 && result.back() > 0 && asteroids[i] < 0 && result.back() < abs(asteroids[i])) {
                result.pop_back();
            }
            
            if(result.size() == 0) result.push_back(asteroids[i]);
            else if(result.back() < 0 && asteroids[i] > 0) result.push_back(asteroids[i]);
            else if(result.back() < 0 && asteroids[i] < 0) result.push_back(asteroids[i]);
            else if(result.back() > 0 && asteroids[i] > 0) result.push_back(asteroids[i]);
            else if(result.back() > 0 && asteroids[i] < 0) {
                if(result.back() == abs(asteroids[i])) {
                    result.pop_back();
                    continue;
                } else if(result.back() > abs(asteroids[i])) {
                    //smaller will explode
                    continue;
                }
            }
        }
        
        return result;
    }
};