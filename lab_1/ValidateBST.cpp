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
bool isBST(Node* root, int min, int max)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data >= min and root->data <= max)
    {
        bool left  = isBST(root->left , min , root->data);
        bool right = isBST(root->right,root->data,max);
        return left and right;
    }
    else{
        return false;
    }
}
bool validate(Node* root)
{
    // if inorder is sorted , then true 

}