#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector <int> VE;
typedef vector <VE> VVE;

int k_esim(int k, const VVE& V) {
    map <int, int> m;
    for (int i = 0; i < V.size(); i++) {
        if (not V[i].empty()) m[V[i][0]] = i;
    }

    pair <int, int> res;
    VE it(V.size(), 1);
    while (k--) {
        res = *m.begin();
        if (V[res.second].size() > it[res.second]) m[ V[res.second][it[res.second]++]] = res.second;
        m.erase(m.begin());
    }
    return res.first;
}