#include <iostream>
#include <set>
#include <string>

using namespace std;

struct comp{
	bool operator() (const string& a, const string& b) const {
		if (a.size() < b.size()) return true;
		else if (a.size() > b.size()) return false;
		else return (a < b);
	}
};

int main() {
	string s;
	int contador = 1;
	set<string>::iterator it1;
	set<string, comp>::iterator it2;
	while (s != "QUIT") {
		set<string> shas;
		set<string, comp> shad;
		while (cin >> s and s != "END" and s != "QUIT") {
			it1 = shas.find(s);
			if (it1 != shas.end()) { //está en shas
				shas.erase(it1);
				shad.insert(s);
			}
			else { //no está en shas
				it2 = shad.find(s);
				if (it2 != shad.end()) { //está en shad
					shad.erase(it2);
					shas.insert(s);
				}
				else { //no está en shad
					shas.insert(s);
				}
			}
		}
		if (contador > 1) cout << endl;
		//sacar por pantalla los resultados
		cout << "GAME #" << contador << endl;
		cout << "HAS:" << endl;
		if (!shas.empty()) {
			for (it1=shas.begin(); it1 != shas.end(); ++it1) {
				cout << *it1 << endl;
			}
		}
		cout << endl;
		cout << "HAD:" << endl;
		if (!shad.empty()) {
			for (it2=shad.begin(); it2 != shad.end(); ++it2) {
				cout << *it2 << endl;
			}
		} 
		//
		++contador;
	}
}