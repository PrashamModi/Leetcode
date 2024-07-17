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
    TreeNode* f(TreeNode* root, set<int> &s, vector<TreeNode*> &ans){
        if(!root){
            return NULL;
        }
        
        root->left = f(root->left, s, ans);
        root->right =  f(root->right, s, ans);

        auto it = s.find(root->val);
        if(it != s.end()){
              if(root->left){
                  ans.push_back(root->left);
              }
              if(root->right){
                  ans.push_back(root->right);
              }
              return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s;
        for(auto it : to_delete){
            s.insert(it);
        }
        vector<TreeNode*> ans;
        f(root, s, ans);
        if(s.find(root->val) == s.end()){
            ans.push_back(root);
        }
        return ans;
    }
};