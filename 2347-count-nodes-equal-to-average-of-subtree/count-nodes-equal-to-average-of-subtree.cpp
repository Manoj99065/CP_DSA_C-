class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        // Base case
        if (root == NULL) {
            return {0, 0};
        }

        // Get sum and count from left subtree
        pair<int, int> left = solve(root->left);

        // Get sum and count from right subtree
        pair<int, int> right = solve(root->right);

        // Calculate current subtree's sum and count
        int totalSum = left.first + right.first + root->val;
        int totalCount = left.second + right.second + 1;

        // Calculate average
        int average = totalSum / totalCount;

        // Check condition
        if (root->val == average) {
            ans++;
        }

        // Return sum and count to parent
        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};