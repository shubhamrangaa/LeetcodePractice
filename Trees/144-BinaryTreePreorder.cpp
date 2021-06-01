#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <queue>

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
    vector<int> list;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        list.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return list;
    }
};

// ITERATIVE SOLUTION

class SolutionIterative
{
public:
    vector<int> list;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *curr = stack.top();
            list.push_back(curr->val);
            stack.pop();
            if (curr->right)
            {
                stack.push(curr->right);
            }
            if (curr->left)
            {
                stack.push(curr->left);
            }
        }
        return list;
    }
};