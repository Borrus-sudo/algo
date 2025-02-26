#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename S, typename T>
void smax(S &a, const T &b)
{
    if (a < b)
        a = b;
};

template <typename S, typename T>
void smin(S &a, const T &b)
{
    if (a > b)
        a = b;
};

using ll = long long;
#define all(x) (x).begin, (x).end()

void towerOfHanoi(int disk, int from_rod, int aux_rod, int to_rod)
{
    if (disk == 0)
        return;
    towerOfHanoi(disk - 1, from_rod, to_rod, aux_rod);
    cout << from_rod << " " << to_rod << endl;
    towerOfHanoi(disk - 1, aux_rod, from_rod, to_rod);
}

void solve()
{
    // write your code here
    int disk;
    cin >> disk;
    cout << ((1 << disk) - 1) << endl;
    towerOfHanoi(disk, 1, 2, 3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin >> TC;

    while (TC--)
        solve();

    return 0;
}