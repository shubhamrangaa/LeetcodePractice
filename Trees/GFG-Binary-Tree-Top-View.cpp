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
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.

    map<int, pair<int, int>> hashMap; // map to store breadth, height and node value
    vector<int> list;
    void help(Node *root, int breadth, int level)
    {
        if (root == NULL)
            return;

        // check if for the given breadth, is there a node already present,
        // If No, add node to map
        // If YES, check if the level of that node is greater than current nodes level
        // if yes replace else move on
        if (!hashMap[breadth].second || hashMap[breadth].first > level)
        {
            hashMap[breadth].first = level;
            hashMap[breadth].second = root->data;
        }
        // finally we keep on storing only the top most nodes at every breadth or horizontal distance
        help(root->left, breadth - 1, level + 1);
        help(root->right, breadth + 1, level + 1);
        return;
    }
    vector<int> topView(Node *root)
    {
        //basic preorder traversal while maintaining level and breadth
        // the traversal type doesn't really matter cause map key values are stored in order
        help(root, 0, 0);
        for (auto x : hashMap)
        {
            list.push_back(x.second.second);
        }
        return list;
    }
};
