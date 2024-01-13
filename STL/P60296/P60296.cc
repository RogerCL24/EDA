#include <iostream> 
#include <map>
#include <set>
#include <utility>

using namespace std;

struct comp {
    bool operator() (const pair <string, int>& a, const pair <string, int>& b) const { 
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};


int main() {
    map <string, pair<int, bool>> reg;
    map <string, pair<int, bool>>::iterator it;    
    string command, j1,j2;  
    while (cin >> command) {
        if (command == "LOGIN") {
            cin >> j1;
            it = reg.find(j1);
            if (it == reg.end()) reg.insert(make_pair(j1,make_pair(1200,true)));
            else if (not it -> second.second) it -> second.second = true;    
        }
        else if (command == "PLAY") {
            map <string, pair<int,bool>>::iterator it2;
            cin >> j1 >> j2;
            it = reg.find(j1);
            it2 = reg.find(j2);
            if (it->second.second and it2->second.second) {
                it->second.first += 10;
                it2->second.first -= 10;
                if (it2->second.first < 1200) it2->second.first = 1200;  
            }
            else cout << "jugador(s) no connectat(s)" << endl;
        }
        else if (command == "GET_ELO") {
            cin >> j1;
            cout << j1 << ' ' << reg[j1].first << endl;
        }

        else {
            cin >> j1;
            it = reg.find(j1);
            if (it->second.second) it->second.second = false;
        }

    }

    cout << endl << "RANKING" << endl;

    set <pair <string, int>, comp> s;
    for (pair <string, pair <int, bool> > p : reg) s.insert(make_pair(p.first,p.second.first));
    for (pair <string, int> it3: s) cout << it3.first << ' ' << it3.second << endl;

}