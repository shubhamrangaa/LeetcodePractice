#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    while (m && n)
    {
        nums1[m + n] = nums1[m - 1] > nums2[n - 1] ? nums1[--m] : nums2[--n];
    }
    while (n)
    {
        nums1[m + n] = nums2[--n];
    }
}

int main()
{
    int m, n;
    vector<int> nums1, nums2;
    nums1 = {1, 2, 3, 0, 0, 0}, m = 3, nums2 = {2, 5, 6}, n = 3;
    merge(nums1, m, nums2, n);
    return 0;
}