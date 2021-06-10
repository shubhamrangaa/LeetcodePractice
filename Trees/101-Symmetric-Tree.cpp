#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        else if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isMirror(root->left, root->right);
    }
};