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
    if (t == NULL)
        return;
    
    inorder(v, t->left);
    v.push_back(t->value);
    inorder(v, t->right);
}

int BST::leafCounter(BTreeNode *t) {
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 1;
    } else {
        return leafCounter(t->left) + leafCounter(t->right);
    }
}

void BST::DestroyTree(BTreeNode* tNode) {
    if (tNode == NULL) {
        return;
    }
    
    DestroyTree(tNode->left);
    DestroyTree(tNode->right);
    delete tNode;
}

BST::~BST() {
    DestroyTree(tree);
    tree = NULL;
}
