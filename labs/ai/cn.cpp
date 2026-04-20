#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int data[20], hamming[30];
    int m, r = 0;
    cout << "Enter number of data bits: ";
    cin >> m;
    cout << "Enter data bits:\n";
    for (int i = 1; i <= m; i++)
        cin >> data[i];

    while (pow(2, r) < (m + r + 1))
        r++;
    int n = m + r;

    int j = 1;
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0)
            hamming[i] = 0;
        else
            hamming[i] = data[j++];
    }
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;
        for (int j = pos; j <= n; j++) {
            if (j & pos)
                parity ^= hamming[j];
        }

        hamming[pos] = parity;
    }
    cout << "Hamming Code: ";
    for (int i = 1; i <= n; i++)
        cout << hamming[i] << " ";
    cout << endl;

    cout << "Enter received code:\n";
    for (int i = 1; i <= n; i++)
        cin >> hamming[i];
    int error = 0;
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;
        for (int j = pos; j <= n; j++) {
            if (j & pos)
                parity ^= hamming[j];
        }
        if (parity)
            error += pos;
    }
    if (error == 0)
        cout << "No error detected\n"_;
    else {
        cout << "Error at position: " << error << endl;
        hamming[error] ^= 1;
        cout << "Corrected code: ";
        for (int i = 1; i <= n; i++)
            cout << hamming[i] << " ";
    }
    return 0;
}