#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

void write_sol(VI& rosers, VI& sol_parcial, bool consec, int idx) {
    if (idx == sol_parcial.size()) {
        if (consec)  {
            for (int x : sol_parcial) cout << x;
            cout << endl;
        }
    }
    else {
        for (int i = 1; i <= 3; ++i) {
            if (rosers[i] > 0 and (not consec or idx == 0 or sol_parcial[idx - 1] != i)) {
                sol_parcial[idx] = i;
                --rosers[i];
                write_sol(rosers, sol_parcial, consec or (idx > 0 and sol_parcial[idx - 1] == i), idx + 1);
                ++rosers[i];
            }
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        VI sol_parcial(3*n);
        VI rosers(4,n);                         //rosers[0] no utilitzat
        write_sol(rosers, sol_parcial, false, 0);
        cout << string(10,'*') << endl;
    }

}