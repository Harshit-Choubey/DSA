class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};