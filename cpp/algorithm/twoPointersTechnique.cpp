#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    Node() : val(0), next(nullptr)
    {
    }

public:
    Node *next;

private:
    int val;
};

// 快慢指针1：判定链表中是否含有环
bool hasCircle(Node *head)
{
    Node *fast, *slow;
    fast = slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/shuang-zhi-zhen-ji-qiao
// 快慢指针2：已知链表中含有环，返回这个环的起始位置
Node *findCircleStart(Node *head)
{
    Node *fast, *slow;
    fast = slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
// 快慢指针3: 寻找链表中点
Node *findMidNode(Node *head)
{
    Node *fast, *slow;
    fast = slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // 当链表的长度是奇数时，slow 恰巧停在中点位置；如果长度是偶数，slow 最终的位置是中间偏右
    return slow;
}

// 快慢指针4：寻找链表的倒数第 k 个元素, 链表长度大于K
Node *KthElementFromEnd(Node *head, int k)
{
    Node *fast, *slow;
    fast = slow = head;
    while (k-- > 0)
    {
        fast = fast->next;
    }
    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}
/************************************************************************************/
// 左右指针常用算法
// 左右指针1：二分查找
int binarySearch(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else
        {
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else // nums[mid] > target
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

// 左右指针2：两数之和
// 167. 两数之和 II - 输入有序数组
// 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

// 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

// 说明:

//     返回的下标值（index1 和 index2）不是从零开始的。
//     你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

// 示例:

// 输入: numbers = [2, 7, 11, 15], target = 9
// 输出: [1,2]
// 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0, right = numbers.size() - 1;
    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            return {left + 1, right + 1};
        }
        else
        {
            if (sum < target)
            {
                ++left;
            }
            else // sum > target
            {
                --right;
            }
        }
    }

    return {-1, -1};
}

// 左右指针3: 反转数组
void reverse(vector<int> &arr)
{
    int sz = arr.size();
    if (sz <= 1)
    {
        return;
    }
    int left = 0, right = sz - 1;
    while (left < right)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        ++left;
        --right;
    }
}
int main()
{
    return 0;
}