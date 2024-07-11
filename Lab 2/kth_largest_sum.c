#define MAX(a, b) ((a) > (b) ? (a) : (b))

int treeHeight(struct TreeNode *root) {
    if (root == NULL) return 0;
    else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return MAX(leftHeight, rightHeight) + 1;
    }
}

long long levelSum(struct TreeNode *root, int level) {
    if (root == NULL) return 0;
    if (level == 0) return root->val;
    return levelSum(root->left, level - 1) + levelSum(root->right, level - 1);
}

long long kthLargestLevelSum(struct TreeNode *root, int k) {
    int height = treeHeight(root);
    if (k > height) {
        printf("Error\n");
        return -1;
    }
    long long sumArray[height];  // Assuming the height index array is correct
    for (int i = 0; i < height; i++) {
        sumArray[i] = levelSum(root, i);
    }
    // Bubble sort to find kth largest sum
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            if (sumArray[j] < sumArray[j + 1]) {
                long long temp = sumArray[j];
                sumArray[j] = sumArray[j + 1];
                sumArray[j + 1] = temp;
            }
        }
    }
    return sumArray[k - 1];
}
