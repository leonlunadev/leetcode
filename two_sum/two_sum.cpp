#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
private:
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end())
            {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};

void runTestCases()

{
    Solution sol;

    {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        vector<int> expected = {0, 1};
        vector<int> result = sol.twoSum(nums, target);
        assert(result == expected);
    }

    {
        vector<int> nums = {3, 2, 4};
        int target = 6;
        vector<int> expected = {1, 2};
        vector<int> result = sol.twoSum(nums, target);
        assert(result == expected);
    }

    {
        vector<int> nums = {3, 3};
        int target = 6;
        vector<int> expected = {0, 1};
        vector<int> result = sol.twoSum(nums, target);
        assert(result == expected);
    }
}

int main()
{
    runTestCases();
    cout << "All test cases passed!" << endl;
    return 0;
}