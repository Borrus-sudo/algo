#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int currSum = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currSum = max(nums[i], nums[i] + currSum);
        maxSum = max(currSum, maxSum);
    }
    return 0;
}