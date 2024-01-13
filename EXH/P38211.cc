#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector <vector <char>> VVC;

int n;
VI t, mc, md1, md2;

void write_board(VVC& board) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << board[i][j];    
        
        cout << endl;
    }
}   

int diag1(int i, int j) {
    return i + j;
}

int diag2(int i, int j) {
    return i - j + n - 1;
} 

void queens_march(int i, VVC& board, bool& found) {
    if (i == n) {
        found = true;
        write_board(board);
    }
    else {
        for (int j = 0; j < n and not found; ++j) {
            if (not mc[j] and not md1[diag1(i, j)] and not md2[diag2(i, j)]) {
                mc[j] = md1[diag1(i,j)] = md2[diag2(i,j)] = true;
                board[i][j] = 'Q';
                queens_march(i + 1, board, found);
                mc[j] = md1[diag1(i,j)] = md2[diag2(i,j)] = false;
                board[i][j] = '.';
            }
        }
    }
}

int main() {
    cin >> n;
    t = VI(n);
    mc = VI(n, false);
    md1 = md2 = VI(2*n - 1, false);
    VVC board (n, vector<char>(n, '.'));
    bool found = false;
    queens_march(0, board, found);
    if (not found) cout << "NO SOLUTION" << endl;
}