#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <list>

using namespace std;

typedef vector <char> VC;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef map <char, int> MCI;

VC species;
MCI s2i;
VVB mat;
VB vis;

void backtracking(string s, int k) {
    if (s.length() == species.size()) cout << s << endl;
    else {
        for (int i = 0; i < mat.size(); ++i) {
            if (not vis[i] and mat[k][i]) {
                vis[i] = true;
                backtracking(s + species[i], i);
                vis[i] = false;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    species = VC (n);
    for (int i = 0; i < n; ++i) {
        cin >> species[i];
        s2i[species[i]] = i;
    }
    cin >> m;
    mat = VVB(n, VB(n, true));
    for (int i = 0; i < m; ++i) {
        char a, b;
        cin >> a >> b;
        int na = s2i[a];
        int nb = s2i[b];
        mat[na][nb] = mat[nb][na] = false;
    }
    vis = VB (n, false);
    for (int i = 0; i < n; ++i) {
        string s = "";
        s += species[i];
        vis[i] = true;
        backtracking(s, i);
        vis[i] = false;
    } 
    
}