/*
207. Course Schedule Medium

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

class Solution {
public:
    
    /*
    Runtime: 607 ms, faster than 5.04% of C++ online submissions for Course Schedule.
Memory Usage: 17.1 MB, less than 6.08% of C++ online submissions for Course Schedule.
    */
    
    //O(V + E) v = number of courses, E = number of dependencies
    // 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> adj; //adj[z] = z depends on list
        
        //how many depends on this item
        vector<int> dependCount(numCourses, 0);
        
        //O(E) to build adj
        for(int i = 0; i < prerequisites.size(); i++) {
            vector<int> item = prerequisites[i];
            int a = item[0];
            int b = item[1]; 
            //a depends on b
            adj[a].insert(b);
        }
        //next O(V + E)
        //we will visit each vertex & edge only once
        
        queue<int> q; //hold the items who doesn't depens on anyone
        for(int i = 0; i < numCourses; i++) {
            if(adj[i].size() == 0) { //it doesn't depend on anyone
                q.push(i);
            }
        }
        
        int courseCompleted = 0;
        while(!q.empty()) {
            int course = q.front(); // no one depends on ths course
            q.pop();
            courseCompleted++;
            
            for(int i = 0; i < numCourses; i++) {
                if(adj[i].find(course) != adj[i].end()) {
                    adj[i].erase(course);
                    if(adj[i].size() == 0) {
                        q.push(i);
                    }
                }
            }
        }
        if(courseCompleted == numCourses) return true;
        else return false;
        
    }
};

/* another solution with cycle detection

    bool notPossible;
    
    bool isCyclic(int course, vector<bool>& mark, vector<vector<int>>& adjlist, vector<bool>& isVisited) {
        if(mark[course]) return true;
        
        int len = adjlist[course].size();
        if(len == 0) return false;
        
        mark[course] = true;
        
        bool isFoundCycle = false;
        for(int i=0 ; i<len ; i++ ) {
            if(!isVisited[adjlist[course][i]]) isFoundCycle = isCyclic(adjlist[course][i], mark, adjlist, isVisited);
            if(isFoundCycle) break;
            isVisited[adjlist[course][i]] = true;
        }
        
        mark[course] = false;
        return isFoundCycle;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        map<int, int> mp;
        mp.clear();
        
        int prereqLen = prerequisites.size();
        for(int i=0 ; i<prereqLen ; i++) {
            adjlist[prerequisites[i][1]].push_back(prerequisites[i][0]);
            mp[prerequisites[i][1]]++;
            mp[prerequisites[i][0]]++;
        }
        
        vector<bool> mark(numCourses, false);
        vector<bool> isVisited(numCourses, false);
        
        for(int i=0 ; i<numCourses ; i++ ) {
            if(mp[i] && !isVisited[i] && isCyclic(i, mark, adjlist, isVisited)){
                return false;
            }
            isVisited[i] = true;
        }
        
        return true;
    }
*/