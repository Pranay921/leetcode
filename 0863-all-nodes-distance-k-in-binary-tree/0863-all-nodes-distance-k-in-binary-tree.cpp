/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void inOrder(TreeNode* root){
        if(root==nullptr) return;
        if(root->left!=nullptr) parent[root->left]=root;
        inOrder(root->left);
        if(root->right!=nullptr) parent[root->right]=root;
        inOrder(root->right);
    }
    void BFS(TreeNode* target,int k,vector<int> &result){
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        while(!q.empty()){
            int n=q.size();
            if(k==0) break;
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                //left
                if(curr->left!=nullptr && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                //right
                if(curr->right!=nullptr && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                //parent
                if(parent.count(curr) && !visited.count(parent[curr])){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            k--;
        }
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        inOrder(root);
        BFS(target,k,result);
        return result;
    }
};