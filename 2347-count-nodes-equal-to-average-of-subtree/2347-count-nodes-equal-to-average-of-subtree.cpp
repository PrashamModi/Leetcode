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
    int ans = 0;
    pair<int, int> f(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }
        auto left = f(root->left);
        auto right = f(root->right);

        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;

        if(root->val == (sum / cnt)) {
            ans++;
        }
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};