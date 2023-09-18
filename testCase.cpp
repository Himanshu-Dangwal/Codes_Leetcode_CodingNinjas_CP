#include "bits/stdc++.h"
using namespace std;
bool hasNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> numIndexMap;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (numIndexMap.find(nums[i]) != numIndexMap.end() && i - numIndexMap[nums[i]] <= k)
        {
            return true;
        }
        numIndexMap[nums[i]] = i;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    if (hasNearbyDuplicate(nums, k))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
