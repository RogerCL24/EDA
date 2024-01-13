#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;

struct cell {
    char type;
    bool visited;
    int bishops;
    cell() : type('V'), visited(false), bishops(0) {

    }

};

typedef pair<int, int> pr;
typedef vector<cell> vc;
typedef vector <vc> mc;


int bishop(mc& board, int i, int j, int n, int m) {
    queue <pr> q;
    q.push(pr(i, j));
    int x, y;
    int cells = 0;
    int bishops = 0;

    while (not q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (board[x][y].type == 'V' and not board[x][y].visited) {
            board[x][y].visited = true;
            ++cells;
            bishops += board[x][y].bishops;

            if (x + 1 < n and y + 1 < m) q.push(pr(x + 1, y + 1));
            if (x - 1 >= 0 and y + 1  < m) q.push(pr(x - 1, y + 1));
            if (x + 1 < n and y - 1 >= 0) q.push(pr(x + 1, y - 1));
            if (x - 1 >= 0 and y - 1 >= 0) q.push(pr(x - 1, y - 1));
        }
    }
    
    if (bishops % cells == 0) return bishops/cells;
    else return -2;
}

int main() {
    int t, n ,m;
    string s;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        mc board(n, vc(m));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cin >> s;
                if (s == "X") board[j][k].type = 'X';
                else board[j][k].bishops = atoi(s.c_str());
            }
        }

        int mit_total = -1;
        int mit;

        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (board[j][k].type == 'V' and not board[j][k].visited) {
                    mit = bishop(board,j, k, n, m);
                    if (mit_total == -1) mit_total = mit;
                    else if (mit_total != mit) mit_total = -2;
                }
            }
        }
        
        cout << "Case " << i + 1 << ": ";
        if (mit_total == -2) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}