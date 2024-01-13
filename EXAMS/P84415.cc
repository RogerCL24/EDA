#include <iostream>
#include <map>

using namespace std;

int main() {
    string token;
    map <string, int> bag;
    while (cin >> token) {
        map<string,int>::iterator it;
        if (token == "minimum?") {
            if (not bag.empty()) {
                it = bag.begin();
                cout << "minimum: " << it->first  << ", " << it->second << " time(s)" << endl;
            }
            else cout << "indefinite minimum" << endl;
        }
        else if (token == "store") {
            string p;
            cin >> p;
            it = bag.find(p);
            if (it != bag.end()) ++it->second;
            else bag.insert(make_pair(p, 1));
        }
        else if (token == "delete") {
            string p;
            cin >> p;
            it = bag.find(p);
            if (it != bag.end()) {
                --it->second;
                if (it->second == 0) it = bag.erase(it);
            }
        }
        else if (token == "maximum?") {
            if (not bag.empty()) {
                it = bag.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
            else cout << "indefinite maximum" << endl;
        }
    }
}