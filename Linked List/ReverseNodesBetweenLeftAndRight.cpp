/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseK(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;

        int cnt = 0;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *stay = head;
        ListNode *next;

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
            stay->next = curr;
        }

        return prev;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        if (right - left == 0)
            return head;

        if (left == 1)
        {
            ListNode *curr = head;
            ListNode *prev = NULL;
            ListNode *next;
            ListNode *stay = head;

            int cnt = 1;

            while (curr != NULL && cnt <= right)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;

                cnt++;
            }

            if (curr != NULL)
            {
                stay->next = curr;
            }

            return prev;
        }

        int cnt = 1;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *stay = head;
        while (cnt < left)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = reverseK(curr, right - left + 1);
        return stay;
    }
};
