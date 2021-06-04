#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// RECURSIVE APPROACH
// 1. Visit left child
// 2. Visit root
// 3. Visit right child
class Solution
{
public:
    vector<int> list;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        inorderTraversal(root->left);
        list.push_back(root->val);
        inorderTraversal(root->right);
        return list;
    }
};

// ITERATIVE APPROACH

class SolutionIterative
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> list;
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        while (curr != NULL || !stack.empty())
        {
            if (curr != NULL)
            {
                stack.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stack.top();
                stack.pop();
                list.push_back(curr->val);
                curr = curr->right;
            }
        }
        return list;
    }
};