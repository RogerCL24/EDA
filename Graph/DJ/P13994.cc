#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int,int> P;
typedef vector <P> VP;
typedef vector <VP> VVP;

void dijkstra(const VVP& g, int x, int y, int n) {
    vector <bool> visited(n, false);
    vector <int> dist (n, 10001);
    vector <int> minwein(n, -1);
    priority_queue < P, VP, greater < P > > Q;
    Q.push({0, x});
    dist[x] = 0;

    while (not Q.empty() and Q.top().second != y) {
        int node = Q.top().second;
        Q.pop();

        if (not visited[node]) {
            visited[node] = true;
            for (auto aux : g[node]) {
                int td = dist[node] + aux.first;
                if (dist[aux.second] > td) {
                    dist[aux.second] = td;
                    minwein[aux.second] = node;
                    Q.push({dist[aux.second], aux.second});
                }
            }
        }
    }
    if (Q.empty()) {
        cout << "no path from " << x << " to " << y << endl;
        return;
    }
    
    stack <int> res;
    while (minwein[y] != -1) {
        res.push(y);
        y = minwein[y];
    }

    res.push(y);
    cout << res.top();
    res.pop();
    while (not res.empty()) {
        cout << " " << res.top();
        res.pop();
    }

    cout << endl;
}


int main() {
    int n,m;
    while (cin >> n >> m) {
        int u, v, c;
        VVP graf (n);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            graf[u].push_back(P(c, v));         //U se dirige a V con coste C
        }
        int x, y;
        cin >> x >> y;
        dijkstra(graf, x, y, n);
    }
}