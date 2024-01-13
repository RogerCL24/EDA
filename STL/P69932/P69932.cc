#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        set <int> m;
        int n;
        int seq = 0;
        istringstream iss(s);
        while (iss >> n) m.insert(n);
        bool par = true;
        set <int>::iterator it = m.begin();
        while (it != m.end()) {
            if (it == m.begin()) {
                ++seq;
                par = (*it%2 == 0);
            }
            else if (par and *it%2 != 0) {
                ++seq;
                par = false;
            }
            else if (not par and *it%2 == 0) {
                ++seq;
                par = true;
            }
            ++it;
        }
        cout << seq << endl;

    }
}