#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem link ->
            https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
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

class Solution
{
public:
    TreeNode *Recursion_lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        int curr = root->val;
        if (curr < p->val && curr < q->val)
        {
            return Recursion_lowestCommonAncestor(root->right, p, q);
        }
        else if (curr > p->val && curr > q->val)
        {
            return Recursion_lowestCommonAncestor(root->left, p, q);
        }
        return root;

        // Time Complexity = O(LogN)
        // Space Complexity = O(H) ->recursive stack space
    }

    TreeNode *Itterative_lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        while (root)
        {
            int curr = root->val;
            if (curr < p->val && curr < q->val)
            {
                root = root->right;
            }
            else if (curr > p->val && curr > q->val)
            {
                root = root->left;
            }
            else
                return root;
        }
        return root;
        // Time Complexity = O(LogN)
        // Space Complexity = O(1)
    }
};
int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    Solution s;
    TreeNode *ans = s.Recursion_lowestCommonAncestor(root, root->left->left, root->left->right);
    TreeNode *ans2 = s.Itterative_lowestCommonAncestor(root, root->left->left, root->left->right);
    cout << "Recursive Ans = " << ans->val << endl;
    cout << "Itterative Ans = " << ans2->val << endl;

    return 0;
}