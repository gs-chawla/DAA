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

bool searchBST(Node *root, int x)
{
    // recursive
    //     if (root == NULL)
    //     {
    //         return false;
    //     }

    //     if (root->data == x)
    //     {
    //         return true;
    //     }

    //     if (root->data > x)
    //     {
    //         return searchBST(root->left, x);
    //     }

    //     else
    //     {
    //         return searchBST(root->right, x);
    //     }
    //  return false;

    // iterative

    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }

        if (temp->data > x)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}
Node *minValue()
{
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *deletefromBST(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL and root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL and root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL and root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deletefromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {

        root->left = deletefromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deletefromBST(root->right, val);
        return root;
    }
}