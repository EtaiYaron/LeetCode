#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int maxPathSum(struct TreeNode* root) {
    int ans = 0;
    int x = root->val;
    int x1 = 0;
    int x2 = 0;
    if (x > 0) {
        ans += x;
    }
    if (root->left != NULL) {
        x1 = maxPathSum(root->left);
    }
    if (root->right != NULL) {
        x2 = maxPathSum(root->right);
    }
    if (x + x1 + x2 >= x + x1 && x + x1 + x2 >= x + x2 && x + x1 + x2 >= x1 && x + x1 + x2 >= x2 && x + x1 + x2 >= x)
    {
        ans = x + x1 + x2;
    }
    else if (x + x1 >= x + x2 && x + x1 >= x1 && x + x1 >= x2 && x + x1 >= x)
    {
        ans = x + x1;
    }
    else if (x + x2 >= x + x1 && x + x2 >= x1 && x + x2 >= x2 && x + x2 >= x)
    {
        ans = x + x2;
    }
    else if (x1 >= x2 && x1 >= x)
    {
        ans = x1;
    }
    else if (x2 >= x1 && x2 >= x)
    {
        ans = x2;
    }
    else
    {
        ans = 0;
    }
    return ans;
}

int main() {
    // Construct the tree: [-10,9,20,null,null,15,7]
    struct TreeNode node15 = { 15, NULL, NULL };
    struct TreeNode node7 = { 7, NULL, NULL };
    struct TreeNode node20 = { 20, &node15, &node7 };
    struct TreeNode node9 = { 9, NULL, NULL };
    struct TreeNode root = { -10, &node9, &node20 };

    int result = maxPathSum(&root);
    printf("Result: %d\n", result);
    printf("Expected: 42\n");

    if (result == 42) {
        printf("Test passed!\n");
    }
    else {
        printf("Test failed! Expected 42, got %d\n", result);
    }

    return 0;
}