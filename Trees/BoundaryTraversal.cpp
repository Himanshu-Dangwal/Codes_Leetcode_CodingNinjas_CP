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

bool isBalanced(Node *root, int *height)
{

    if (root == NULL)
    {
        *height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    if (!isBalanced(root->left, &lh))
        return false;
    if (!isBalanced(root->right, &rh))
        return false;

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
    {
        return true;
    }

    return false;
}

bool isLeaf(Node *root)
{
    return (root->left == NULL && root->right == NULL);
}

void addLeftNodes(Node *root, vector<int> &ans)
{

    if (root == NULL)
        return;

    Node *curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->val);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addleafnodes(Node *root, vector<int> &ans)
{

    if (isLeaf(root))
    {
        ans.push_back(root->val);
        return;
    }

    addleafnodes(root->left, ans);
    addleafnodes(root->right, ans);
}

void addRightNodes(Node *root, vector<int> &ans)
{

    if (root == NULL)
        return;

    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->val);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

void boundaryTraversal(Node *root)
{

    vector<int> ans;
    if (root != NULL)
        ans.push_back(root->val);

    addLeftNodes(root, ans);
    addleafnodes(root, ans);
    addRightNodes(root, ans);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
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

    boundaryTraversal(root);
}