#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef vector <char> VC;
typedef vector <VC> VVC;
typedef pair <int, double> P;
typedef vector <int> VI;
typedef vector<VI> VVI;

vector<pair<int,int>> dirs = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

static const int inf = numeric_limits<int>::max();

int n, m, ini_i, ini_j;

bool pos_ok(int i, int j, const VVC& T) {
    return i >= 0 and j >= 0 and i < n and j < m and T[i][j] != 'a'; 
}

P cerca (const VVC& T) {
    int flors = 0;
    int suma_dist = 0;
    VVI dist(n, VI(m, inf));
    queue<pair<int, int>> Q;
    Q.push({ini_i,ini_j});
    dist[ini_i][ini_j] = 0;
    while (not Q.empty()) {
        pair<int, int> pos = Q.front();
        Q.pop();
        for (auto& d : dirs) {
            int next_i = pos.first + d.first;
            int next_j = pos.second + d.second;
            if (pos_ok(next_i, next_j, T) and dist[next_i][next_j] == inf) {       // == inf, significa que no esta visitado
                dist[next_i][next_j] =   dist[pos.first][pos.second] + 1;
                Q.push({next_i, next_j});
                if (T[next_i][next_j] == 'F') {
                    ++flors;
                    suma_dist += dist[next_i][next_j];
                }
            }
        }
    }
    if (flors != 0) return {flors, double(suma_dist)/flors};
    else return {0,0};
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    cin >> n >> m;
    VVC T (n, VC (m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> T[i][j];
            if (T[i][j] == 'C') {
                ini_i = i;
                ini_j = j;
            }
        }
    }
        P res = cerca(T);
        if (res.first > 0) {
            cout << "flors accessibles: " << res.first << endl;
            cout << "distancia mitjana: " << res.second << endl;
        }
        else cout << "el cavall no pot arribar a cap flor" << endl;

}