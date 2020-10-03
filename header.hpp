#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class BTreeNode {
public:
    BTreeNode(double x, BTreeNode *leftp = NULL, BTreeNode *rightp = NULL) {
        value = x;
        left = leftp;
        right = rightp;
    }
              
private:
    double value;
    BTreeNode *left, *right;
    friend class BST;
};

class BST {
public:
    int height() { return height(tree); }
    void insert(double x);
    void inorder(vector<double> & v) { inorder(v, tree); }
    int leafCounter() { return leafCounter(tree); }
    void DestroyTree(BTreeNode* tNode);
    BST() { tree = NULL; }
    ~BST();
    
private:
    void inorder(vector<double>&tlist, BTreeNode *t);
    int leafCounter(BTreeNode *t);
    static int height(BTreeNode *t);
    BTreeNode *tree;
};
              
              
