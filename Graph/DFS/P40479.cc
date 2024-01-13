#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> mc;
typedef pair<int, int> pr;
typedef vector<pr> vp;



void fullfill(mc& board, pr& p, int n, int m, char c) {
    vector <vector <bool> > visited(n, vector<bool> (m));
    queue<pr> q;
    int x, y;
    q.push(p);
    while (not q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (not visited[x][y]) {
            visited[x][y] = true;
            if (board[x][y] == '.') board[x][y] = c;

            if (x - 1 >= 0 and board[x - 1][y] != '#') q.push(pr(x - 1, y));
            if (x + 1 < n and board[x + 1][y] != '#') q.push(pr(x + 1, y));
            if (y - 1 >= 0 and board[x][y - 1] != '#') q.push(pr(x, y - 1));
            if (y + 1 < m and board[x][y + 1] != '#') q.push(pr(x, y + 1));
        }   
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        mc board(n, vc(m));
        vp v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> board[i][j];
                if (board[i][j] != '.' and board[i][j] != '#')  v.push_back(pr(i, j));      //Pos with a letter
            }
        }

        for (int i = 0; i < v.size(); ++i) fullfill(board, v[i], n, m, board[v[i].first][v[i].second]);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}