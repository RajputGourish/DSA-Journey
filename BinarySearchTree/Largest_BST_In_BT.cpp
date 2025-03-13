#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
    Problem Link-
        https://www.geeksforgeeks.org/problems/largest-bst/1
*/
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
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
class NodeValue
{
public:
    int minNode;
    int maxNode;
    int maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
class Solution
{
private:
    NodeValue largestBstHelper(TreeNode *root)
    {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = largestBstHelper(root->left);
        auto right = largestBstHelper(root->right);

        if (left.maxNode < root->val && root->val < right.minNode)
        {
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBst(TreeNode *root)
    {
        return largestBstHelper(root).maxSize;
    }
};
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(8);
    return 0;
}