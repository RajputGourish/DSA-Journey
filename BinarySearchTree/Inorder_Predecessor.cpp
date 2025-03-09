#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
    Problem link =>
        premium -> https://www.geeksforgeeks.org/problems/predecessor-and-successor/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
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
    TreeNode *Optimal_Predessor(TreeNode *root, int val)
    {
        TreeNode *Predeessor = nullptr;
        while (root)
        {
            if (root->val >= val)
            {
                root = root->left;
            }
            else
            {
                Predeessor = root;
                root = root->right;
            }
        }
        return Predeessor;

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
    cout << "Optimal = " << s.Optimal_Predessor(root, 8)->val << endl;

    return 0;
}