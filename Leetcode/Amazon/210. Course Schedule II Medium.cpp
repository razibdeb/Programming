/*
210. Course Schedule II Medium

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/
class Solution {
public:

    /*
    Runtime: 27 ms, faster than 76.73% of C++ online submissions for Course Schedule II.
Memory Usage: 13.9 MB, less than 59.42% of C++ online submissions for Course Schedule II.
    */
    //O(V+E) 
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        
        int n = prerequisites.size();
        
        unordered_map<int, vector<int>> courses; //course[0] = {} other depens on 0
        
        vector<int> inDegree(numCourses, 0); //how many course depends on this item
        for(int i = 0; i < n; i++) {
            int courseA = prerequisites[i][0];
            int courseB = prerequisites[i][1]; 
            //A depends on  B
            courses[courseB].push_back(courseA);
            inDegree[courseA]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        //each vertex will be pushed to queue once
        //inside for loop will run for the number of edges, 
        // but single edge will run only one
        //so V + E
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            
            result.push_back(course);
            
            for(int i = 0; i < courses[course].size(); i++) {
                int dependent = courses[course][i];
                inDegree[dependent]--;
                if(inDegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }
        if(result.size() == numCourses) return result;
        else return {};
    }
};