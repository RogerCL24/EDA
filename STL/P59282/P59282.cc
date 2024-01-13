#include <iostream>
#include <string>
#include <map>
using namespace std;


int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    string s;
    int aver = 0;
    int averc = 0;
    map <int,int> m;
    map <int,int>::iterator it;
    while (cin >> s) {
        if (s == "number") {
            int n;
            cin >> n;
            it = m.find(n);
            if (it != m.end()) ++it->second;
            else m.insert(make_pair(n,1));
            ++averc;
            aver += n;

        }
        else if (m.begin() != m.end()) {
           --averc;
           aver -= m.begin() -> first;
           --m.begin() -> second;
           if (m.begin()-> second == 0) it = m.erase(m.begin());

        }
        if (m.size() == 0) cout << "no elements" << endl;
        else cout << "minimum: " << m.begin()->first << ", maximum: " << (--m.end())->first << ", average: " << aver / double(averc) << endl;

        }
}
