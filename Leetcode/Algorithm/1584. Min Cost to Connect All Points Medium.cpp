/*
1584. Min Cost to Connect All Points Medium


You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.

*/
/*
Runtime: 484 ms, faster than 63.23% of C++ online submissions for Min Cost to Connect All Points.
Memory Usage: 58.3 MB, less than 56.69% of C++ online submissions for Min Cost to Connect All Points.
*/
///////////////////////////Kruskal's Algorithm
class Edge {
    public:
        int from;
        int to;
        int d;
        Edge(int f, int t, int _d) {
            from = f;
            to = t; 
            d = _d;
        }
    };

    bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs.d > rhs.d;
    }

class Solution {
public:
    vector<int> root;
    vector<int> rank;
    
    
    int find(int a) {
        if(a == root[a]) {
            return a;
        }
        return root[a] = find(root[a]);
    }
    /*
    Then, we iterate over the allEdgesallEdges array, and for each element, we perform a union-find operation. The amortized time complexity for union-find by rank and path compression is O(\alpha(N))O(α(N)), where \alpha(N)α(N) is Inverse Ackermann Function, which is nearly constant, even for large values of NN.
    */
    bool isCycle(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return true;
        
        if(rank[pa] > rank[pb]) {
            rank[pa] += rank[pb];
            root[pb] = pa;
        } else {
            rank[pb] += rank[pa];
            root[pa] = pb;
        }
        
        return false;
    }
    
    //kruskal algo
    /*
    take one vertex -> get all edges connected to it 0 - 1, 0 - 2, 0 - 3 . . . .
    put them on priority queue, priority queue will have (cost, from, to)
    mark this vertex(from) as visited
    
    keep taking off from PQ -> this will give the shortest edge connected with this vertex
    get the TO from this edge
    if this vertex is visited then skip
    now mark this as visited
    now get all the edges connected to it, from this to others -> others who are not visited yet
    push them to queue
    */
    
    /*
    As a result, it is the same as we keep pushing edges and the total number of elements in the heap would be O(E)O(E), where EE is the number of edges.
    */
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        int edgeCount = 0;
        priority_queue<Edge> pq;
        
        //add zero vertext
        visited[0] = true;
        for(int j = 1; j < n; j++) {
            int distance = abs(points[0][0] - points[j][0]) + abs(points[0][1] - points[j][1]);
            pq.push(Edge(0, j, distance));
        }
        int result = 0;
        while(edgeCount < n - 1 && !pq.empty()) {
            Edge topEdge = pq.top();
            pq.pop();
            
            if(visited[topEdge.to] == true) continue;
            
            //following codes will be V times
            
            visited[topEdge.to] = true;
            result += topEdge.d;
            edgeCount++;
            
            for(int j = 0; j < n; j++) {
                if(visited[j] == true) continue;
                int d = abs(points[topEdge.to][0] - points[j][0]) + 
                    abs(points[topEdge.to][1] - points[j][1]);
                pq.push(Edge(topEdge.to, j, d));
            }
        }
        return result;
    }

    //krushkal algo N^2LogN
    //create all edges
    //push them to priority queue (N^2LogN)
    // take each edge and check if it creates a cycle -> union find -> which is nearly constant time
    // keep taking from priority queue untill we have N - 1 edges
    int minCostConnectPoints1(vector<vector<int>>& points) {
        int n = points.size();
        
        root = vector<int>(n);
        rank = vector<int>(n, 1);
        
        for(int i = 0; i < n; i++) {
            root[i] = i;
        }
        
        auto cmp = [](Edge &lhs, Edge &rhs) {
            return lhs.d > rhs.d;
        };
        
        priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);
        
        //N^2 log N 
        //N*(N-1)/2 times 
        // N = number of points in input
        // in case of complete graph there could be N^2 edges
        // sorting would take N^2log(N^2) = N^2log(N)
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push(Edge(i, j, d));
            }
        }
        
        int edgeCount = 0;
        int result = 0;
        while(edgeCount < n - 1 && !pq.empty()) {
            Edge e = pq.top();
            pq.pop();
            if(isCycle(e.from, e.to) == false) {
                result += e.d;
                edgeCount++;
            }
        }
        return result;
    }
};