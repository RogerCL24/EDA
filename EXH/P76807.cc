#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;

VVI su;
VVI r_mkd, c_mkd;
VVVI s_mkd;

void write() {
    cout << endl;
    for (int i = 0; i < 9; ++i) {
        cout << su[i][0];
        for (int j = 1; j < 9; ++j) {
            cout << ' ' << su[i][j];
        }
        cout << endl;
    }
}

bool fill (int i, int j) {
    if (i == 9) {
        write();
        return true;
    }
    if (j == 9) return fill(i + 1, 0);
    if (su[i][j] != 0) return fill(i , j + 1);
    for (int v = 1; v <= 9; ++v) 
        if (not r_mkd[i][v] and not c_mkd[j][v] and not s_mkd[i/3][j/3][v]) {
            r_mkd[i][v] = c_mkd[j][v] = s_mkd[i/3][j/3][v] = true;
            su[i][j] = v;
            if (fill(i, j + 1)) return true;
            su[i][j] = 0;
            r_mkd[i][v] = c_mkd[j][v] = s_mkd[i/3][j/3][v] = false;
        }
    return false;
}

int main() {
    su = VVI (9, VI (9));
    int n;
    cin >> n;
    cout << n << endl;
    while (n--) {
        r_mkd = c_mkd = VVI(9, VI(10, false));
        s_mkd = VVVI(3, VVI(3, VI(10, false)));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c;
                cin >> c;
                if (c == '.') su[i][j] = 0;
                else {
                    int v = c - '0';
                    su[i][j] = v;
                    r_mkd[i][v] = c_mkd[j][v] = s_mkd[i/3][j/3][v] = true;
                }
            }
            fill(0, 0);
        }
    }
}