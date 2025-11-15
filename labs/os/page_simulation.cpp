#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class PagingSystem {
    int frameCount;
    vector<int> frames;
    vector<vector<int>> pageTables;
    int nextReplace = 0;
    int hits = 0, faults = 0;

   public:
    PagingSystem(int processes, int pagesPerProcess, int frames)
        : frameCount(frames),
          frames(frames, -1),
          pageTables(processes, vector<int>(pagesPerProcess, -1)) {
    }

    void accessPage(int pid, int page) {
        cout << "Process " << pid << " accesses page " << page << endl;

        if (pageTables[pid][page] != -1) {
            cout << "Page Hit" << endl;
            hits++;
            printPageTables();
            return;
        }

        cout << "Page Fault" << endl;
        faults++;

        auto it = find(frames.begin(), frames.end(), -1);
        if (it != frames.end()) {
            int idx = it - frames.begin();
            frames[idx] = encode(pid, page);
            pageTables[pid][page] = idx;
            printPageTables();
            return;
        }

        int encoded = frames[nextReplace];
        int oldPid = encoded / 1000000;
        int oldPage = encoded % 1000000;

        pageTables[oldPid][oldPage] = -1;

        frames[nextReplace] = encode(pid, page);
        pageTables[pid][page] = nextReplace;

        nextReplace = (nextReplace + 1) % frameCount;
        printPageTables();
    }

    int encode(int pid, int page) {
        return pid * 1000000 + page;
    }

    void printPageTables() {
        cout << "Frames: ";
        for (int x : frames)
            cout << x << " ";
        cout << endl;

        for (int i = 0; i < pageTables.size(); i++) {
            cout << "PageTable P" << i << ": ";
            for (int x : pageTables[i])
                cout << x << " ";
            cout << endl;
        }
    }

    void stats() {
        cout << "Hits: " << hits << " Faults: " << faults << endl;
    }
};

int main() {
    cout << "Jinmay Jhaveri 241080027" << endl;
    int processes, pages, frames;
    cout << "Enter number of processes: ";
    cin >> processes;
    cout << "Enter pages per process: ";
    cin >> pages;
    cout << "Enter total frames: ";
    cin >> frames;

    PagingSystem ps(processes, pages, frames);

    while (true) {
        cout << "\n1. Access Page\n";
        cout << "2. Show Stats\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        int c;
        cin >> c;

        if (c == 1) {
            int pid, page;
            cout << "Enter process id: ";
            cin >> pid;
            cout << "Enter page number: ";
            cin >> page;
            ps.accessPage(pid, page);
        } else if (c == 2) {
            ps.stats();
        } else if (c == 3) {
            return 0;
        }
    }
}
