struct TreeNode* increasingBST(struct TreeNode *root) {
    if (root == NULL) return NULL;
    struct TreeNode *head = NULL;
    struct TreeNode *prev = NULL;
    inOrder(root, &head, &prev);
    return head;
}


void inOrder(struct TreeNode *node, struct TreeNode **head, struct TreeNode **prev) {
    if (node == NULL) return;

    inOrder(node->left, head, prev);

    if (*prev == NULL) {
        *head = node;
    } else {
        (*prev)->right = node;
    }
    node->left = NULL;
    *prev = node;

    inOrder(node->right, head, prev);
    if (node->left) {
        inOrder(node->left, head, prev);
    }
    if (*prev == NULL) {
        *head = node; // node becomes the new root if prev is still NULL
    } else {
        (*prev)->right = node; // right child of prev set to current node
    }
    node->left = NULL; // the left child of the current node is always NULL
    *prev = node; // move prev to current node

    if (node->right) {
        inOrder(node->right, head, prev);
    }
}
