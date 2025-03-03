#include <iostream>
#include <vector>
using namespace std;

/*
    problem link :- 
            https://leetcode.com/problems/delete-node-in-a-bst/

*/
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};
void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
class Solution
{
    TreeNode *findLastRight(TreeNode *root)
    {
        if (root->right == nullptr)
            return root;
        return findLastRight(root->right);
    }
    TreeNode *helper(TreeNode *root)
    {
        if (root->left == nullptr)
        {
            return root->right;
        }
        else if (root->right == nullptr)
        {
            return root->left;
        }
        TreeNode *rightchild = root->right;
        TreeNode *Lastright = findLastRight(root->left);
        Lastright->right = rightchild;
        return root->left;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            return helper(root);
        }
        TreeNode *dummy = root;
        while (root != nullptr)
        {
            if (root->val > key)
            {
                if (root->left != nullptr && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if (root->right != nullptr && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return dummy;
        
        // Time Complexity = O(H)
        // Space Complexity = O(1)
        
    }
};
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(7);
    Solution s;

    TreeNode *ans = s.deleteNode(root, 3);
    inorder(ans);
    cout << endl;

    return 0;
}