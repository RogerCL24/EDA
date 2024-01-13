#include <iostream>
#include <vector>

using namespace std;

void inv_2(vector <int>& v, int u, int n) {
    if (v.size() == n) {
        for (int i = 0; i < n; ++i) {
            cout << v[i];
            if (i != n - 1) cout << ' ';
        }
        cout << endl;
    }
    else {
        if (n + u < v.size()) {
            v[n] = 0;
            inv_2(v, u, n + 1);
        }

        if (u != 0) {
            v[n] = 1;
            inv_2(v, u - 1, n + 1);
        }      
    }

}


int main() {
    int n, u;
    cin >> n >> u;

    vector<int> v(n);
    inv_2(v, u, 0);
}