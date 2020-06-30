// 83. 删除排序链表中的重复元素
// 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
// 示例 1:
// 输入: 1->1->2
// 输出: 1->2

// 示例 2:
// 输入: 1->1->2->3->3
// 输出: 1->2->3

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
};

class Solution2
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while (slow->next != nullptr)
        {
            if (slow->val == fast->val) // 相等
            {
                if (fast->next == nullptr) // 快指针后面没有元素
                {
                    slow->next = nullptr;
                }
                else // 快指针后面有元素
                {
                    slow->next = fast->next;
                    fast = fast->next;
                }
            }
            else // 不相等
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return head;
    }
};

class Solution3
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *curr = head;
    curr->next = new ListNode(1);
    curr = curr->next;
    curr->next = new ListNode(2);
    Solution solution;
    ListNode *res = solution.deleteDuplicates(head);
    return 0;
}