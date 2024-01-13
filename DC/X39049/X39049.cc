#include <iostream>
#include <vector>

using namespace std;

void product(vector<int>& a, vector<int>& b) {
    vector<int> res(a.size());
    for (int i = 0; i < a.size(); ++i) {
        res[i] = a[b[i]];   
    }
    a = res;
}

vector <int> exp(vector<int>& v, int k){
    vector <int> res(v.size());
    if (k == 0) {
        for (int i = 0; i < res.size(); ++i) res[i] = i;
        return res;
    }
    res = exp(v, k/2);
    if (k%2 == 0) product(res, res);
    else {
        product(res, res);
        product(res, v);
    }
    return res;
}


int main() {
    int n, k;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        cin >> k;
        vector <int> res = exp(v, k);
        for (int i = 0; i < n; ++i) {
            cout << res[i];
            if (i != n - 1) cout << ' '; 
        }
        cout << endl;
    }
}