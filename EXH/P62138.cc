#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

typedef vector <int> VI;
typedef list <int> LI;
typedef set <int> SI;
typedef vector <LI> VLI;
typedef vector <bool> VB;

VLI vl;
VI v;
LI l;
SI s;

void backtracking(int n) {
    if (not n) {
        bool first = true;
        for (int i : l) {
            if (first) first = false;
            else cout << " ";
            cout << i;
        }
        cout << endl;
    }
    else {
        for (auto it = s.begin(); it != s.end(); ++it) {
            int num = *it;
            for (int j : vl[num]) {
                if (not (--v[j])) s.insert(j);      //si llega a grado 0 se añade al set
            }
            s.erase(it);
            l.push_back(num);
            backtracking(n - 1);
            l.pop_back();
            auto aux = s.insert(num);
            it = aux.first;
            for (int j : vl[num]){
                if (not (v[j]++)) s.erase(j);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vl = VLI(n);                        //grafo de adj
    v = VI(n, 0);                       //numero de entradas de cada vertice                
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        vl[x].push_back(y);
        ++v[y];
    }
    for (int i = 0; i < n; ++i) {
        if (not v[i]) s.insert(i);      //vertices sin entrada (grado 0)
    }
    backtracking(n);
}