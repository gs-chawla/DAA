#include <bits/stdc++.h>
#include "binaryTree.cpp"
using namespace std;

void inorder(node *root, int &cnt)
{
    if (root != NULL)
    {
        inorder(root->left, cnt);
        if (root->left == NULL and root->right == NULL)
        {
            cnt++;
        }
        inorder(root->right, cnt);
    }
}

int noOfLeafNodes(node *root)
{
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}
