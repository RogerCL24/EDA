#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_SIZE 2147483647

typedef pair<int, int> P;
typedef vector <P> VP;
typedef vector <VP> VVP;

void dijkstra(const VVP& G, int x, int y, int n) {
    vector <bool> visited (n, false);
    vector <int> dist (n, MAX_SIZE);
    vector <int> ways (n, 0);
    priority_queue <P, VP, greater <P> > q;
    q.push(P(0, x));
    dist[x] = 0;
    ways[x] = 1;

    while (not q.empty()) {
        int v = q.top().second;
        q.pop();
        if (not visited[v]) {
            visited[v] = true;
            for (auto u : G[v]) {
                int d = dist[v] + u.first;          // V goes to U
                if (dist[u.second] > d) {
                    dist[u.second] = d;
                    ways[u.second] = ways[v];
                    q.push(P(d, u.second));
                }
                else if (dist[u.second] == d) ways[u.second] += ways[v]; 
            }
        }
    }

    if (dist[y] == MAX_SIZE) {
        cout << "no path from " << x << " to " << y << endl;
        return;
    }

    cout << "cost " << dist[y] << ", " << ways[y] << " way(s)" << endl;
}


int main() {
    int n, m;
    while (cin >> n >> m) {
        VVP G (n);
        int u, v, c;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            G[u].push_back(P(c, v));
        }

        int x, y;
        cin >> x >> y;
        dijkstra(G, x, y, n);
    }
}