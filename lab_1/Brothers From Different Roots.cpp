class Solution
{
    private:
    void inorder(Node* root, vector<int>& ans){
        if(root==NULL){
            return ;
        }
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> vec1;
        inorder(root1, vec1);
        vector<int> vec2;
        inorder(root2, vec2);
        
        //now find sum using 2 pointer Approach
        int i = 0;
        int j = vec2.size()-1;
        int count = 0;
        while(i < vec1.size() && j >= 0){
            int sum = vec1[i] + vec2[j];
            if(sum == x) count++, i++, j--;
            else if(sum < x) i++;
            else j--;
        }
        
        return count;
    }
};