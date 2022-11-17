/*
1192. Critical Connections in a Network Hard


There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/
/*
https://www.youtube.com/watch?v=Rhxs4k6DyMM&t=876s
targan's algorithm
*/
class Solution {
public:
    vector<int> discoveryTime, low, parent;
    int time;
    unordered_map<int, vector<int> > adj;
    vector<vector<int>> result;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        discoveryTime = vector<int>(n, -1);
        low = vector<int>(n, -1);
        parent = vector<int>(n, -1);
        time = 0;
        
        for(int i = 0; i < connections.size(); i++) {
            int from = connections[i][0];
            int to = connections[i][1];
            adj[from].push_back(to);
            adj[to].push_back(from); //MUST add both edge
        }

        for(int i = 0; i < n; i++) {
            if(discoveryTime[i] == -1) { //not visited yet
                visit(i);
            }
        }

        return result;
    }
    
    void visit(int node) {
        
        //update it's discovery time 
        //update low to time
        //increase time

        
        discoveryTime[node] = time; //the time when it was discovered
        low[node] = time; //low means node with lowest discovery time accessible from current node
        time++;
        
        //visit all it's neighbours
            // do not visit parent
            //if already visited
                // that means it was one of it's parents
                // update current's node's low to min of low & discovery of node which we are checking
            //if not visited
                //visit it
                //update current's low to min of current low & just visited low
        
            //when visit complete one item
                //update it's low to min of visited one
                //if visited's low time is bigger then it's discovery time then it's a bridge
                //if visted items' low time is bigger that menas it was not possible to visit any of it's parents, 
                // no back edge
        
        for(int i = 0; i < adj[node].size(); i++) {
            int nextNode = adj[node][i];
            if(nextNode  == parent[node]) continue;

            if(discoveryTime[nextNode] != -1) {
                low[node] = min(low[node], discoveryTime[nextNode]);
            } else { //not visited
                parent[nextNode] = node;
                visit(nextNode);
                if(low[nextNode] > discoveryTime[node]) { //it was not possible to visit any of it's parents, no bridge
                    result.push_back({node, nextNode});
                } else {
                    low[node] = min(low[node], low[nextNode]); 
                    //as nextNode accessible from this node, 
                    //other node which was accessible from nextNode will also be accessible from cur node
                }
            }
        }
    }
};