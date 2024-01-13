#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

struct rock {
    double x;
    double y;
    double r;
};

typedef vector <rock> VR;
typedef pair <rock, int> Par;

bool can_jump(const rock& r1, const rock& r2, double d) {
    double x = (r2.x - r1.x) * (r2.x - r1.x);
    double y = (r2.y - r1.y) * (r2.y - r1.y);
    double dist = sqrt(x + y);                  //hipotenusa
    dist = dist - r1.r - r2.r;
    return dist < d;    
}

int bfs (const VR& rocks, double d, int n) {
    vector<bool> visited (n, false);
    queue <Par> q;
    q.push(Par(rocks[0], 0));
    vector <int> steps (n , -1);
    steps[0] = 0;
    while (not q.empty()) {
        int index = q.front().second;
        rock r = q.front().first;
        q.pop();
        if (not visited[index]) {
            visited[index] = true;
            for (int i = 0; i < n; ++i) {
                if (can_jump(r, rocks[i], d) and steps[i] == -1) {
                    q.push(Par(rocks[i], i));
                    steps[i] = steps[index] + 1;
                    if (i == n - 1) return steps[i];

                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    double  d;
    while (cin >> n >> d) {
        VR rocks (n);
        for (int i = 0; i < n; ++i) cin >> rocks[i].x >> rocks[i].y >> rocks[i].r;
        int jump = bfs(rocks, d, n);
        if (jump == -1) cout << "Xof!" << endl;
        else cout << jump << endl;
        
    }
}