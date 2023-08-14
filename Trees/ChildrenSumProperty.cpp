
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

void levelOrder(Node *root)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int sumAtKthLevel(Node *root, int k)
{

    queue<Node *> q;
    q.push(root);

    int level = 0;

    while (!q.empty() && level < k)
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            auto curr = q.front();
            q.pop();

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);

            level++;
        }
    }

    int sum = 0;
    while (!q.empty())
        sum += q.front()->val, q.pop();
    return sum;
}

void childrenSum(Node *root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
        child += root->left->val;
    if (root->right)
        child += root->right->val;

    if (root->val > child)
    {
        if (root->left)
            root->left->val = root->val;
        if (root->right)
            root->right->val = root->val;
    }
    else
    {
        root->val = child;
    }

    childrenSum(root->left);
    childrenSum(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->val;
    if (root->right)
        tot += root->right->val;

    if (root->left or root->right)
        root->val = tot;
    return;
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

    preOrder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    levelOrder(root);
    // cout << endl;
    // cout << sumAtKthLevel(root, 2);

    childrenSum(root);
    cout << endl;
    levelOrder(root);
}