int MAX;

int traverse(struct TreeNode* node) {
    int max, left, right, center = node->val;
    
    // If your left child exists, get a value from it.
    if(node->left != NULL)
        left = traverse(node->left);
    // If your right child exists, get a value from it.
    if(node->right != NULL)
        right = traverse(node->right);
    // If neither child exists, return yourself.
    if(node->left == NULL && node->right == NULL){
        return center;
    }
    // If only your right child exists, set the max to right
    else if(node->left == NULL)
        max = right;
    // If only your left child exists, set the max to left
    else if(node->right == NULL)
        max = left;
    // If both children exist, set the max to the higher value
    else{
        if(right > left)
            max = right;
        else
            max = left;
        /* Check if this subgraph including yourself is greater
         * than the current maximum path.
         */
        if((left + right + center) > MAX)
            MAX = left + right + center;
    }
    
    /* If the maximum of your children is greater than the global
     * maximum, update the global maximum.
     */
    if(max > MAX)
        MAX = max;
    /* If the maximum of your children is negative, there's no
     * sense including it upstream.
     */
    if(max < 0)
        return center;
    // Return the maximum of your children and yourself.
    return max + center;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSum(struct TreeNode* root) {
    MAX = root->val;
    
    // Just in case the root plus its greatest child path is the maximum
    int ret = traverse(root);
    if(ret > MAX)
        MAX = ret;
    
    return MAX;
}
