
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
typedef long long ll;
#define MOD 1000000007
using namespace std;

class Node
{
public:
    Node *next;
    int val;

    Node(int val)
    {
        this->val = val;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    return;
}

void display(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void reverse(Node *&head)
{

    if (head == NULL)
        return;

    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    head = prev;
}

Node *reverseRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverseRecursive(head->next);
    head->next->next = head;

    head->next = NULL;

    return newHead;
}

Node *reverseK(Node *head, int k)
{

    if (head == NULL)
        return NULL;

    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    int cnt = 0;

    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;

        cnt++;
    }

    if (curr != NULL)
    {
        head->next = reverseK(curr, k);
    }

    return prev;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    display(head);

    // reverse(head); //Iterative

    // Node *newNode = reverseRecursive(head);
    // display(newNode);

    Node *newHead = reverseK(head, 2);
    display(newHead);

    // display(head);
    return 0;
}