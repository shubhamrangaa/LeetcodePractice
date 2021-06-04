#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// FIRST APPROACH
// Store preorder traversals of both trees and compare the vectors
// Tried using inorder traversal but that isn't true for all cases!
class Solution
{
public:
    int flag = 0;
    vector<int> listP;
    vector<int> listQ;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            flag ? listQ.push_back(0) : listP.push_back(0);
            return;
        }
        flag ? listQ.push_back(root->val) : listP.push_back(root->val);
        inorder(root->left);
        inorder(root->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        inorder(p);
        flag = 1;
        inorder(q);
        if (listP == listQ)
            return true;
        else
            return false;
    }
};

// SECOND/CLEANER APPROACH
// Unbelievable simplicity of the code, traversing two trees at the same time as soon as two nodes differ we return false!
class SolutionClean
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL || q == NULL)
            return (p == q);
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};