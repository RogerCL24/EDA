#include <iostream>
#include <vector>

using namespace std;

typedef vector <bool> VB;
typedef vector <VB> VVB;

const int D_X[8] = {-1, -1, 1, 1, 1, -1, 0, 0};
const int D_Y[8] = {0, 1, -1, 1 , 0, -1, 1, -1};

void next(int i, int j, int n, int& ni, int& nj) {
    if (j < n - 1) {
        ni = i;
        nj = j + 1;
    } else {
        ni = i + 1;
        nj = 0;
    }
}

void write(int n, const VVB& m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m[i][j]) cout << 'K';
            else cout << '.';
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

bool ok(int i, int j, int n) {
    return 0 <= i and 0 <= j and j < n and i < n; 
}

bool safe (int i, int j, int n, VVB& m) {
    for (int k = 0; k < 8; ++k) {
        int ii = i + D_X[k];
        int jj = j + D_Y[k];
        if (ok(ii, jj, n) and m[ii][jj]) return false;
    }
    return true;
}

void search(int i, int j, int n, int r, int s, VVB& m) {
    if (s == r) write(n, m);
    else if (i < n){
        int ni, nj;
        next(i, j, n, ni, nj);
        if (safe(i, j, n, m)) {
            m[i][j] = true;
            search(ni, nj, n, r, s + 1, m);
        }
        m[i][j] = false;
        search(ni, nj, n, r, s, m);
    }
}

int main() {
    int n, r;
    cin >> n >> r;
    VVB m(n, VB(n, false));
    search(0, 0, n, r, 0, m);
}