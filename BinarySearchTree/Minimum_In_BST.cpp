#include <iostream>
#include <climits>
using namespace std;
/*
    Problem link -
        https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1
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
    int minValue(TreeNode *root)
    {
        int min = INT_MAX;
        while (root != NULL)
        {
            min = root->val;
            root = root->left;
        }
        return min;
        
        // Time Complexity = O(logN)
        // Space Complexity = O(H)
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
    cout << s.minValue(root) << endl;

    return 0;
}
