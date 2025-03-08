#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem link =>
        premium -> https://leetcode.com/problems/inorder-successor-in-bst
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
    int a = -1;
    void Inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
            return;
        Inorder(root->left, arr);
        arr.push_back(root->val);
        Inorder(root->right, arr);
    }
    void Better_Inorder(TreeNode *root, int val, int &ans)
    {
        if (root == nullptr)
            return;
        (Better_Inorder(root->left, val, ans));
        if (root->val > val)
        {
            if (a == -1)
            {
                ans = root->val;
                a = root->val;
            }
            // ans = root->val;
        }
        (Better_Inorder(root->right, val, ans));
    }

public:
    int Brute_successor(TreeNode *root, int val)
    {
        if (root == nullptr)
            return INT_MIN;
        vector<int> arr;
        Inorder(root, arr);
        int l = 0;
        int r = arr.size() - 1;
        int ans = INT_MIN;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] == val)
                ans = mid + 1;
            if (arr[mid] > val)
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return (ans == arr.size()) ? INT_MIN : arr[ans];

        // Time Complexity = O(N) + O(logN)
        // Space Complexity = O(N)
    }
    int Better_successor(TreeNode *root, int val)
    {
        int ans = INT_MIN;
        Better_Inorder(root, val, ans);
        return ans;
    }
    TreeNode *Optimal_successor(TreeNode *root, int val)
    {
        TreeNode *successor = nullptr;
        while (root)
        {
            if (root->val <= val)
            {
                root = root->right;
            }
            else
            {
                successor = root;
                root = root->left;
            }
        }
        return successor;

        // Time Complexity = O(H)
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
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(8);
    Solution s;
    cout << "Brute = " << s.Brute_successor(root, 2) << endl;
    cout << "Better = " << s.Better_successor(root, 2) << endl;
    cout << "Optimal = " << s.Optimal_successor(root, 2)->val << endl;

    return 0;
}