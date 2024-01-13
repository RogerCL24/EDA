#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> mc;

typedef vector <bool> vb;
typedef vector <vb> mb;


void accessibles(vector<vc>& mapa, vector<vb>& visited, int x, int y, int& count, int n, int m) {
    if (not visited[x][y]) {
        visited[x][y] = true;
        if (mapa[x][y] == 't') ++count;
        if (mapa[x][y] != 'X') {
            if (y < m - 1) accessibles(mapa, visited, x, y + 1, count, n, m);
            if (x < n - 1) accessibles(mapa, visited, x + 1, y, count, n, m);
            if (x > 0) accessibles(mapa, visited, x - 1 , y, count, n, m);
            if (y > 0) accessibles(mapa, visited, x, y - 1, count, n, m);

        }
    }
 
}

int main() {
    int n, m, f, c;
    cin >> n >> m;
    mc mapa (n, vc(m));
    mb visited (n, vb(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mapa[i][j];
        }
    }

    cin >> f >> c;
    int count = 0;
    accessibles(mapa, visited, f - 1, c - 1, count, n, m);

    cout << count << endl;
    
}