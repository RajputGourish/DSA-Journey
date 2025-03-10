#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;
/*
    Problem link->
            https://leetcode.com/problems/binary-search-tree-iterator
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
class BSTIteratorBrute
{
    vector<int> arr;
    int size;
    int i;

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

public:
    BSTIteratorBrute(TreeNode *root)
    {
        inorder(root);
        size = arr.size();
        i = -1;
    }

    int next()
    {
        return arr[++i];
    }

    bool hasNext()
    {
        return (i + 1 < size);
    }
};

class BSTIterator
{
    stack<TreeNode *> mystack;
    void pushall(TreeNode *node)
    {
        for (; node != nullptr; mystack.push(node), node = node->left)
            ;
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushall(root);
    }

    int next()
    {
        TreeNode *node = mystack.top();
        mystack.pop();
        pushall(node->right);
        return node->val;
    }

    bool hasNext()
    {
        return !mystack.empty();
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

    BSTIteratorBrute a(root);
    cout << a.next() << endl;
    BSTIterator a(root);
    cout << a.next() << endl;

    return 0;
}