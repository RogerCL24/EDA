#include <iostream>
#include <vector>


using namespace std;

typedef vector <string> VS;
typedef vector <VS> VVS;

VS vs;
VVS partition;
int n;

void write() {
    int size = partition.size();
    for (int i = 0; i < size; ++i) {
        cout << "subconjunt " << i + 1 << ": {";
        int part_size = partition[i].size();
        for (int j = 0; j < part_size - 1; ++j) cout << partition[i][j] << ",";
        if (not partition[i].empty()) cout << partition[i][part_size - 1];
        cout << "}" << endl;
    }
    cout << endl;
}

void combine(int x) {
    if (x == vs.size()) write();
    else {
        for (int i = 0; i < partition.size(); ++i) {
            partition[i].push_back(vs[x]);
            combine(x + 1);
            partition[i].pop_back();
        }
    }
    
}

int main() {
    cin >> n;

    vs = VS(n);
    for (int i = 0; i < n; ++i) cin >> vs[i];

    int p;
    cin >> p;
    partition = VVS(p);
    combine(0); 

}