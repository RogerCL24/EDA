#include<iostream>
#include<map>

using namespace std;

const int EDGE = 100000000;

int main() {
    int x, y, n;
    map<int,int> m;
    bool kharij = false;
    map<int,int>::iterator it;
    while (cin >> x >> y >> n) {
        int counter = 0;
        m.insert(make_pair(n, 1));
        while (not kharij and n <= EDGE) {
            if (n%2 == 0) n = n/2 + x;
            else n = n*3 + y;
            it = m.find(n);
            if (it == m.end()) m.insert(make_pair(n, 1));
            
            else if (it->second == 1){
                ++it->second;
                ++counter;
            }
            else kharij = true;
        }
        if (not kharij) cout << n << endl;
        else cout << counter << endl;
        m.clear();
        kharij = false;
    }
}