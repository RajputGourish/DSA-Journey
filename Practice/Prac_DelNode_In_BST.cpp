#include <iostream>
using namespace std;

/*
    Problem link ->
        https://leetcode.com/problems/delete-node-in-a-bst/
*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    TreeNode *BrutedeleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->val == key)
                break;
            prev = curr;
            if (curr->val > key)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // check key is available or not
        if (!curr)
            return root;

        if (prev == nullptr)
        {
            if (!curr->left)
                return curr->right;
            else if (!curr->right)
                return curr->left;
        }
        else
        {
            if (!curr->left)
            {
                if (prev->left == curr)
                    prev->left = curr->right;
                else
                    prev->right = curr->right;

                return root;
            }
            else if (!curr->right)
            {
                if (prev->left == curr)
                    prev->left = curr->left;
                else
                    prev->right = curr->left;

                return root;
            }
        }

        // not left null || not right null

        prev = curr;
        TreeNode *temp = curr->right;
        while (temp->right)
        {
            prev = temp;
            temp = temp->right;
        }
        curr->val = temp->val;
        prev->right = temp->left;

        TreeNode *leftrightmost = curr->left;
        while (leftrightmost->right)
        {
            leftrightmost = leftrightmost->right;
        }
        leftrightmost->right = curr->right;
        curr->right = nullptr;

        return root;
    }

private:
    // optimal and clean code
    TreeNode *rightmost(TreeNode *root)
    {
        while (root->right)
        {
            root = root->right;
        }
        return root;
    }
    TreeNode *helper(TreeNode *curr)
    {
        if (!curr->left)
            return curr->right;
        else if (!curr->right)
            return curr->left;
        TreeNode *rightchild = curr->right;
        TreeNode *lastright = rightmost(curr->left);
        lastright->right = rightchild;
        return curr->left;
    }

public:
    TreeNode *OptimaldeleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root;
        if (root->val == key)
        {
            return helper(root);
        }
        TreeNode *dummy = root;
        while (root)
        {

            if (root->val > key)
            {
                if (root->left != nullptr && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                    root = root->left;
            }
            else
            {
                if (root->right != nullptr && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                    root = root->right;
            }
        }
        return dummy;
    }
};
int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right = new TreeNode(11);
    Solution s;
    TreeNode *ans1 = s.BrutedeleteNode(root, 5);
    cout << ans1->val << endl;
    TreeNode *ans2 = s.OptimaldeleteNode(root, 5);
    cout << ans2->val << endl;
    return 0;
}
