// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // k nodes reverse
        // remaining recursive call
        // head->next = function()

        ListNode *curr = head;
        int cnt = 0;

        while (curr != NULL)
        {

            curr = curr->next;

            if (cnt == k)
            {
                break;
            }

            cnt++;
        }

        if (cnt < k)
        {
            return head;
        }

        curr = head;
        cnt = 0;
        ListNode *prev = NULL;
        ListNode *next;

        // Loop to check the remaining length. If size < k return head

        // Reverse first k nodes

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
            head->next = reverseKGroup(curr, k);
        }

        return prev;
    }
};