#include <iostream>
#include <vector>
using namespace std;
/*
    Problem link ->
        https://leetcode.com/problems/insert-into-a-binary-search-tree/description
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

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);
        TreeNode *cur = root;
        while (true)
        {
            if (cur->val <= val)
            {
                if (cur->right != nullptr)
                    cur = cur->right;
                else
                {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (cur->left != nullptr)
                    cur = cur->left;
                else
                {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;

        // Time Complexity = O(logn)
        // Space Complexity = O(1)
    }
};
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    Solution s;

    TreeNode *ans = s.insertIntoBST(root, 5);

    // to show the element in inorder arrangement
    inorder(ans);
    cout << endl;

    return 0;
}