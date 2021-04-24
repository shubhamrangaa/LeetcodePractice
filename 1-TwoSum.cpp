#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> pair; // could use unordered_map
        for (int i = 0; i < nums.size(); i++)
        {
            if (pair.find(target - nums[i]) != pair.end())
            {
                return {i, pair[target - nums[i]]};
            }
            pair[nums[i]] = i;
        }
        return {};
    }
};