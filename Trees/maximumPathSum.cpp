

// https://drive.google.com/file/d/1kiGIBXHztMA-ECs1sOkiKj4ojsnqGLpR/view?usp=drivesdk

#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;

    Node(int x)
    {
        this->val = x;
        left = right = NULL;
    }
};

int getBest(TreeNode *root, int &ans)
{

    if (root == nullptr)
        return 0;

    int left = getBest(root->left, ans);
    int right = getBest(root->right, ans);

    int NodeMax = max(max(root->val, left + root->val + right), max(left + root->val, right + root->val));

    ans = max(ans, NodeMax);

    return max(root->val, max(left + root->val, right + root->val));
}

int maxPathSum(TreeNode *root)
{

    int ans = INT_MIN;

    getBest(root, ans);
    return ans;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
}