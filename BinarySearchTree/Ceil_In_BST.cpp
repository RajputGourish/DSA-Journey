#include <iostream>

using namespace std;

/*
    Problem Link ->
            https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
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

int findCeil(TreeNode *root, int input)
{
    if (root == NULL)
        return -1;
    int ceil = -1;
    while (root)
    {
        if (input == root->val)
        {
            ceil = root->val;
            return ceil;
        }
        if (root->val > input)
        {
            ceil = root->val;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;

    // Time Complexity = O(logN)
    // Space Complexity = O(1)
}
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right = new TreeNode(11);
    cout << findCeil(root, 6) << endl;
    return 0;
}