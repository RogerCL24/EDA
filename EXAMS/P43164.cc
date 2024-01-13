#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<int> VI;
typedef vector <VI> VVI;
typedef pair<int,int> P;
static const int inf = numeric_limits<int>::max();

const int D_X[4] = {1, 0, -1, 0};
const int D_Y[4] = {0, 1, 0, -1};

int n, m;

bool pos_ok(int i, int j, const VVC& b) {
    return i >= 0 and j >= 0 and i < n and j < m and b[i][j] != 'X';
}

int bfs(const VVC& b, int f, int c) {
    int dist_max_1 = 0;
    int dist_max_2 = 0;
    VVI dist (n, VI(m,inf));
    queue <P> q;
    dist[f][c] = 0;
    q.push(P(f,c));
    while (not q.empty()) {
        P p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_i = p.first + D_X[i]; 
            int next_j = p.second + D_Y[i];
            if (pos_ok(next_i, next_j, b) and dist[next_i][next_j] == inf) {
                dist[next_i][next_j] = dist[p.first][p.second] + 1;
                q.push(P(next_i, next_j));
                if (b[next_i][next_j] == 't') {
                    if (dist[next_i][next_j] >= dist_max_1){
                        dist_max_2 = dist_max_1;
                        dist_max_1 = dist[next_i][next_j];
                    }
                }
            }
        }     
    }

    return dist_max_2;

}

int main() {
    cin >> n >> m;
    VVC board (n, VC(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> board[i][j];
    }

    int f, c;
    cin >> f >> c;
    --f;
    --c;
    int dist = bfs(board, f, c);
    if (dist == 0) cout << "no es pot arribar a dos o mes tresors" << endl;
    else cout << "segona distancia maxima: " << dist << endl; 

}