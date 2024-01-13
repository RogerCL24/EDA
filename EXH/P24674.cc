#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<string> VS;
typedef vector<bool> VB;

void permutation(VS& v2s, VS& perm,VB& visited, int n) {
    if (n == perm.size()) {
        cout << "(";
        for (int i = 0; i < n; ++i) {
            cout << perm[i];
            if (i != n - 1) cout << ',';
        }
        cout << ")" << endl;
    }
    else {
        for (int i = 0; i < v2s.size(); ++i) {
            if (not visited[i]) {
                visited[i] = true;
                perm[n] = v2s[i];
                permutation(v2s, perm, visited, n + 1);
                visited[i] = false;
            }

        }
    }
}


int main() {
    int n;
    cin >> n;
    VS v2s (n);       
    for (int i  = 0; i < n; ++i) cin >> v2s[i];                      //Each word belongs to an index
    VS perm (n);
    VB visited (n, false);
    permutation(v2s, perm, visited, 0);

}
