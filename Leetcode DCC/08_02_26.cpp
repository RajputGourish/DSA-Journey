#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link =>
                https://leetcode.com/problems/balanced-binary-tree/submissions/1912701724/?envType=daily-question&envId=2026-02-08
*/


class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

};


int maxdepth(TreeNode *root, int &ans)
{
    if (root == nullptr)
        return 0;
    int left = maxdepth(root->left, ans);
    int right = maxdepth(root->right, ans);
    if (abs(left - right) > 1)
        ans = 0;
    return 1 + max(left, right);
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    int ans = 1; // 1 = true
    maxdepth(root, ans);
    return ans;
}

int main()
{

    return 0;
}