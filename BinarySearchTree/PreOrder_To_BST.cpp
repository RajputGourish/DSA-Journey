#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem link:-
            https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal
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
    void Brute_HelpBstFromPreorder(TreeNode *root, vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            TreeNode *temp = root;
            while (temp)
            {
                if (temp->val > arr[i])
                {
                    if (temp->left)
                        temp = temp->left;
                    else
                    {
                        temp->left = new TreeNode(arr[i]);
                        break;
                    }
                }
                else
                {
                    if (temp->right)
                        temp = temp->right;
                    else
                    {
                        temp->right = new TreeNode(arr[i]);
                        break;
                    }
                }
            }
        }
    }

    TreeNode *build(vector<int> &arr, int &i, int bound)
    {
        if (i == arr.size() || arr[i] > bound)
            return nullptr;
        TreeNode *root = new TreeNode(arr[i++]);
        root->left = build(arr, i, root->val);
        root->right = build(arr, i, bound);
        return root;
    }

public:
    TreeNode *Brute_bstFromPreorder(vector<int> &arr)
    {
        if (arr.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(arr[0]);
        Brute_HelpBstFromPreorder(root, arr);
        return root;
        
        // Time Complexity = O(N x N)
        // Space Complexity = O(N -> stack space)
        
    }
    TreeNode *Optimal_bstFromPreorder(vector<int> &arr)
    {
        int i = 0;
        return build(arr, i, INT_MAX);
        
        // Time Complexity = O(3N > each node visit 3 times)
        // Space Complexity = O(N stack space)
        
    }
};
int main()
{
    vector<int> arr = {8, 5, 1, 7, 10, 12};
    Solution s;
    TreeNode *root = s.Brute_bstFromPreorder(arr);
    TreeNode *root1 = s.Optimal_bstFromPreorder(arr);
    inorder(root);
    cout << endl;
    inorder(root1);
    cout << endl;

    return 0;
}