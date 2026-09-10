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

    void traverse(TreeNode* root, int& sum, int& cnt) {
        if(root) {
            cnt++;
            sum += root->val;
            traverse(root->left, sum, cnt);
            traverse(root->right, sum, cnt);
        }
    }

    void helper(TreeNode* root) {
        if(root) {
            int left , right, cnt;
            right = left = cnt = 0;

            traverse(root->left, left, cnt);
            traverse(root->right, right, cnt);
            
            if((left + right + root->val) / (cnt+1) == root->val) ans++;

            helper(root->left);
            helper(root->right);
        }
    }

    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};