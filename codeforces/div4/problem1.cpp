// PASS!
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int lines;
    cin >> lines;
    while (lines-- > 0) {
        string input;
        cin >> input;
        input.replace(input.size() - 2, 2, "i");
        cout << input << endl;
    }
        return 0;
}