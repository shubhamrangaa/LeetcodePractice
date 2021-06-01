
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <set>

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
// RECURSIVE/DFS APPROACH
class Solution
{
public:
    map<int, map<int, multiset<int>>> map;

    void inorder(TreeNode *root, int breadth, int level)
    {
        if (root == NULL)
            return;
        map[breadth][level].insert(root->val); // Inserting values into the multiset
        // most of it will have only one value but for those having multiple nodes at the same coordinate this will have 2 values and my multiset will sort them for me
        inorder(root->right, breadth + 1, level + 1);
        inorder(root->left, breadth - 1, level + 1);
        // the map stores keys in ascending order so interchanging the above statements won't make a difference and we'd still get the same answer (-2, -1. 0 and so on)

        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> list;
        inorder(root, 0, 0);
        for (auto x : map)
        {
            // I'm inside the first map, x = map[breadth] which itself is a map
            vector<int> column;
            for (auto y : x.second)
            // I'm inside the second map y = map[breadth][height] which is a multiset
            {
                column.insert(column.end(), y.second.begin(), y.second.end());
            }
            list.push_back(column);
        }
        return list;
    }
};