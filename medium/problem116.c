void traverse(struct TreeLinkNode *parent, struct TreeLinkNode *node, int isLeft)
{
    if(node->left == NULL){
        if(!isLeft){
            if(parent->next == NULL){
                node->next = NULL;
            }
            else{
                node->next = parent->next->left;
            }
        }
        return;
    }
    if(isLeft){
        node->left->next = node->right;
        traverse(node, node->left, 1);
        traverse(node, node->right, 0);
    }
    else{
        node->left->next = node->right;
        if(parent->next == NULL){
            node->next = NULL;
        }
        else{
            node->next = parent->next->left;
        }
        traverse(node, node->left, 1);
        traverse(node, node->right, 0);
    }
}

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if(root == NULL)
        return;
    
    root->next = NULL;
    if(root->left == NULL)
        return;
    
    root->left->next = root->right;
    root->right->next = NULL;
    
    traverse(root, root->left, 1);
    traverse(root, root->right, 0);
}
