#include <iostream>

using namespace std;

double fast_exp(double x, int n) {
    if (n == 0) return 1;
    else {
        double y = fast_exp(x, n/2);
        if (n%2 == 0) return y * y;
        else return y * y * x;
    }
}

int search_day(int min, int max, double r, double q, double f) {
    if (min <= max) {
        int m = (max+min)/2;
        double rb = fast_exp(r,m) * q;          //return bank
        double rg = f * m + q;                  //return guy      
        if (rg > rb) return search_day(m + 1, max, r, q, f);
        else if (rg < rb) return search_day(min, m - 1, r, q, f);
        else return m;                                
    }
    else return min;
}



int main() {
    double m, f, r;
    while (cin >> m >> f >> r) {
        r = (r/100) + 1;
        cout <<  search_day(1, 10000000, r, m, f) << endl;
    }
}