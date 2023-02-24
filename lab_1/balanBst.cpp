#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void inorder(Node* root, vector<int> &in)
{
     inorder(root->left,in);
     in.push_back(root->data);
     inorder(root->right,in);

}
Node *sortedToBST(int arr[], int st, int end)
{
    if (st > end)
    {
        return NULL;
    }

    int mid = (st + end) / 2;

    Node *root = new Node(arr[mid]);

    root->left = sortedToBST(arr, st, mid - 1);

    root->right = sortedToBST(arr, mid + 1, end);

    return root;
}



Node* balancedBST(Node* root)
{
    vector<int> inorderVal;

    inorder(root,inorderVal);
}