#include <iostream>
#include <vector>

using namespace std;


typedef vector <int> VI;
typedef vector <VI> VVI;
int n;
VI t, mc, md1, md2;
VVI board;

int diag1(int i, int j) {
    return i + j;
}

int diag2(int i, int j) {
    return i - j + n - 1;
}

void write_board() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j]) cout << "Q";
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}

void queen_march(int i) {
    if (i == n) write_board();
    else {
        for (int j = 0; j < n; ++j) {
            if (not mc[j] and not md1[diag1(i, j)] and not md2[diag2(i, j)]) {
                t[i] = j;
                mc[j] = md1[diag1(i, j)] = md2[diag2(i, j)] = true;
                board[i][j] = true;
                queen_march(i + 1);
                mc[j] = md1[diag1(i, j)] = md2[diag2(i, j)] = false;
                board[i][j] = false;
            }
        }
    }
}


int main() {
    cin >> n;
    t = VI (n);
    mc = VI (n, false);
    md1 = md2 = VI (2*n - 1, false);
    board = VVI (n, VI(n, false));
    queen_march(0);
}