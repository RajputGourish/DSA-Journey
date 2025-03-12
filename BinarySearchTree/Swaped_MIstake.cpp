#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem link->
            https://leetcode.com/problems/recover-binary-search-tree
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

class SolutionBrute
{
public:
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
            return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    void Brute_recoverTree(TreeNode *root)
    {
        vector<int> arr;
        inorder(root, arr);
        sort(arr.begin(), arr.end());
        int i = 0;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (true)
        {
            if (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;
                else
                {
                    node = st.top();
                    st.pop();
                    if (node->val != arr[i])
                        node->val = arr[i];
                    i++;
                    node = node->right;
                }
            }
        }
    }
};
class Solution
{
    TreeNode *middle;
    TreeNode *first;
    TreeNode *last;
    TreeNode *prev;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        if (prev != NULL && (root->val < prev->val))
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        middle = first = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
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
    SolutionBrute s;
    vector<int> before;
    s.inorder(root, before);
    cout << "Before swapped" << endl;

    // print(before);
    // s.Brute_recoverTree(root);
    // vector<int> after;
    // s.inorder(root, after);
    // cout << "After swapped" << endl;
    // print(after);

    return 0;
}