#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

	vector<int> Inorder(TreeNode *root) {

		vector<int> inorder;
		TreeNode *curr = root;

		while (curr != NULL) {

			if (curr -> left == NULL) {

				inorder.push_back(curr -> val);
				curr = curr -> right;
			}
			else {

				TreeNode *prev = curr -> left;
				while (prev -> right && prev -> right != curr) {

					prev = prev -> right;
				}

				if (prev -> right == NULL) {

					prev -> right = curr;
					curr = curr -> left;
				}
				else {

					prev -> right = NULL;
					inorder.push_back(curr -> val);
					curr = curr -> right;
				}
			}
		}

		return inorder;
	}
};

int main() {

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->right->right = new TreeNode(6);

	Solution sol;

	vector<int> inorder = sol.Inorder(root);

	cout << "Binary Tree Morris Inorder Traversal: ";
	for (int i = 0; i < inorder.size(); i++) {
		cout << inorder[i] << " ";
	}
	cout << endl;

	return 0;
}
