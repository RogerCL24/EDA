#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector <vc> mc;

typedef vector<bool> vb;
typedef vector<vb> mb;

const vector <int> D_X {1, 0, -1, 0};
const vector <int> D_Y {0, 1, 0, -1};

bool ok (int x, int y, int n, int m) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

bool tresor(const mc& mapa, mb& visited,int x, int y, int n, int m) {
    if (visited[x][y]) return false;
    visited[x][y] = true;
    if (mapa[x][y] == 't') return true;
    for (int i = 0; i < 4; ++i) {
        int next_x = x + D_X[i];
        int next_y = y + D_Y[i];
        if (ok(next_x, next_y, n, m) and mapa[next_x][next_y] != 'X') 
            if (tresor(mapa, visited, next_x, next_y, n, m)) return true;
    }
    return false;
}

int main() {
    int n, m, f, c;
    cin >> n >> m;

    mc mapa (n, vc(m));
    mb visited(n, vb(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mapa[i][j];
        }
    }

    cin >> f >> c;

    if (tresor(mapa,visited, f - 1, c - 1, n, m)) cout << "yes" << endl;
    else cout << "no" << endl;

}