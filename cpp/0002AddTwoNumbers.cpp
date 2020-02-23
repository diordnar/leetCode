#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0, sum, digit;
        ListNode *ret = new ListNode(0);
        ListNode *curr = ret;
        while (l1 != NULL || l2 != NULL)
        {
            int v1 = (l1 != NULL) ? l1->val : 0;
            int v2 = (l2 != NULL) ? l2->val : 0;
            sum = v1 + v2 + carry;
            carry = sum / 10;
            digit = sum % 10;
            curr->next = new ListNode(digit);
            curr = curr->next;
            if (l1 != NULL)
            {
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                l2 = l2->next;
            }
        }

        if (carry)
        {
            curr->next = new ListNode(carry);
        }

        return ret->next;
    }
};

int main()
{
    ListNode *list1 = new ListNode(2);
    ListNode *l1begin = list1;
    list1->next = new ListNode(4);
    list1 = list1->next;
    list1->next = new ListNode(3);

    ListNode *list2 = new ListNode(5);
    ListNode *l2begin = list2;
    list2->next = new ListNode(6);
    list2 = list2->next;
    list2->next = new ListNode(4);
    Solution solution;
    ListNode *tmp = solution.addTwoNumbers(l1begin, l2begin);

    while (tmp)
    {
        cout << tmp->val;
        if (tmp->next)
            cout << "->";
        tmp = tmp->next;
    }
    return 0;
}