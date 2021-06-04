#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

map<int, pair<int, int>>
    hashMap;

void helper(Node *root, int breadth, int level)
{
    if (root == NULL)
        return;

    if (!hashMap[breadth].second || level > hashMap[breadth].first)
    {
        hashMap[breadth].first = level;
        hashMap[breadth].second = root->data;
    }
    else if (level == hashMap[breadth].first)
    {
        hashMap[breadth].first = level;
        hashMap[breadth].second = root->data;
    }

    helper(root->left, breadth - 1, level + 1);
    helper(root->right, breadth + 1, level + 1);
}

//Function to return a list containing the bottom view of the given tree.
vector<int> bottomView(Node *root)
{
    // Your Code Here
    vector<int> list;
    helper(root, 0, 0);

    for (auto x : hashMap)
    {
        list.push_back(x.second.second);
    }
    return list;
}