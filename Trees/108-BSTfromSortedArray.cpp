#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *createMinimalBST(vector<int> array, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(array[mid]);
        root->left = createMinimalBST(array, start, mid - 1);
        root->right = createMinimalBST(array, mid + 1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return createMinimalBST(nums, 0, nums.size() - 1);
    }
};
