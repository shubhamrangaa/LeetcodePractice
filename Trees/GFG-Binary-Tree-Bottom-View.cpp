#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> bottomView(Node *root)
{
    queue<pair<Node *, int>> queue; //queue storing the node and its breadth
    map<int, int> hashMap;          // map storing breadth and the bottom most node value for that breadth
    vector<int> list;
    queue.push({root, 0});
    while (!queue.empty())
    {
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            auto curr = queue.front();
            queue.pop();
            int breadth = curr.second;
            hashMap[breadth] = curr.first->data;
            if (curr.first->left)
                queue.push({curr.first->left, breadth - 1});
            if (curr.first->right)
                queue.push({curr.first->right, breadth + 1});
        }
    }

    for (auto x : hashMap)
    {
        list.push_back(x.second);
    }
    return list;
}
