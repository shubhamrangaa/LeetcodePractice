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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        list.push_back(root->val);
        return list;
    }
};

// ITERATIVE APPROACH

class SolutionIterative
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        // two stacks one for the traversal and one to store values as we traverse
        stack<TreeNode *> stack, stackMain;
        vector<int> list;
        stack.push(root);
        while (!stack.empty()) //tree traversal
        {
            TreeNode *curr = stack.top();
            stack.pop();
            stackMain.push(curr);
            if (curr->left)
            {
                stack.push(curr->left);
            }
            if (curr->right)
            {
                stack.push(curr->right);
            }
        }
        while (!stackMain.empty()) // popping nodes in postorder
        {
            list.push_back(stackMain.top()->val);
            stackMain.pop();
        }
        return list;
    }
};