#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_SIZE 2147483647

typedef pair <int, int> P;
typedef vector < P > VP;
typedef vector < VP > VVP;

void dijkstra(const VVP& G, int ori, int dest, int n) {
    vector <bool> visited (n, false);
    vector <int> dist (n, MAX_SIZE);
    vector <int> steps (n, 0);
    priority_queue < P, VP, greater < P > > Q;
    Q.push(P(0, ori)); 
    dist[ori] = 0;   
    while (not Q.empty() and Q.top().second != dest) {
        int v = Q.top().second;
        Q.pop();
        if (not visited[v]) {
            visited[v] = true;
            for (auto u : G[v]) {
                int md = dist[v] + u.first;
                if (dist[u.second] > md) {
                    steps[u.second] = steps[v] + 1;
                    dist[u.second] = md;
                    Q.push(P(md, u.second));
                } 
                else if (dist[u.second] == md and steps[u.second] > steps[v] + 1) steps[u.second] = steps[v] + 1;
                
            }
        }
    }
    if (Q.empty()) {
        cout << "no path from " << ori << " to " << dest << endl;
        return;
    }
    cout << "cost " << dist[dest] << ", " << steps[dest] << " step(s)" << endl;

}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int u, v, c;
        VVP graf (n);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            graf[u].push_back(P(c, v));
        } 

        int x, y;
        cin >> x >> y;
        dijkstra(graf, x , y, n);
    }
}

