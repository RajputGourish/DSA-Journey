#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;
/*
    Problem link->
                https://leetcode.com/problems/two-sum-iv-input-is-a-bst
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

class BSTiterator
{
    stack<TreeNode *> mystack;
    // reverse -> true = for before
    // reverse -> false = for next
    bool reverse = true;
    void pushall(TreeNode *node)
    {
        for (; node != NULL;)
        {
            mystack.push(node);
            if (reverse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }

public:
    BSTiterator(TreeNode *root, bool isreverse)
    {
        reverse = isreverse;
        pushall(root);
    }
    bool hashnxt()
    {
        return !mystack.empty();
    }
    int next()
    {
        TreeNode *tmpNode = mystack.top();
        mystack.pop();
        if (reverse == true)
        {
            pushall(tmpNode->left);
        }
        else
        {
            pushall(tmpNode->right);
        }
        return tmpNode->val;
    }
};
class Solution
{
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
            return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

public:
    bool Brute_findTarget(TreeNode *root, int k)
    {
        vector<int> arr;
        inorder(root, arr); // -> Sorted
        int i = 0;
        int j = arr.size() - 1;
        while (i < j)
        {
            if (arr[i] + arr[j] == k)
                return true;
            else if (arr[i] + arr[j] < k)
                i = i + 1;
            else
            {
                j = j - 1;
            }
        }
        return false;
    }
    bool Optimal_findTarget(TreeNode *root, int k)
    {
        if (root == nullptr)
            return false;
        BSTiterator l(root, false); // for next
        BSTiterator r(root, true);  // for before

        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
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
    cout << s.Brute_findTarget(root, 2) << endl;
    cout << s.Optimal_findTarget(root, 2) << endl;

    return 0;
}