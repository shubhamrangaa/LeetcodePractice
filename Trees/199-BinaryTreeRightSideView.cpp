#include <bits/stdc++.h>    

// Concept
// Every time you visit a node you check if its the last node in the queue in which we store the nodes left to right, if its the last node, it will be in the right side view so we push it in the list
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> list = {};
        if (root == NULL)
            return list;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = queue.front();
                queue.pop();
                if (i == size - 1)
                    list.push_back(curr->val);
                if (curr->left)
                    queue.push(curr->left);
                if (curr->right)
                    queue.push(curr->right);
            }
        }
        return list;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}