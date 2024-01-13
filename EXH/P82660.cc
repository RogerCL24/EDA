#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> VI;

int s, n;
VI numbers, sum;

void write() {
    int size = sum.size();
    cout << "{";
    for (int i = 0; i < size - 1; ++i) cout << sum[i] << ","; 
    if (not sum.empty()) cout << sum[size - 1];
    cout << "}" << endl;
}

void backtracking(int k, int i, bool& found) {
    if (i == n and k == s) {
        write();
        found = true;
    }
    else if (i < n) {
        sum.push_back(numbers[i]);
        backtracking(k + numbers[i], i + 1, found);
        if (not found) {
            sum.pop_back();
            backtracking(k, i + 1, found);
        }
    }
}

int main() {
    cin >> s >> n;
    numbers = VI (n);
    for (int i = 0; i < n; ++i) cin >> numbers[i];
    sort(numbers.begin(), numbers.end(), greater<int>());
    bool found = false;
    backtracking(0,0, found);
    if (not found) cout << "no solution" << endl;

}

