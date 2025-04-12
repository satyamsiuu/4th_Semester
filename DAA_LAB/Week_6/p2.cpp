#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1);  // -1 means uncolored

    for (int start = 0; start < V; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
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

    if (isBipartite(V, adj)) {
        cout << "Yes Bipartite\n";
    } else {
        cout << "Not Bipartite\n";
    }

    return 0;
}
