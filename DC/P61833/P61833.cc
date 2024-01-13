#include <iostream>
#include <vector>

using namespace std;

typedef vector <vector <int> > matrix;

void mult (const matrix& M1, const matrix& M2, matrix& p, int m) {
    p = matrix(M1.size(), vector<int>(M2[0].size(), 0));
    for (int i = 0; i < M1.size(); ++i) {
        for (int j = 0; j < M2[0].size(); ++j) {
            for (int k = 0; k < M2.size(); ++k){
                p[i][j] += M1[i][k] * M2[k][j];
            }
            p[i][j] %= m;
        }
    }
}


void power(const matrix& m, int n, int mod, matrix& p) {
    if (n == 0) {
        p[0][0] = p[1][1] = 1;
        p[0][1] = p[1][0] = 0;
    } 
    else if (n == 1) {
        p[0][0] = m[0][0] % mod;
        p[0][1] = m[0][1] % mod;
        p[1][0] = m[1][0] % mod;
        p[1][1] = m[1][1] % mod;
    }
    else if (n%2 == 0) {
        matrix aux(2, vector<int> (2));
        power(m, n/2, mod, aux);
        mult(aux, aux, p, mod);
    }
    else {
        matrix aux(2, vector<int> (2));
        power(m, n - 1, mod, aux);
        mult(m, aux, p, mod);
    }

}

int main() {
    matrix ma(2, vector<int> (2));
    int n, m;
    while (cin >> ma[0][0] >> ma[0][1] >> ma[1][0] >> ma[1][1] >> n >> m) {
        matrix p(2, vector <int> (2));
        power(ma, n, m, p);
        cout << p[0][0] << ' ' << p[0][1] << endl;
        cout << p[1][0] << ' ' << p[1][1] << endl;
        cout << "----------" << endl;
    }


}
