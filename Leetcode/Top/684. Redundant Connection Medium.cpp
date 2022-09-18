/*

684. Redundant Connection Medium


In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
*/
class Solution {
public:
    int n;
    
    //by default it is it's own parent
    vector<int> parent;
    //how many under this item
    vector<int> rank;
    /*
    Runtime: 8 ms, faster than 82.23% of C++ online submissions for Redundant Connection.
Memory Usage: 8.9 MB, less than 70.02% of C++ online submissions for Redundant Connection.
    */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size()+1;
        parent = vector<int> (n+1);
        rank = vector<int> (n+1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1; 
        }
        
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            if(isCycle(a, b) == true) return {a, b};
        }
        return {};
    }
    
    int findParent(int a) {
        int p = a;
        //find the actual parent
        //this can go at most height of the tree, 
        // but this will go once, because next step we are compressing the path
        while(parent[p] != p) p = parent[p];
        
        //we do not need to compress if p == a
        if(p == a) return a;
        
        //compress the path
        while(parent[a] != p) {
            int tempParent = parent[a];
            parent[a] = p;
            a = tempParent;
            rank[p]++; //increase the rank
        }
        return p;
    }
    //kind of union
    bool isCycle(int a, int b) {
        int parentA = findParent(a);
        int parentB = findParent(b);
        if(parentA == parentB) return true;
        
        if(rank[parentA] >= rank[parentB]) {
            parent[parentB] = parentA;
            rank[parentA]++;
        } else {
            parent[parentA] = parentB;
            rank[parentB]++;
        }
        return false;
    }
        
};