#include <bits/stdc++.h>
#include "binaryTree.cpp"
using namespace std;
class Solution
{
public:
    void traverseLeft(node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL and root->right == NULL)
        {
            return;
        }
        ans.push_back(root->data);
        if (root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    void traverseLeaf(node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL and root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
    }

    void traverseRight(node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL and root->right == NULL)
        {
            return;
        }
        if (root->right)
        {
            traverseRight(root->right, ans);
        }
        else
            traverseRight(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundary(node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        ans.push_back(root->data);

        traverseLeft(root->left, ans);

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        traverseRight(root->right, ans);

        return ans;
    }
};
