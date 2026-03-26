#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<string> strips(k);
        for (int i = 0; i < k; i++) {
            cin >> strips[i];
        }

        // A[i] = bitmask of allowed characters at position i
        vector<int> A(n, 0);
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < k; j++) {
                mask |= (1 << (strips[j][i] - 'a'));
            }
            A[i] = mask;
        }

        // Collect all divisors of n
        vector<int> divisors;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d * d != n)
                    divisors.push_back(n / d);
            }
        }
        sort(divisors.begin(), divisors.end());

        int best_d = n;
        vector<int> chosen;

        // Find smallest valid period
        for (int d : divisors) {
            bool ok = true;
            vector<int> cur(d, (1 << 26) - 1);

            for (int r = 0; r < d; r++) {
                for (int pos = r; pos < n; pos += d) {
                    cur[r] &= A[pos];
                }
                if (cur[r] == 0) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                best_d = d;
                chosen = cur;
                break;
            }
        }

        // Build the answer
        string ans(n, 'a');
        for (int r = 0; r < best_d; r++) {
            int letter = 0;
            for (int c = 0; c < 26; c++) {
                if (chosen[r] & (1 << c)) {
                    letter = c;
                    break;
                }
            }
            for (int pos = r; pos < n; pos += best_d) {
                ans[pos] = char('a' + letter);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
