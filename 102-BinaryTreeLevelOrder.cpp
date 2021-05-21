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
    vector<vector<int>> matrix;
    int level = 0;

    void preorder(TreeNode *root, int level)
    {
        if (root != NULL)
        {
            if (matrix.size() == level)
            {
                matrix.push_back({});
            }
            matrix[level].push_back(root->val);
            preorder(root->left, level + 1);
            preorder(root->right, level + 1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        preorder(root, level);
        
        return matrix;
    }
};
