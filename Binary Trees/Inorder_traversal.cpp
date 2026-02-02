#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left; 
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution {
private:
    void inOrder(TreeNode* root, vector<int> &arr){
		if(root == nullptr){
			return;
		}
		inOrder(root->left, arr);
		arr.push_back(root-> data);
		inOrder(root->right, arr);
	}
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inOrder(root, arr);

        return arr;
    }
};

int main()
{
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol = Solution();
    // Getting inorder traversal
    vector<int> result = sol.inorderTraversal(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}