#include <bits/stdc++.h>
#include "binaryTree.cpp"
using namespace std;

int heightOfBT(node *root)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = heightOfBT(node->left);
    int right = heightOfBT(node->right);

    int ans = max(left, right) + 1;
    return ans;
}