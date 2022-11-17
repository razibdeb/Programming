/*
332. Reconstruct Itinerary Hard 

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

 

Example 1:


Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:


Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 

Constraints:

1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi and toi consist of uppercase English letters.
fromi != toi
*/
/*
Hierholzer’s Algorithm

To better understand the above algorithm, we could look at it from another perspective.

Actually, we could consider the algorithm as the postorder DFS (Depth-First Search) in a directed graph, from a fixed starting point.

As we know that, each input is guaranteed to have a solution. Therefore, the task of the problem can be interpreted as that given a list of flights (i.e. edges in graph), we should find an order to use each flight once and only once.

In the resulted path, before we visit the last airport (denoted as V), we can say that we have already used all the rest flights, i.e. if there is any flight starting from V, then we must have already taken that before.

Or to put it another way, before adding the last airport (vertex) in the final path, we have visited all its outgoing vertex.

Actually, the above statement applies to each airport in the final itinerary. Before adding an airport into the final itinerary, we must first visit all its outgoing neighbor vertex.

If we consider the outgoing vertex in a directed graph as children nodes in a tree, one could see the reason why we could consider the algorithm as a sort of postorder DFS traversal in a tree.

*/
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> paths;
        //O(E) number of edges
        for(int i = 0; i < tickets.size(); i++) {
            vector<string> edge = tickets[i];
            string from = edge[0];
            string to = edge[1];
            paths[from].push_back(to);
        }

        //V* log (number of edges connected to this vertex * 3 ) -> this is causing 
        for(auto &it: paths) {
            string from = it.first;
            sort(it.second.rbegin(), it.second.rend());
            /*
            cout<<from<<" -> ";
            for(auto to: it.second) {
                cout<<to<<" ";
            }
            cout<<endl;
            */
        }

        stack<string> st;
        stack<string> reversePath;

        st.push("JFK");
        //O(E) number of edges
        while(!st.empty()) {
            string from = st.top();

            if(paths[from].size() == 0) {
                reversePath.push(from);
                st.pop();
                continue;
            }
            //auto it = paths[from].begin();
            st.push(paths[from].back());
            paths[from].pop_back();
        }

        vector<string> result;
        while(!reversePath.empty()){
            result.push_back(reversePath.top());
            reversePath.pop();
        }
        return result;
    }
};
/*
stack: 
complete: J

[["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]
*/