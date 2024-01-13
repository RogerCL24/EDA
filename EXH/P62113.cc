#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int x, n;
VI v, times;
VB c1, c2;


void exchange(int sum, int i) {
    if (sum == x) {
        sum = 0;
        cout << x << " = ";
        for (int i = 0; i < n; ++i) {
            if (c1[i]) {
                cout << v[i];
                sum += v[i];
                if (sum != x) cout << " + ";
            }
            if (c2[i]) {
                cout << v[i] << "p";
                sum += v[i];
                if (sum != x) cout << " + ";
            }
        }
        cout << endl;
    }
    else if (x > sum and i < n){
        if (v[i] + sum <= x) {
            if (not c1[i]) {
                c1[i] = true;
                exchange(sum + v[i], i);
                c1[i] = false;
            }
            if (not c2[i]) {
                c2[i] = true;
                exchange(sum + v[i], i + 1);
                c2[i] = false;
            }
            exchange(sum, i + 1);
        }
    }
}

int main() {
    while (cin >> x >> n) {
        v = VI(n);
        times = VI (n,0);
        c1 = c2 = VB(n, false);
        for (int i = 0; i < n; ++i) cin >> v[i];     
        sort(v.begin(), v.end()); 
        exchange(0,0);
        cout << "----------" << endl;
    }
}