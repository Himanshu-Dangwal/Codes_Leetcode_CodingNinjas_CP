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

void morrisTraversal(Node *root)
{
    vector<int> inOrder;

    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inOrder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            Node *dummy = curr->left;

            while (dummy->right != NULL && dummy->right != curr)
            {
                dummy = dummy->right;
            }

            if (dummy->right == curr)
            {
                // If link exists, break the link, add element in the traversal, move right
                dummy->right = NULL;
                inOrder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // Create a link and move left
                dummy->right = curr;
                curr = curr->left;
            }
        }
    }

    for (int i = 0; i < inOrder.size(); i++)
        cout << inOrder[i] << " ";
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

    morrisTraversal(root);
}