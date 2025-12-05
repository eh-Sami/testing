#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bfs(int v, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size());
    vector<vector<int>> l(adj.size()); // l[i] is the set of nodes we can reach in i steps from v
    l[0].push_back(v); // we can reach in 0 steps
    visited[v] = true;

    for(int i = 0; i < adj.size(); i++) {
        if(l[i].empty()) break;

        for(auto &it : l[i]) {

            for(auto &u : adj[it]) {

                if(!visited[u]) {
                    visited[u] = true;
                    l[i + 1].push_back(u);
                }

            }

        }
    }

    return l;
}

pair<vector<int>, vector<int>> bfs2(int v, vector<vector<int>>& adj) {
    vector<int> ans;
    vector<bool> visited(adj.size());
    vector<int> dist(adj.size());
    queue<int> q;
    q.push(v);
    visited[v] = true;
    dist[v] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(auto &it : adj[x]) {
            if(!visited[it]) {
                visited[it] = true;
                dist[it] = dist[x] + 1;
                q.push(it);
            }
        }
    }
    return {ans, dist};
}

int main() {
    // Create a sample graph with 6 nodes (0-5)
    //   0 -- 1 -- 3
    //   |    |
    //   2 -- 4 -- 5
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2, 5};
    adj[5] = {4};

    cout << "BFS levels from node 0:" << endl;
    vector<vector<int>> levels = bfs(0, adj);
    for (int i = 0; i < levels.size(); i++) {
        cout << "Level " << i << ": ";
        for (int node : levels[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    cout << "\nBFS2 traversal from node 0:" << endl;
    auto [order, dist] = bfs2(0, adj);
    for (int node : order) {
        cout << node << " ";
    }
    cout << endl;

    cout << "\nDistances from node 0:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}