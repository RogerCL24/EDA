#include <iostream>
#include <vector>

using namespace std;

int find_unimodal(const vector<int>& v, int i, int j) {
    if (j == i) return j;
    if (j - i == 1) {
        if (v[j] > v[i]) return j;
        return i;
    } 
    int m = (i + j)/2;
    if (v[m - 1] < v[m] and v[m] < v[m + 1]) return find_unimodal(v, m + 1, j);
    if (v[m - 1] > v[m] and v[m] > v[m + 1]) return find_unimodal(v, i, m - 1);
    return m;   
}

bool x_search(const vector<int>& v, int x, int i, int j, int mode) {
     
     if (i > j) return false;
     int m = (j+i)/2;
     if (v[m] == x) return true;
     if ((mode == 0 and v[m] > x) or (mode == 1 and v[m] < x)) return x_search(v, x, i, m - 1, mode);
     return x_search(v, x, m + 1, j, mode);
     
}



bool search(int x, const vector<int>& v) {
    int pos = find_unimodal(v, 0, v.size() - 1);
    if (x_search(v, x, 0, pos, 0)) return true;
    if (x_search(v, x, pos, v.size() - 1, 1)) return true;
    return false;
}