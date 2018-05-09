#include <iostream>
#include "common.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val_){ val = val_; left = right = NULL;}
};

// 94. Binary Tree Inorder Traversal
vector<int> inorderTraversal(TreeNode* root) {
   vector<int> inorder_t;

   if(!root)return inorder_t;

   vector<int> left = inorderTraversal(root->left);
   vector<int> right = inorderTraversal(root->right);
   left.push_back(root->val);
   left.insert(left.end(), right.begin(), right.end());
   return left;
}


int main (int argc, char** argv)
{



    return (0);
}
