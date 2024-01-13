#include<iostream>
#include<map>

using namespace std;

int main() {
    string s, word;
    map <string, int> m;
    map <string, int>::iterator it;
    while (cin >> s) {
        if (s == "store") {
            cin >> word;
            it = m.find(word);
            if (it != m.end())  ++it->second;
            else m.insert(make_pair(word,1));
        }
        else if (s == "delete") {
             cin >> word;
             it = m.find(word);
             if (it != m.end()) {
                if (it->second == 1) m.erase(it);
                else --it->second;
             }
        }
        else if (s == "minimum?") {
            if (m.empty()) cout << "indefinite minimum" << endl;
            else {
                it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else {
            if (m.empty()) cout << "indefinite maximum" << endl;
            else {
                it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
    }
}