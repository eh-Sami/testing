#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> adj;
    unordered_set<int> s;
    vector<int> ans;
    void dfs(int k) {
        if(s.find(k) == s.end()) {
            for(auto &it : adj[k]) {
                dfs(it);
            }
            ans.push_back(k);
            s.insert(k);
        }
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        adj.resize(V);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);     
        }
        for(int i = 0; i < V; i++) {
            dfs(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    
    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter edges (u v format, 0-based indexing):" << endl;
    for(int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    Solution sol;
    vector<int> result = sol.topoSort(V, edges);
    
    cout << "Topological Sort: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

