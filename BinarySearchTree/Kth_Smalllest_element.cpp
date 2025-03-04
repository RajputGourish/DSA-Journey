#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem lInk ->
            https://leetcode.com/problems/kth-smallest-element-in-a-bst
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

class solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        // Morris traversal
        int ans = INT_MIN;
        int cnt = 0;
        TreeNode *curr = root;
        while (curr != nullptr)
        {
            if (curr->left == nullptr)
            {
                cnt++;
                if (cnt == k)
                    ans = curr->val;
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right != nullptr && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == nullptr)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = nullptr;
                    cnt++;
                    if (cnt == k)
                        ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;

        // Time Complexity = O(N)
        // Space Complexity = O(1)
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    solution s;
    cout << s.kthSmallest(root, 2) << endl;

    return 0;
}