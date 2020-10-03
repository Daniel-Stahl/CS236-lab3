/*
Stahl, Daniel
CS236, Section #25704
Fall 2020
*/

#include "header.hpp"

int main() {
    BST Tree;
    vector<double> numsInorder;
    string input;
    double num = 0;
    
    cout << "This program allows you to insert some numbers in binary search tree.\n" << "It prints out the nubers in the tree inorder.\n" << "It computes and prints the number of leaves in the tree.\n" << "and the height of the tree.\n" << "Enter 10 numbers: ";
    
    getline(cin, input);
    istringstream userInput(input);
    
    while (userInput >> num) {
        Tree.insert(num);
    }
    
    Tree.inorder(numsInorder);
    cout << "\nThe items in the tree in inorder are:\n";
    for (int x = 0; x < numsInorder.size(); x++) {
        cout << numsInorder.at(x) << " ";
    }
    
    cout << "\nThe height of the tree is " << Tree.height() << "\n\nThe number of leaves is " << Tree.leafCounter() << endl;
}
