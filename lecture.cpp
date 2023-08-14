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

void levelOrder(Node *root)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

void sumAtKthLevel(Node *root, int k)
{
    queue<Node *> q;
    q.push(root);
    int lvl = 0;
    while (lvl < k)
    {

        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        lvl++:
    }

    int ans = 0;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        ans += curr->val;
    }

    cout << ans;
}

void preOrder(Node *root)
{

    if (root == NULL)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
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