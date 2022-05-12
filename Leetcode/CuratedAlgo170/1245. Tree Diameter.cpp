/*
The diameter of a tree is the number of edges in the longest path in that tree.

There is an undirected tree of n nodes labeled from 0 to n - 1. You are given a 2D array edges where edges.length == n - 1 and edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the tree.

Return the diameter of the tree.

 

Example 1:


Input: edges = [[0,1],[0,2]]
Output: 2
Explanation: The longest path of the tree is the path 1 - 0 - 2.
Example 2:


Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation: The longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
 

Constraints:

n == edges.length + 1
1 <= n <= 104
0 <= ai, bi < n
ai != bi
*/

class Solution {
public:
    int n;
    int treeDiameter(vector<vector<int>>& edges) {
        n = edges.size();
        
        if(n == 0) return 0;
        
        unordered_map<int, unordered_set<int>> adjList;
        for(int i = 0; i < edges.size(); i++) {
            auto edge = edges[i];
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }
        /*
        Topological sorting
        Runtime: 106 ms, faster than 28.23% of C++ online submissions for Tree Diameter.
Memory Usage: 32.1 MB, less than 10.20% of C++ online submissions for Tree Diameter.

        */
        
        queue<int> q;
        int unProcessed = n+1;
        
        for(int i = 0; i < unProcessed; i++) {
            if(adjList[i].size() == 1) {
                q.push(i);
            }
        }

        int layer = 0;
        
        while(unProcessed > 2) {
            int size = q.size();
            unProcessed -= size;
            for(int i = 0; i < size; i++) {
                int leaf = q.front();
                q.pop();
                
                int neighbour = *begin(adjList[leaf]);//only 1 connected
                
                adjList[neighbour].erase(leaf);
                
                if(adjList[neighbour].size() == 1) q.push(neighbour);
            }
            layer++;
        }
        
        if(unProcessed == 1) {
            return layer*2;
        } else {
            return layer*2+1;
        }
        
        //BFS
        // int distance;
        // int furthestNode = bfs(adjList, 0, distance);
        // bfs(adjList, furthestNode, distance);
        // return distance;
    }
    
    /*
    Topological sort:
    
    find the leaf nodes -> push them to Q
    loop untill unprocessed leaf is bigger then 2 -> if there are even node then 2 will be left 
        get the size of Q
        take leaf node 
        remove it from it's neighbour
        if neighbour becomes leaf push it to Q
    */
    
    
    //return furthest node with distance
    int bfs(unordered_map<int, unordered_set<int>> &adjList, int node, int &distance) {
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(node);
        distance = -1;
        int curNode;
        
        while(!q.empty()) {
            
            int size = q.size();

            for(int i = 0; i < size; i++) {
                curNode = q.front();
                q.pop();
                
                //if(visited[curNode] == true) continue;
                
                visited[curNode] = true;
                
                for(auto it: adjList[curNode]) {
                    if(visited[it] == false) {
                        q.push(it);
                    }
                }
                
            }
            distance++;
        }
        return curNode;
    }
};