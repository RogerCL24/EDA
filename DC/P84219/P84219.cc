#include <iostream>
#include <vector>

using namespace std;

int first_occurrence_rec(double x, const vector<double>& v, int l, int r) {
    int m = (r + l)/2;
    if (l > r) return -1;
    if (x < v[m]) return first_occurrence_rec(x,v,l,m-1);
    else if (x > v[m]) return first_occurrence_rec(x,v,m+1,r);
    else if (m > 0 and v[m-1] == x) return first_occurrence_rec(x,v,l,m-1);
    else return m;
}



int first_occurrence(double x, const vector<double>& v) {
    if (v.empty() or x < v[0] or v[v.size() - 1] < x) return -1;
    else return first_occurrence_rec(x,v,0,v.size() - 1);
}