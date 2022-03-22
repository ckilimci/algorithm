#include <iostream>

using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : data(data) { }
};

void inorder(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main(int argc, char const *argv[])
{
    cout << "Given two binary trees, determine whether" << endl;
    cout << "they have the same inorder traversal" << endl;
    TreeNode *tree1 = new TreeNode(5);
    tree1->left = new TreeNode(3);
    tree1->left->left = new TreeNode(1);
    tree1->right = new TreeNode(7);
    tree1->right->left = new TreeNode(6);
    inorder(tree1);
    cout << endl;

    TreeNode *tree2 = new TreeNode(3);
    tree2->left = new TreeNode(1);
    tree2->right = new TreeNode(6);
    tree2->right->left = new TreeNode(5);
    tree2->right->right = new TreeNode(7);
    inorder(tree2);
    cout << endl;
    
    return 0;
}
