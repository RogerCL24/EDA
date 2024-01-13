#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <char> VC;
typedef vector <VC> VVC;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int,int> P;

const int D_X[4] = {1, 0, -1, 0};
const int D_Y[4] = {0, 1, 0, -1};

bool pos_ok(int i, int j, int n , int m) {
    return i < n and j < m and i >= 0 and j >= 0;
}


int search(const VVC& map, int n, int m, int f, int c) {
    VVI dist (n, VI(m,-1));
    queue <P> q;
    int max_dist = -1;
    q.push(P(f, c));
    dist[f][c] = 0;
    while (not q.empty()) {
        P p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int next_x = i + D_X[k];
            int next_y = j + D_Y[k];
            if (pos_ok(next_x, next_y, n, m) and map[next_x][next_y] != 'X' and dist[next_x][next_y] == -1) {
                q.push(P(next_x, next_y));
                dist[next_x][next_y] = 1 + dist[i][j];
                if (map[next_x][next_y] == 't') max_dist = dist[next_x][next_y];
            }
        }
    }

    return max_dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    VVC map (n, VC(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> map[i][j]; 
    }
    int f, c;
    cin >> f >> c;
    --f;
    --c;
    int dist = search(map, n, m, f, c);
    if (dist >= 0) cout << "distancia maxima: " << dist << endl;
    else cout << "no es pot arribar a cap tresor" << endl;

}