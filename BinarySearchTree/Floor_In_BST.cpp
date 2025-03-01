#include <iostream>

using namespace std;

/*
    Problem link ->
            https://www.geeksforgeeks.org/problems/floor-in-bst/1?utm
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

int findFloor(TreeNode *root, int x)
{
    int floor = -1;
    while (root)
    {
        if (root->val == x)
        {
            floor = root->val;
            return floor;
        }
        if (root->val > x)
        {
            root = root->left;
        }
        else
        {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;

    // Time Complexity = O(logN)
    // Space Complexity = O(1)
}
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right = new TreeNode(11);
    cout << findFloor(root, 6) << endl;
    return 0;
}