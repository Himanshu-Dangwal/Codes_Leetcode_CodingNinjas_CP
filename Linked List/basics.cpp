
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

int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    display(head);

    reverse(head);
    display(head);
    return 0;
}