#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

char operators[] = {'*', '/', '%', '+', '-', '^'};

int opPref(char op)
{
    switch (op)
    {

    case '*':
    case '/':
    case '%':
        return 3;
    case '+':
    case '-':
        return 2;
    case '^':
        return 4;
    }
    return -1;
}
bool isOp(char c)
{
    return find(begin(operators), end(operators), c) != end(operators);
};
bool isLiteral(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

void solve()
{
    string res;
    string input;
    cin >> input;
    stack<char> st;

    for (int i = 0; i < input.size(); i++)
    {
        char curr = input[i];
        if (isLiteral(curr))
        {
            res += curr;
        }
        else if (curr == '(')
        {
            // trouble matey
            st.push('(');
        }
        else if (curr == ')')
        {
            // identical to what we will do in end of string condition
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOp(curr))
        {
            // let's goo!!!!
            int currPref = opPref(curr);
            while (!st.empty())
            {
                char prevOp = st.top();
                int prevPref = opPref(prevOp);
                if (currPref > prevPref)
                    break;
                else
                {
                    st.pop();
                    res += prevOp;
                }
            }
            st.push(curr);
        }
        else
        {
            cout << "Invalid Input" << endl;
            return;
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    cout << res << endl;
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