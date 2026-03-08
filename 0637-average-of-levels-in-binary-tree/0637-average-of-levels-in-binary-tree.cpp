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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==nullptr) return {};
        vector<double> result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        double s=0,count=0;
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if(top!=nullptr){
                s+=top->val;
                count++;
                if(top->left!=nullptr) q.push(top->left);
            if(top->right!=nullptr) q.push(top->right);
            }
            else{
                result.push_back(s/count);
                s=0;
                count=0;
                if(!q.empty()) q.push(nullptr);
            }
            
        }
        return result;
    }
};