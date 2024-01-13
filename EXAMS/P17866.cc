#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> P;

static const int inf = numeric_limits<int>::max();

const int D_X[8] = {1,-1, -1, 1, 2, 2, -2, -2};
const int D_Y[8] = {2, 2, -2, -2, 1, -1, -1, 1};

int n, m, f, c;

bool pos_ok(int i, int j, const VVC& b) {
    return i >= 0 and j >= 0 and i < n and j < m and b[i][j] != 'X'; 
}

int bfs(const VVC& b) {
    VVI dist (n, VI(m, inf));
    queue<P> q;
    q.push(P(f, c));
    dist[f][c] = 0;
    while (not q.empty()) {
        P p = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int n_i = p.first + D_X[i]; 
            int n_j = p.second + D_Y[i];
            if (pos_ok(n_i, n_j, b) and dist[n_i][n_j] == inf) {
                dist[n_i][n_j] = dist[p.first][p.second] + 1;
                q.push(P(n_i, n_j));
                if (b[n_i][n_j] == 'p') return dist[n_i][n_j];
            }
        }
    }
    return 0;
}

int main() {
    while (cin >> n >> m) {
        VVC b (n, VC(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cin >> b[i][j];
        }

        cin >> f >> c;
        --f;
        --c;
        int d = bfs(b);
        if (d == 0) cout << "no" << endl;
        else cout << d << endl;
    }

}