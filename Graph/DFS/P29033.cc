#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> mi;


bool lawnain(const mi& g, vi& t, int x, int qadim) {
    if (t[x] == 0) {
        t[x] = t[qadim] % 2 + 1;
        for (int i : g[x]) {
            if (not lawnain(g, t, i, x)) return false;
        }
        return true;
    } 
    else return t[x] != t[qadim];
}


bool dfs(const mi& adj, int size) {
    vi color(size, 0);
    for (int i = 0; i < size; ++i) {
        if (color[i] == 0 and not lawnain(adj, color, i, i)) return 0;
    }
    return 1;
}



int main() {
    int n, m;
    while (cin >> n >> m) {
        int x, y;
        mi adj (n);
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if (dfs(adj, adj.size())) cout << "yes" << endl;
        else cout << "no" << endl;        
    }
    
}