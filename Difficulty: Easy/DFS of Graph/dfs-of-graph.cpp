//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
// Recursive function to perform Depth First Search (DFS)
    void recDFS(vector<int> adj[], vector<bool> &visited, int ind, vector<int> &ans) {
        // Mark the current node as visited
        visited[ind] = true;
        
        // Add the current node to the DFS traversal result
        ans.push_back(ind);
        
        // Traverse all adjacent vertices of the current node
        for (int i = 0; i < adj[ind].size(); i++) {
            // If the adjacent vertex has not been visited, recursively perform DFS on it
            if (!visited[adj[ind][i]]) {
                recDFS(adj, visited, adj[ind][i], ans);
            }
        }
    }
    
    // Function to return the DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Vector to keep track of visited nodes, initialized to false for all vertices
        vector<bool> visited(V, false);
        
        // Vector to store the DFS traversal result
        vector<int> ans;
        
        // Start DFS from the first vertex (vertex 0)
        recDFS(adj, visited, 0, ans);
        
        // Return the DFS traversal result
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends