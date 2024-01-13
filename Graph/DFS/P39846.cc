#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef vector <char> vc;
typedef vector <vc> mc;
 
typedef vector <bool> vb;
typedef vector <vb> mb;

int bfs(const mc& mapa, int x, int y, int n, int m) {
    mb visited(n, vb(m, false));

    queue <pair < pair <int, int>,int > > q;
    q.push(make_pair(make_pair(x, y),0));

    int a,b,d;
    stack <int> s;
    while (!q.empty()) {
        a = q.front().first.first;
        b = q.front().first.second;
        d = q.front().second;
        q.pop();

        if (!visited[a][b]) {
            visited[a][b] = true;
            if (mapa[a][b] == 't') s.push(d);
            if (a != 0 and mapa[a - 1][b] != 'X') q.push(make_pair(make_pair(a - 1, b), d + 1));
            if (a < n - 1 and mapa[a + 1][b] != 'X') q.push(make_pair(make_pair(a + 1, b) , d + 1));
            if (b != 0 and mapa[a][b - 1] != 'X') q.push(make_pair(make_pair(a, b - 1), d + 1));
            if (b < m - 1 and mapa[a][b + 1] != 'X') q.push(make_pair(make_pair(a, b + 1), d + 1));
        }
    }
    if (!s.empty()) return s.top();
    else return -1;
}

int main() { 
    int n, m;
    cin >> n >> m;

    mc mapa (n, vc(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mapa[i][j];
        }
    }

    int f, c;
    cin >> f >> c;
    int dist = bfs(mapa, f - 1, c - 1, n , m);
    if (dist == -1) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia maxima: " << dist << endl;
}