#include "binaryTree.cpp"
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
  int height(node *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
  }

public:
  pair<bool, int> isBalanced(node *root)
  {
    if (root == NULL)
    {
      pair<bool, int> p = make_pair(true, 0);
      return p;
    }

    pair<bool, int> left = isBalanced(root->left);
    pair<bool, int> right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (left.first and right.first and diff)
    {
      ans.first = true;
    }
    else
    {
      ans.first = false;
    }
    return ans;
  }
};