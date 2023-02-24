long long findMaxScore(Node* root)
    {
        if(!root)
            return 0ll;
        long long l = findMaxScore(root->left);
        long long r = findMaxScore(root->right);
        return root->data * max(1ll,max(l,r));
    }