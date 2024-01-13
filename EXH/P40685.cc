#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> VI;

int s, n;
VI numbers, sum, vis;

void write() {
    int size = sum.size();
    cout << "{";
    for (int i = 0; i < size - 1; ++i) cout << sum[i] << ",";
    if (not sum.empty()) cout << sum[size - 1] ;
    cout << "}" << endl;

}

void backtracking(int k, int j) {  // k = total_sum
    if (k == s and j == n) write();
    else if (j < n) {
        sum.push_back(numbers[j]);
        backtracking(k + numbers[j], j + 1);
        sum.pop_back();
        backtracking(k, j + 1);     
    }
}

int main() {
    cin >> s >> n;
    numbers = VI(n);
    vis = VI (n, false);
    for (int i = 0; i < n; ++i) cin >> numbers[i];
    backtracking(0, 0);
    

}