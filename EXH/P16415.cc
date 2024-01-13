#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;


int n;
VI t, mc, md1, md2;

int diag1(int i, int j) {
    return i + j;
}

int diag2(int i, int j)  {
    return i - j + n - 1;           //(n - 1) siempre positivo (asi no da errores en el vector)
}

int queens_march(int k) {
    if (k == n) return 1;
    else {
        int res = 0;
        for (int i = 0; i < n; ++i){
            if (not mc[i] and not md1[diag1(k, i)] and not md2[diag2(k, i)]) {
                t[k] = i;
                mc[i] = md1[diag1(k, i)] = md2[diag2(k, i)] = true; 
                res += queens_march(k + 1);
                mc[i] = md1[diag1(k, i)] = md2[diag2(k, i)] = false; 
            }
        }
        return res;
    }
}

int main() { 
    cin >> n;
    t = vector <int> (n);
    mc = vector<int> (n, false);
    md1 = md2 = vector<int> (2*n - 1, false);
    cout << queens_march(0) << endl;
}