/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector < vector<int> matrix;
    void revLevel(TreeNode *root, int level)
    {
        if (root == NULL)
            return;
        revLevel(root->left, level + 1);
        revLevel(root->right, level + 1);
        matrix[level].push_back(root->val);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        revLevel(root, 0);
        return matrix;
    }
};