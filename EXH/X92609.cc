#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int n, x;
VI coins;
VB c1, c2;

int backtracking(int sum, int i) {
    if (sum == x) return 1;
    else if (x > sum and i < n){
        int res = 0;
        if (not c1[i]) {
            c1[i] = true;
            res += backtracking(sum + coins[i], i);
            c1[i] = false;
        }
        else if (not c2[i]) {
            c2[i] = true;
            res += backtracking(sum + coins[i], i + 1);
            c2[i] = false;
        }
        res += backtracking(sum, i + 1);
        
        return res;
    }
    return 0;
}

int main() {
    
    while (cin >> x >> n) {
        c1 = c2 = VB (n, false);
        coins = VI (n);
        for (int i = 0; i < n; ++i) {
            cin >> coins[i];
        }
        sort(coins.begin(), coins.end());
        cout << backtracking(0,0) << endl;
    }
}