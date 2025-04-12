#include <iostream>
#include <vector>
using namespace std;

bool dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, adj, visited, recStack))
                return true;
        } else if (recStack[v]) {
            return true;
        }
    }

    recStack[u] = false;
    return false;
}

bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V;
    cin >> V;
    vector<vector<int>> adj(V);

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int val;
            cin >> val;
            if (val == 1) {
                adj[i].push_back(j);
            }
        }
    }

    if (hasCycle(V, adj)) {
        cout << "Yes Cycle Exists\n";
    } else {
        cout << "No Cycle Exists\n";
    }

    return 0;
}
