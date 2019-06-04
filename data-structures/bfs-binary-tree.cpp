#include <iostream>
#include <vector>

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int d) {
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

class BinaryTree {
	public:
	TreeNode* root;
	BinaryTree(int items[], int n) {
		root = assign(items, 0, n);
	}
	TreeNode* assign(int items[], int start, int end) {
		std::cout << "Assigning start:" << start << " end:" << end << std::endl;
		if (end <= start) return nullptr;
		int mid = (start + end) / 2;
		std::cout << "mid:" << mid << "data:" << items[mid] << std::endl;
		TreeNode* node = new TreeNode(items[mid]);
		node->left = assign(items, start, mid);
		node->right = assign(items, mid+1, end);
		return node;
	}
	void print(TreeNode* now) {
		if (nullptr == now) return;
		std::cout << "Printing.." << std::endl;
		std::cout << "Data:" << now->data << std::endl;
		print(now->left);
		print(now->right);
	}
	std::vector<std::vector<TreeNode*> > findLevels() {
		std::vector<std::vector<TreeNode*> > result;
		std::vector<TreeNode*> * current_level = new std::vector<TreeNode*>();
		int level = 0;
		current_level->push_back(root);
		result.push_back(*current_level);
		while(level<10) {
			current_level = new std::vector<TreeNode*>();
			for(auto node : result[level]) {
				if (nullptr != node->left)
					current_level->push_back(node->left);
				if (nullptr != node->right)
					current_level->push_back(node->right);
			}
			if (current_level->size() > 0) {
				result.push_back(*current_level);
			} else {
				break;
			}
			level++;
		}
		for(auto lvl : result) {
			for(auto node : lvl) {
				std::cout << node->data << " ";
			}
			std::cout << std::endl;
		}
		return result;
	}
};

int main() {
	std::cout << "Hello BFS Binary Tree" << std::endl;
	int items[] = { 10, 15, 20, 37, 40, 55, 70, 133 };
	int n = sizeof(items) / sizeof(items[0]);
	BinaryTree bt(items, n);
	bt.print(bt.root);
	bt.findLevels();
	return 0;
}
