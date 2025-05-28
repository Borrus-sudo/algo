#include <iostream>
#include <vector>
#include <string>
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

char operators[] = {'*', '/', '%', '+', '-'};

bool isOperator(char c)
{
    for (char op : operators)
    {
        if (op == c)
            return true;
    }
    return false;
}

bool isLiteral(char c)
{
    return (c >= '0' && c <= '9');
}

void solve()
{
    string input;
    cin >> input;
    stack<char> eval;
    int res = 0;
    // we eval
    for (int i = input.size() - 1; i >= 0; i--)
    {
        char token = input[i];
        if (isLiteral(token))
        {
            eval.push(token);
        }
        else if (isOperator(token))
        {
            int operand1 = eval.top() - '0';
            eval.pop();
            int operand2 = eval.top() - '0';
            eval.pop();
            switch (token)
            {
            case '*':
                res += (operand1 * operand2);
                break;
            case '/':
                res += (operand1 / operand2);
                break;
            case '-':
                res += (operand1 / operand2);
                break;
            case '+':
                res += (operand1 / operand2);
                break;
            }
        }
    }
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