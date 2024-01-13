#include<iostream>
#include <queue>

using namespace std;

int main() {
    char x;
    int n;
    priority_queue <int> q;

    //greater number is on the top of the queue
    while (cin >> x) {
        if (x == 'S') {
            cin >> n;
            q.push(n);
        }
        else if (q.empty()) {
           if (x == 'I' or x == 'D') cin >> n;
           cout << "error!" << endl;
        }
        else if (x == 'A') cout << q.top() << endl;
        else if (x == 'R') q.pop();
        else {
            cin >> n;
            if (x == 'I') n += q.top();
            else n = q.top() - n;
            q.pop();
            q.push(n);
        }
    }
}