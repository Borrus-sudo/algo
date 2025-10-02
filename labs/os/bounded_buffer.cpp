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
            // this is a problem!!!
            // suspend and sleep
            return false;
        } else {
            return true;
        }
    }
    // must be atomic ofc
    void signal() {
        counter++;
        if (counter <= 0) {
            // we gotta put one slept thread back to life
        }
    };
};

class BoundedBuffer {
    Semaphore full;      // no of empty slots
    Semaphore empty{0};  // no of full slots
    Semaphore lock{1};
    int top = 0;

   public:
    vector<int> buffer;
    BoundedBuffer(int N) : full(N), buffer(N) {};
    void add(int elem) {
        bool success = full.wait();  // there are some spots
        if (!success) {
            cout << "Buffer is full" << endl;
            return;
        }
        lock.wait();
        cout << "Producer produces: " << elem << endl;
        buffer[top++] = elem;
        lock.signal();
        empty.signal();
    };
    void remove() {
        bool success = empty.wait();
        if (!success) {
            cout << "Buffer is empty" << endl;
            return;
        }
        lock.wait();
        cout << "Consumer consumes: " << buffer[--top] << endl;
        lock.signal();
        full.signal();
    };
    void print() {
        cout << "Current Buffer: ";
        for (int i = 0; i < top; i++) {
            cout << buffer[i] << " ";
        }
        cout << endl;
    };
};

int main() {
    int N;
    cout << "Enter your buffer size: ";
    cin >> N;
    BoundedBuffer buffer(N);
    while (true) {
        cout << "1. Producer" << endl;
        cout << "2. Consumer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element: ";
                int elem;
                cin >> elem;
                buffer.add(elem);
                buffer.print();
                break;
            case 2:
                buffer.remove();
                buffer.print();
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}