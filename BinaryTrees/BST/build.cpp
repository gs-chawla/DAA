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
Node *insertIntoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput()
{
}
void printLevelOrder(Node *root)
{
    // if (root == NULL)
    // {
    //     return;
    // }
    // map<int, vector<int>> m;
    // queue<pair<int, Node *>> q;
    // q.push({0, root});
    // while (!q.empty())
    // {
    //     pair<int, Node *> temp = q.front();
    //     int lvl = temp.first;
    //     Node *x = temp.second;

    //     m[lvl].push_back(x->data);
    //     if (x->left)
    //     {
    //         q.push({lvl + 1, x->left});
    //     }
    //     if (x->right)
    //     {
    //         q.push({lvl + 1, x->right});
    //     }
    //     q.pop();
    // }
    // for (auto i : m)
    // {
    //     vector<int> p = i.second;
    //     for (auto j : p)
    //     {
    //         cout << j << " ";
    //     }
        
    // }
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // separator

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL) // purana level traverse done
        {
            //cout << endl;
            if (!q.empty()) // queue still has child node
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
    
    printLevelOrder(root);
    return 0;
}
