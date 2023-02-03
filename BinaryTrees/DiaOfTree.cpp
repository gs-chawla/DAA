#include "binaryTree.cpp"

#include <bits/stdc++.h>
#include <utility>

using namespace std;

int height(node *root) {
  if (root == NULL) {
    return 0;
  }
  return max(height(root->left), height(root->right)) + 1;
}

pair<int, int> diaTree(node *root) {
  if (root == NULL) {
    pair<int, int> p = make_pair(0, 0);
    return p;
  }
  pair<int, int> left = diaTree(root->left);
  pair<int, int> right = diaTree(root->right);

  int op1 = left.first;
  int op2 = right.first;
  int op3 = left.second + right.second + 1;

  //   int op1 = diaTree(root->left);
  //   int op2 = diaTree(root->right);
  //   int op3 = height(root->left) + height(root->right) + 1;
  pair<int, int> ans;
  ans.first = max(op1, max(op2, op3));             // returns diameters
  ans.second = max(left.second, right.second) + 1; // returns heights

  // int ans = max(op1, max(op2, op3));
  return ans;
}
int diameter(node *root) { return diaTree(root).first; }
