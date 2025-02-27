#include <iostream>

using namespace std;

// Problem-Link ->  https://leetcode.com/problems/search-in-a-binary-search-tree

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
class Solution
{
public:
    TreeNode *Recursive_searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val)
            return root;
        if (root->val > val)
        {
            return Recursive_searchBST(root->left, val);
        }
        else
        {
            return Recursive_searchBST(root->right, val);
        }

        // Time Complexity = O(logN)
        // Space Complexity = O(H)
    }
    TreeNode *Iterative_searchBST(TreeNode *root, int val)
    {
        while (root != nullptr && root->val != val)
        {
            root = val > root->val ? root->right : root->left;
        }
        return root;

        // Time Complexity = O(logN)
        // Space Complexity = O(1)
    }
};
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);

    Solution s;
    TreeNode *res = s.Recursive_searchBST(root, 1);
    cout << res->val << endl;
    TreeNode *res1 = s.Iterative_searchBST(root, 1);
    cout << res1->val << endl;

    return 0;
}