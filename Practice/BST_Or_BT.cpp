#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem link->
        https://leetcode.com/problems/validate-binary-search-tree
*/

void print(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
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
    void inorder(vector<int> &res, TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }

public:
    bool Brute_isValidBST(TreeNode *root)
    {
        vector<int> res;
        inorder(res, root);
        for (int i = 0; i < res.size() - 1; i++)
        {
            if (res[i] >= res[i + 1])
                return false;
        }
        return true;
        // Time Complexity = O(2N)
        // Space Complexity = O(2N)
    }

    bool IsvalidBst(TreeNode *root, long minval, long maxval)
    {
        if (root == nullptr)
            return true;
        if (root->val >= maxval || root->val <= minval)
            return false;
        return IsvalidBst(root->left, minval, root->val) && IsvalidBst(root->right, root->val, maxval);
        return true;
    }
    bool optimal_isValidBST(TreeNode *root)
    {
        return IsvalidBst(root, LONG_MIN, LONG_MAX);
        // Time Complexity = O(N)
        // Space Complexity = O(N)
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    // root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    Solution s;
    cout << s.Brute_isValidBST(root) << endl;
    cout << s.optimal_isValidBST(root) << endl;

    return 0;
}