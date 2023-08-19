#include "bits/stdc++.h"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

void display(ListNode *head)
{
    ListNode *curr = head;

    while (curr != NULL)
    {
        cout << curr->val;
        curr = curr->next;
    }

    cout << endl;
}

ListNode *subtract(ListNode *head1, ListNode *head2)
{

    ListNode *h1 = reverse(head1);
    ListNode *h2 = reverse(head2);

    // display(h1);
    // display(h2);

    int carry = 0;
    ListNode *ans = new ListNode();
    ListNode *curr = ans;

    while (h1 != NULL && h2 != NULL)
    {
        curr->next = new ListNode();
        curr = curr->next;
        h1->val = h1->val - carry;
        carry = 0;
        if (h1->val < h2->val)
        {
            carry = 1;
            h1->val = h1->val + 10;
            curr->val = h1->val - h2->val;
        }
        else
        {
            curr->val = h1->val - h2->val;
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    while (h1 != NULL)
    {
        if (h1->val > 0)
        {
            if (carry)
            {
                carry = 0;
                h1->val = h1->val - 1;

                if (h1->val > 1)
                    curr->next = new ListNode(h1->val);
                curr = curr->next;
            }
            else
            {
                curr->next = new ListNode(h1->val);
                curr = curr->next;
            }
        }
        else
        {
            if (carry == 0)
            {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
            else
            {
                curr->next = new ListNode(9);
                curr = curr->next;
            }
        }
        h1 = h1->next;
    }

    ListNode *sol = ans->next;
    ListNode *finalAns = reverse(sol);
    return finalAns;
}

int main()
{
    // ListNode *head1 = new ListNode(1);
    // head1->next = new ListNode(2);
    // head1->next->next = new ListNode(3);

    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(0);

    display(head1);

    // ListNode *head2 = new ListNode(6);
    // head2->next = new ListNode(6);

    ListNode *head2 = new ListNode(1);

    display(head2);

    ListNode *ans = subtract(head1, head2);
    display(ans);
}