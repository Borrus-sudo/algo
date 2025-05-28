#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>

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
    int data;
    Node *left;
    Node *right;
    Node(int data, Node *left = nullptr, Node *right = nullptr) : data(data), left(left), right(right) {}
};

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
        return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}

// non recursive solution
void inorder(Node *root)
{
    // LEFT ROOT RIGHT
    // EDGE CASES :
    stack<Node *> order;
    order.push(root);
    bool fresh = true;
    while (!order.empty())
    {
        Node *top = order.top();
        if (top->left && fresh)
        {
            order.push(top->left);
            continue;
        }
        // no more top->left
        cout << top->data << " ";
        order.pop();
        fresh = false;
        if (top->right)
        {
            order.push(top->right);
            fresh = true;
        }
    }
}

vector<int> postorderTraversal(Node *root)
{
    stack<Node *> order;
    vector<int> ans;
    if (root)
        order.push(root);
    Node *last;
    while (!order.empty())
    {
        Node *top = order.top();
        if (last && (top->left == last || top->right == last))
        {
            ans.push_back(top->data);
            order.pop();
            last = top;
            continue;
        }
        if (top->right)
        {
            order.push(top->right);
        }
        if (top->left)
        {
            order.push(top->left);
        }
        if (top != order.top())
            continue;
        order.pop();
        ans.push_back(top->data);
        last = top;
    }
    return ans;
}

vector<int> preorderTraversal(Node *root)
{
    stack<Node *> order;
    vector<int> ans;
    if (root)
        order.push(root);
    while (!order.empty())
    {
        Node *top = order.top();
        ans.push_back(top->data);
        order.pop();
        if (top->right)
            order.push(top->right);
        if (top->left)
            order.push(top->left);
    }

    return ans;
}

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