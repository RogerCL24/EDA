#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector <VB> VVB;
typedef pair<int,int> P;

const int D_X[4] = {0, -1, 0, 1};
const int D_Y[4] = {1, 0, -1, 0};

int n, m, ox, oy, fx, fy;

bool ok (int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

void search_path(const VVC& land, vector<P>& v, VVB& vis) {
    P p = v.back();
    if (p.first == fx and p.second == fy) {
        for (int i = 0; i < v.size(); ++i) cout << land[v[i].first][v[i].second];
        cout << endl;
    }
    else {
        for (int k = 0; k < 4; ++k) {
            int next_x = p.first + D_X[k];
            int next_y = p.second + D_Y[k];
            if (ok(next_x, next_y) and not vis[next_y][next_y]) {
                vis[next_x][next_y] = true;
                v.push_back(P(next_x, next_y));
                search_path(land, v, vis);
                v.pop_back();
                vis[next_x][next_y] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    VVC land (n, VC(m));
    VVB vis (n, VB(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> land[i][j];
    }
    cin >> ox >> oy >> fx >> fy;
    vis[ox][oy] = true;
    vector <P> v (1, P(ox, oy));
    search_path(land, v, vis);
}