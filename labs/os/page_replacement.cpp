#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

void fcfs(int frames, vector<int>& procs) {
    vector<int> cache;
    unordered_map<int, bool> pres;
    int misses = 0;
    int hits = 0;
    for (auto pid : procs) {
        cout << "Entered PID: " << pid << endl;
        cout << "Cache: " << cache.size() << " " << endl;
        for (auto spid : cache) {
            cout << "-> " << spid << endl;
        }
        if (pres[pid]) {
            cout << "Hit on the the proc: " << pid << endl;
            hits++;
            continue;
        } else {
            cout << "Miss on the proc: " << pid << endl;
            misses++;
        }
        if (cache.size() >= frames) {
            pres[*cache.begin()] = false;
            cache.erase(cache.begin());
        }
        cache.push_back(pid);
        pres[pid] = true;
    }
    cout << "#Misses " << misses << endl;
    cout << "#Hits " << hits << endl;
}

void lru(int frames, vector<int>& procs) {
    vector<int> cache;
    unordered_map<int, bool> pres;
    unordered_map<int, int> lastIdx;
    int misses = 0;
    int hits = 0;
    for (int i = 0; i < procs.size(); i++) {
        auto pid = procs[i];
        lastIdx[pid] = i;
        cout << "Entered PID: " << pid << endl;
        cout << "Cache: " << cache.size() << " " << endl;
        for (auto spid : cache) {
            cout << "-> " << spid << endl;
        }
        if (pres[pid]) {
            cout << "Hit on the the proc: " << pid << endl;
            hits++;
            continue;
        } else {
            cout << "Miss on the proc: " << pid << endl;
            misses++;
        }
        if (cache.size() >= frames) {
            auto ans = cache.begin();
            for (auto loc = cache.begin() + 1; loc != cache.end(); loc++) {
                if (lastIdx[*ans] > lastIdx[*loc]) {
                    ans = loc;
                }
            }
            pres[*ans] = false;
            cache.erase(ans);
        }
        cache.push_back(pid);
        pres[pid] = true;
    }
    cout << "#Misses " << misses << endl;
    cout << "#Hits " << hits << endl;
}

void optimal(int frames, vector<int>& procs) {
    unordered_map<int, bool> pres;
    vector<int> cache;
    int misses = 0;
    int hits = 0;
    for (int i = 0; i < procs.size(); i++) {
        int pid = procs[i];
        cout << "Entered PID: " << pid << endl;
        cout << "Cache: " << cache.size() << " " << endl;
        for (auto spid : cache)
            cout << "-> " << spid << endl;

        if (pres[pid]) {
            cout << "Hit on the proc: " << pid << endl;
            hits++;
            continue;
        } else {
            cout << "Miss on the proc: " << pid << endl;
            misses++;
        }

        if (cache.size() >= frames) {
            unordered_map<int, int> freq;
            for (auto spid : cache)
                freq[spid] = 0;
            for (int j = i + 1; j < procs.size(); j++) {
                if (freq.find(procs[j]) != freq.end())
                    freq[procs[j]]++;
            }
            int removeIdx = 0;
            for (int k = 1; k < cache.size(); k++) {
                int a = cache[removeIdx];
                int b = cache[k];
                if (freq[a] > freq[b])
                    removeIdx = k;
            }
            pres[cache[removeIdx]] = false;
            cache.erase(cache.begin() + removeIdx);
        }

        pres[pid] = true;
        cache.push_back(pid);
    }

    cout << "#Misses " << misses << endl;
    cout << "#Hits " << hits << endl;
}

int main() {
    cout << "Jinmay Jhaveri 241080027" << endl;
    cout << "Enter cache frame sizes: ";
    int frames;
    cin >> frames;
    cout << "Enter number of processes: ";
    int n;
    cin >> n;
    vector<int> procs(n);
    for (int& num : procs) {
        cout << "Enter pid: ";
        cin >> num;
    }

    while (true) {
        cout << endl;
        cout << "1. FCFS" << endl;
        cout << "2. LRU" << endl;
        cout << "3. OPTIMAL" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        int c;
        cin >> c;

        if (c == 1)
            fcfs(frames, procs);
        else if (c == 2)
            lru(frames, procs);
        else if (c == 3)
            optimal(frames, procs);
        else if (c == 4)
            return 0;
        else
            cout << "Invalid choice" << endl;
    }
    return 0;
}