#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 21. 合并两个有序链表
// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
// 示例：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                curr->next = new ListNode(l1->val);
                curr = curr->next;
                l1 = l1->next;
            }
            else if (l1->val >= l2->val)
            {
                curr->next = new ListNode(l2->val);
                curr = curr->next;
                l2 = l2->next;
            }
        }
        while (l1 != nullptr)
        {
            curr->next = new ListNode(l1->val);
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            curr->next = new ListNode(l2->val);
            curr = curr->next;
            l2 = l2->next;
        }
        return dummy->next;
    }
};

class Solution2
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        vector<int> vec;
        while (l1 != nullptr)
        {
            vec.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            vec.push_back(l2->val);
            l2 = l2->next;
        }
        sort(vec.begin(), vec.end());

        ListNode *curr = nullptr;
        ListNode **list = &curr;
        for (auto i : vec)
        {
            curr = new ListNode(i);
            curr = curr->next;
        }
        return *list;
    }
};
class Solution3
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        vector<int> vec;
        while (l1 != nullptr)
        {
            vec.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            vec.push_back(l2->val);
            l2 = l2->next;
        }
        sort(vec.begin(), vec.end());

        ListNode *list = new ListNode(0);
        ListNode *curr = list;
        for (auto i : vec)
        {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
        return list->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *ptr1 = l1;
    ptr1->next = new ListNode(2);
    ptr1 = ptr1->next;
    ptr1->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    ListNode *ptr2 = l2;
    ptr2->next = new ListNode(3);
    ptr2 = ptr2->next;
    ptr2->next = new ListNode(4);

    // Solution slv;
    // ListNode *res = slv.mergeTwoLists(l1, l2);
    Solution slv3;
    ListNode *res3 = slv3.mergeTwoLists(l1, l2);
    return 0;
}