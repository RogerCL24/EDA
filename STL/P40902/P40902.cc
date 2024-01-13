#include<iostream>
#include<map>

using namespace std;

int main() {
    map <string,int> m;
    string name, op;
    int n;
    map<string,int>::iterator it;
    while (cin >> name >> op) {
        it = m.find(name);
        if (op == "enters") {
            if (it == m.end()) m.insert(make_pair(name,0));
            else cout << name << " is already in the casino" << endl;
        }
        else if (op == "wins") {
            cin >> n;
            if (it != m.end()) it->second += n;
            else cout << name << " is not in the casino" << endl;
        }
        else {
            if (it == m.end()) cout << name << " is not in the casino" << endl;
            else {
                cout << it -> first << " has won " << it -> second << endl;
                m.erase(it);
            }
        }
    }

    cout << "----------" << endl;
    it = m.begin();
    while (it != m.end()) {
        cout << it -> first << " is winning " << it -> second << endl;
        ++it; 
    }
}