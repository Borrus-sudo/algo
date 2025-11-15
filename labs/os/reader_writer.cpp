#include <iostream>
#include <vector>
using namespace std;

class Semaphore {
    int counter;

   public:
    Semaphore(int counter) : counter(counter) {};
    // must be atomic ofc
    bool wait() {
        counter--;
        if (counter < 0) {
            // thread would sleep
            return false;
        } else {
            return true;
        }
    }
    // must be atomic ofc
    void signal() {
        counter++;
        if (counter >= 0) {
            // wake up one sleeping thread
        }
    };
};

class ReaderWriter {
    Semaphore mutex{1};
    Semaphore wrt{1};

    int read_count = 0;
    int shared_data = 0;

   public:
    void reader() {
        bool m = mutex.wait();
        if (!m) {
            cout << "Reader blocked on mutex\n";
            return;
        }

        read_count++;
        if (read_count == 1) {
            bool w = wrt.wait();
            if (!w) {
                cout << "Reader blocked writers\n";
            }
        }

        mutex.signal();

        cout << "Reader reads: " << shared_data << endl;

        mutex.wait();
        read_count--;
        if (read_count == 0) {
            wrt.signal();
        }
        mutex.signal();
    }

    void writer(int x) {
        bool w = wrt.wait();
        if (!w) {
            cout << "Writer blocked (another writer/reader active)\n";
            return;
        }

        cout << "Writer writes: " << x << endl;
        shared_data = x;

        wrt.signal();
    }

    void printData() {
        cout << "Shared Data = " << shared_data << endl;
    }
};

int main() {
    cout << "Jinmay Jhaveri 241080027" << endl;

    ReaderWriter rw;
    while (true) {
        cout << "\n1. Reader\n";
        cout << "2. Writer\n";
        cout << "3. Print Shared Data\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        int c;
        cin >> c;

        if (c == 1) {
            rw.reader();
        } else if (c == 2) {
            cout << "Enter value to write: ";
            int x;
            cin >> x;
            rw.writer(x);
        } else if (c == 3) {
            rw.printData();
        } else if (c == 4) {
            return 0;
        }
    }
}
