#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
    public:
    TreeNode(int data) : data(data) {};
    int data;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class BinaryTree {
    // Helper function to insert
    // Note that node is getting by referance!
    void insert(TreeNode * &node, int data) {
        if (node == nullptr) {
            cout << "data=" << data << endl;
            node = new TreeNode(data);
        } else {
            if (data < node->data) {
                cout << "left ";
                insert(node->left, data);
            } else {
                cout << "right ";
                insert(node->right, data);
            }
        }
    }
    bool isBST(TreeNode *node) {
        if (node == nullptr) {
            return true;
        }
        bool result = true;
        if (node->left != nullptr) {
            result = (node->left->data < node->data && isBST(node->left));
        }
        if (result && node->right != nullptr) {
            result = (node->right->data > node->data && isBST(node->right));
        }
        return result;
    }
    public:
    TreeNode * head;
    BinaryTree(int data) {
        head = new TreeNode(data);
    }
    void insert(int data) {
        insert(head, data);
    }
    void level_order_tracersal() {
        cout << "level_order_tracersal: " << endl;
        TreeNode * node = head;
        queue<TreeNode *> current;
        queue<TreeNode *> next;
        current.push(node);
        while (current.size() > 0)
        {
            node = current.front();
            current.pop();
            cout << " " << node->data;
            if (node->left != nullptr) {
                next.push(node->left);
            }
            if (node->right != nullptr) {
                next.push(node->right);
            }
            if (current.size() == 0) {
                cout << ";";
                while (next.size() > 0) {
                    current.push(next.front());
                    next.pop();
                }
            }
        }
        cout << endl;
    }
    bool isBST() {
        return isBST(head);
    }
};

int main(int argc, char const *argv[])
{
    cout << "Given the root of a binary tree, display the node values at each level." << endl;
    BinaryTree * tree = new BinaryTree(100);
    tree->insert(50);
    tree->insert(75);
    tree->insert(25);
    tree->insert(200);
    tree->insert(350);
    tree->insert(90);

    // 50 becomes 80
    tree->head->left->data = 80;

    tree->level_order_tracersal();

    if (tree->isBST()) {
        cout << "This is a BST" << endl;
    } else {
        cout << "This is NOT a BST" << endl;
    }
    return 0;
}
