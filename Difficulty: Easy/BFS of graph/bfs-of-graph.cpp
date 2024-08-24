//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Initialize a visited array to keep track of visited vertices
        vector<bool> visited(V, false);
        
        // This vector will store the BFS traversal result
        vector<int> ans;
        queue<int> temp;
        
        // Start BFS from the first vertex (assuming 0-based index)
        temp.push(0);
        visited[0] = true;
    
        // Continue BFS until the queue is empty
        while (!temp.empty()) {
            // Get the front vertex in the queue and remove it
            int i = temp.front();
            temp.pop();
            
            // Add the current vertex to the result
            ans.push_back(i);
            
            // Traverse the adjacency list of vertex i
            for (int j = 0; j < adj[i].size(); j++) {
                int neighbor = adj[i][j];
                // If the neighbor hasn't been visited, mark it and push to the queue
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    temp.push(neighbor);
                }
            }
        }
        
        // Return the BFS traversal result
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends