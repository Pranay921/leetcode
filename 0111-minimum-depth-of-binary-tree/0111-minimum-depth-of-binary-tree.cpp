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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int levels=1; 
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if(top==nullptr){
                levels++;
                if(!q.empty()){
                    q.push(nullptr);
                    continue;
                }
            }
            if(top->left==nullptr && top->right==nullptr) return levels;
            if(top->left!=nullptr) q.push(top->left);
            if(top->right!=nullptr) q.push(top->right);
        }
        return levels;
    }
};