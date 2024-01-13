#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int>& v, vector<bool>& vis, int n) {
    if (n == v.size()) {
        cout <<  "(";
        for (int i = 0; i < n; ++i) {
            cout << v[i];
            if (i != n - 1) cout << ",";
        }
        cout << ")" << endl;
    }
    else {
        for (int i = 1; i <= v.size(); ++i) {
            if (not vis[i]) {
                vis[i] = true;
                v[n] = i;
                permutation(v, vis, n + 1); 
                vis[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> v (n);
    vector <bool> vis (n + 1, false);
    permutation(v, vis, 0);

}