#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> P;
typedef vector <P> VP;
typedef vector <VP> VVP;

int main() {
    int n, m;
    while (cin >> n >> m) {
        int u, v, w;
        VVP G(n);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            --u;
            --v;
            G[u].push_back(P(w, v));
            G[v].push_back(P(w, u));
        }
        vector <bool> vis (n, false);
        vis[0] = true;
        priority_queue < P, VP, greater <P>> q;
        for (auto u : G[0]) q.push(u);
        int sz = 1;
        int sum = 0;
        while (sz < n) {
            int c = q.top().first;
            int v = q.top().second;
            q.pop();
            if (not vis[v]) {
                vis[v] = true;
                for (auto x : G[v]) q.push(x);
                sum += c;
                ++sz;            
            }
        }
        cout << sum << endl;
        
    }
}