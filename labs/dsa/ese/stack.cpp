#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

#define all(x) (x).begin, (x).end()
#define dbg(x) cout << "Line(" << __LINE__ << ") -> " << #x << " = " << (x) << endl;

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
const int m = 1e9 + 7;

struct Node
{
    int val;
    Node *prev;
    Node(int val, Node *prev = nullptr) : val(val), prev(prev) {};
};

class Stack
{
    Node *head;
    Stack(int val)
    {
        head = new Node(val);
    }
    bool isEmpty()
    {
        return head == nullptr;
    }
    void push(int val)
    {
        Node *newElem = new Node(val);
        newElem->prev = head;
        head = newElem;
    };
    int top()
    {
        if (isEmpty())
            throw "Stack Empty";
        return head->val;
    };
    void pop()
    {
        if (isEmpty())
            throw "Stack Empty";
        Node *temp = head;
        head = head->prev;
        delete temp;
    }
};

void solve()
{
    // write your code here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    // cin >> TC;

    while (TC--)
        solve();

    return 0;
}