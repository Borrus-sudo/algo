#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sl() {
    string s;
    cin >> s;
    int n = s.length();

    bool inf = false;
    for (int i = 0; i < n - 1; ++i) {
        if ((s[i] == '>' || s[i] == '*') && (s[i + 1] == '<' || s[i + 1] == '*')) {
            inf = true;
            break;
        }
    }

    if (inf) {
        cout << -1 << "\n";
    } else {
        int f = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '>') {
                f = i;
                break;
            }
        }

        int l = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '<') {
                l = i;
                break;
            }
        }

        int ml = f;
        int mr = n - 1 - l;

        cout << max(ml, mr) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        sl();
    }
    return 0;
}