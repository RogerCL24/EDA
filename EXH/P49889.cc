#include <iostream>
#include <vector>

using namespace std;

typedef vector <char> VC;
typedef vector<int> VI;

int n;
VC vowel, consonant, word;
VI visvoc, viscon;

void word_perm(int i) {
    if (i == 2*n)  {
        for (int j = 0; j < 2*n; ++j) cout << word[j];
        cout << endl;
    }
    else {
        for (int j = 0; j < n; ++j) {
            if (i%2 == 0 and not viscon[j]) {
                word[i] = consonant[j];
                viscon[j] = true;
                word_perm(i + 1);
                viscon[j] = false;
            }
            else if (i%2 != 0 and not visvoc[j]){
                word[i] =  vowel[j];
                visvoc[j] = true;
                word_perm(i + 1);
                visvoc[j] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    vowel = consonant = VC(n);
    word = VC (2*n);
    visvoc = viscon = VI (n, false);
    for (int i = 0; i < n; ++i) cin >> consonant[i];
    for (int i = 0; i < n; ++i) cin >> vowel[i];

    word_perm(0);

    
}