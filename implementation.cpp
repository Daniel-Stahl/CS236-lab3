#include "header.hpp"
int BST::height(BTreeNode *t) {
    if (t == nullptr) {
        return 0;
    } else {
        int left = height(t->left);
        int right = height(t->right);
        
        return 1 + max(left, right);
    }
}

void BST::insert(double x) {
    BTreeNode* root = tree;
    bool nodeEmpty = true;
    
    while (nodeEmpty) {
        if (tree == NULL) {
            tree = new BTreeNode(x, NULL, NULL);
            nodeEmpty = false;
        } else if(x < root->value) {
            if (root->left == NULL) {
                root->left = new BTreeNode(x, NULL, NULL);
                nodeEmpty = false;
            } else {
                root = root->left;
            }
        } else if(x >= root->value) {
            if (root->right == NULL) {
                root->right = new BTreeNode(x, NULL, NULL);
                nodeEmpty = false;
            } else {
                root = root->right;
            }
        }
    }
}

void BST::inorder(vector<double> & v, BTreeNode *t) {
    
    
    // Cout in order
}


