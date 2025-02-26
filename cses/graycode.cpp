#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<string> gen(vector<string> span, int currLevel, int toReach)
{
    if (currLevel == toReach)
        return span;
    vector<string> result;
    for (int i = 0; i < span.size(); i++)
    {
        char firstElem = i & 1 ? '1' : '0';
        char secondElem = i & 1 ? '0' : '1';
        result.push_back(span[i] + firstElem);
        result.push_back(span[i] + secondElem);
    }
    return gen(result, ++currLevel, toReach);
}

int main()
{
    int depth;
    cin >> depth;
    vector<string> results = gen({"0", "1"}, 1, depth);
    for (auto str : results)
        cout << str << endl;
    return 0;
}