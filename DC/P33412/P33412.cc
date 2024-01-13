#include <iostream>
#include <vector>

using namespace std;

bool i_resistant_search(double x, const vector<double>& v, int l, int r) {
    int m = (l + r)/2;
    if (l > r) return false;
    if (x < v[m]) {
        if (m < v.size() - 1 and x == v[m + 1]) return true;
        else return i_resistant_search(x, v, l, m-1);
    }
    else if (v[m] < x) {
        if (m > 0 and x == v[m - 1]) return true;
        else return     i_resistant_search(x, v, m + 1, r);
    }
    else return true;


}


bool resistant_search(double x, const vector<double>& v) {
    if (v.empty()) return false;
    else return i_resistant_search(x, v, 0, v.size() - 1);
}