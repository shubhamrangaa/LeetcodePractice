#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// FIRST APPROACH
// find the sum of heights of left and right subtrees for every node return whatever was highest

class Solution
{
public:
    int diameter = 0;
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
    void help(TreeNode *root)
    {
        if (root == NULL)
            return;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if (diameter < left + right)
            diameter = left + right;
        help(root->left);
        help(root->right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        help(root);
        return diameter;
    }
};

// SECOND/CLEANER APPROACH
// Same logic cleaner code

class SolutionClean
{
public:
    // could have declared diameter globally to clean even further
    int help(TreeNode *root, int &diameter) //passing diameter by reference and not by value!
    {
        if (root == NULL)
            return 0;
        int left = help(root->left, diameter);
        int right = help(root->right, diameter);
        diameter = max(diameter, left + right);
        return (max(left, right) + 1);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        help(root, diameter);
        return diameter;
    }
};
