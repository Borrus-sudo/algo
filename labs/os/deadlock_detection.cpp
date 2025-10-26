#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Jinmay Jhaveri 241080027 IT" << endl;
    cout << "Enter number of processes: ";
    int n;
    cin >> n;
    cout << "Enter number of resources: ";
    int m;
    cin >> m;

    vector<vector<int>> max_alloc(n, vector<int>(m));
    vector<vector<int>> curr_alloc(n, vector<int>(m));
    vector<int> max_avail(m);
    vector<bool> running(n, true);

    for (int j = 0; j < m; j++) {
        cout << "Enter the current availability of the resource " << (j + 1) << ": ";
        cin >> max_avail[j];
    }

    for (int i = 0; i < n; i++) {
        cout << "For the process " << (i + 1) << endl;
        for (int j = 0; j < m; j++) {
            cout << "    For the resource " << (j + 1) << endl;
            cout << "       Enter max demand of the resource for the process: ";
            cin >> max_alloc[i][j];
            cout << "       Enter amount of allocation of the resource for the process: ";
            cin >> curr_alloc[i][j];
        }
    }

    int finished = 0;
    while (finished != n) {
        bool success = false;
        for (int i = 0; i < n; i++) {
            if (!running[i])
                continue;
            bool satisfy = true;
            for (int j = 0; j < m; j++) {
                int need = max_alloc[i][j] - curr_alloc[i][j];
                if (need > max_avail[j]) {
                    satisfy = false;
                    break;
                }
            }
            if (satisfy) {
                // all the held resources must be cleared
                for (int j = 0; j < m; j++) {
                    max_avail[j] += curr_alloc[i][j];
                }
                running[i] = false;
                success = true;
                finished++;
            }
        }
        if (!success) {
            cout << "Deadlock!" << endl;
            return 0;
        }
    }
    cout << "No deadlock!!" << endl;
    return 0;
}