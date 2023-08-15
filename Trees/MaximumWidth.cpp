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

#define PII pair<Node *, long long>

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

int widthOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<PII> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        int n = q.size();
        long long decreaseBy = q.front().second;
        long long first, second;
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front().first;
            long long idx = q.front().second - decreaseBy;

            if (i == 0)
                first = q.front().second;
            if (i == n - 1)
                second = q.front().second;

            q.pop();

            if (curr->left)
            {
                q.push(make_pair(curr->left, 2 * idx + 1));
            }

            if (curr->right)
            {
                q.push(make_pair(curr->right, 2 * idx + 2));
            }
        }

        if (second - first + 1 > ans)
            ans = second - first + 1;
    }
    return ans;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(7);

    cout << widthOfBinaryTree(root);
}