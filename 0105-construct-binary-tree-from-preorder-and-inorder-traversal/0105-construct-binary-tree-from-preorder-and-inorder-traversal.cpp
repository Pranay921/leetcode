/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
    int preIndex=0;
    TreeNode* compute(vector<int> &preorder,int left,int right){
        if(left>right) return nullptr;
        int rootVal=preorder[preIndex++];
        TreeNode* root=new TreeNode(rootVal);
        int index=mp[rootVal];
        root->left=compute(preorder,left,index-1);
        root->right=compute(preorder,index+1,right);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return compute(preorder,0,inorder.size()-1);
    }
};