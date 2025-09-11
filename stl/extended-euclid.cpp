#include <algorithm>
#include <iostream>
using namespace std;

// invariant: a >= b
pair<int, int> extendedEuclid(int a, int b, pair<int, int> s = {1, 0}, pair<int, int> t = {0, 1})
{

    // a*s + b*t = gcd(a, b) Bezout's Identity guarantess a solution exists to this linear diophantine equation; a,s,b,t belonging to Integers
    if (b == 0)
    {
        return s;
    }
    int q = a / b;
    int a_1 = b;
    int b_1 = a % b;
    s.first = s.first - q * t.first;
    s.second = s.second - q * t.second;
    return extendedEuclid(a_1, b_1, t, s);
    // s1.fir
}

int main()
{
    auto [s, t] = extendedEuclid(123, 45);
    cout << s << " " << t << endl;
    return 0;
}