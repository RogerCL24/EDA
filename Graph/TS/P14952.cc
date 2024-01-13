#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;


list<int> ord_top(mi& G, vi& grade, int n) {

    priority_queue <int, vector<int>, greater <int> > Q;

    for (int i = n - 1; i >= 0; --i) {
        if (grade[i] == 0) Q.push(i);
    }

    list <int> L;
    while (not Q.empty()) {
        int v = Q.top();
        Q.pop();
        L.push_back(v);
        for (int k : G[v]) {
            if (--grade[k] == 0) Q.push(k);
        }
    }
    return L;
}


int main() {
    int n, m;
    while (cin >> n >> m) {
        mi adj(n);
        int x, y;
        vector <int> grade (n, 0);
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            adj[x].push_back(y);
            ++grade[y];
        }

        list<int> res = ord_top(adj, grade, n);
        for (list<int>::iterator it = res.begin(); it != res.end(); ++it) {
            if (it != res.begin()) cout << ' ';
            cout << *it;
        }
        cout << endl;
    }
}