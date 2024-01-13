#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

void top_sort(map<string, int>& num, map<int, string>& str, vector<vector<int>>& graf, vector<int>& grade) {
    priority_queue <string, vector <string>, greater <string> > q;      //grado de entrada 0
    map <string, int>::const_iterator it = num.begin();
    while (it != num.end()) {
        if (grade[it->second] == 0) q.push(it->first);
        ++it;
    }

    queue <string> aux;
    while (not q.empty()) {
        string s = q.top();
        q.pop();
        aux.push(s);
        for (int v : graf[num[s]]) {
            if (--grade[v] == 0) q.push(str[v]);
        }
    }

    int n = graf.size();
    if (aux.size() != n) cout << "NO VALID ORDERING" << endl;
    else {
        while (not aux.empty()) {
            cout << aux.front();
            aux.pop();
        }
        cout << endl;
    }
}

int main() {
    int n;
    string inp;
    while (cin >> n) {
        map <string, int> num;
        map <int, string> str;
        for (int i = 0; i < n; ++i) {
            cin >> inp;
            num.insert(make_pair(inp, i));
            str.insert(make_pair(i, inp));
        }
        int m;
        cin >> m;
        vector <int> grade(n, 0);
        vector <vector <int>> graf(n);
        for (int i = 0; i < m; ++i) {
            string u, v;
            cin >> u >> v;
            graf[num[u]].push_back(num[v]);
            ++grade[num[v]];
        }

        top_sort(num, str, graf, grade);

    }
}