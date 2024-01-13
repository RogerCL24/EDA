#include <iostream>
#include <vector>

using namespace std;

void inv(vector <int> v, int n) {
    if (v.size() == n) {
        for (int i = 0; i < n; ++i) {
            cout << v[i];
            if (i != n - 1) cout << ' ';
        }
        cout << endl;
    }
    else {
        v[n] = 0;
        inv(v, n + 1);

        v[n] = 1;
        inv(v, n + 1);
    }
}

int main() {
    int n;
    cin >> n;

    vector <int> v (n);
    inv(v, 0);
}