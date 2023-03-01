#include "binaryTree.cpp"
#include <bits/stdc++.h>
#include "binaryTree.cpp"
using namespace std;

int heightOfBT(node *root) {
  if (root == NULL) {
    return 0;
  }

  int left = heightOfBT(root->left);
  int right = heightOfBT(root->right);

  int ans = max(left, right) + 1;
  return ans;
}
