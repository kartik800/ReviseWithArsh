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
    int ans = 0;
     // int cnt = 0;
public:
    int averageOfSubtree(TreeNode* root) {
        // ans = 0;
        solve(root);
        return ans;
    }
    // O(n) solution using postorder
    pair<int, int> solve(TreeNode * root){
        if(root== NULL) return {0,0};
        
        auto left = solve(root->left);
        int l_sum = left.first;
        int l_cnt = left.second;
        
        auto right = solve(root->right);
        int r_sum = right.first;
        int r_cnt = right.second;
        
        int sum = root->val + l_sum + r_sum;
        int cnt = l_cnt + r_cnt +1;
        
        if(root->val == sum/cnt) ans++;
        return {sum,cnt};
    }
        // O(n^2) using preorder
//     void solve(TreeNode* root){
//         if(root == NULL) return;
//         cnt = 0;
//         int avg = (sum(root,cnt))/cnt;
//         if(avg == root->val) ans++;
//         solve(root->left);
//         solve(root->right);
//     }
    
//     int sum(TreeNode* root, int &cnt){
//         if(root== NULL) return 0;
//         cnt++;
//         int left = sum(root->left, cnt);
//         int right = sum(root->right,cnt);
//         return root->val + left + right;
//     }
};