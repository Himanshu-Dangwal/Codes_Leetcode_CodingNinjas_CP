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

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void topView(Node *root, unordered_map<int, int> &mp, int idx)
{
    if (root == NULL)
        return;
    if (mp.find(idx) == mp.end())
        mp[idx] = root->val;

    if (root->left)
        topView(root->left, mp, idx - 1);
    if (root->right)
        topView(root->right, mp, idx + 1);
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

    int idx = 0;
    unordered_map<int, int> mp;
    topView(root, mp, idx);

    for (auto it : mp)
    {
        cout << it.second << " ";
    }
}