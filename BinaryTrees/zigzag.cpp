#include <bits/stdc++.h>
#include "binaryTree.cpp"
using namespace std;
class Solution
{
public:
    vector<int> zigzag(node *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        queue<node *> q;
        q.push(root);

        bool leftToRight = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);

            for (int i = 0; i < size; i++)
            {
                node *frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                if (frontNode->left)
                    q.push(frontNode->left);

                if (frontNode->right)
                    q.push(frontNode->right);
            }
            // direction change
            leftToRight = !leftToRight;
            for (auto i : ans)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
