// https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/shi-xian-ji-suan-qi
// 拆解复杂问题：实现计算器

// 我们最终要实现的计算器功能如下：
// 1、输入一个字符串，可以包含+ - * /、数字、括号以及空格，你的算法返回运算结构。
// 2、要符合运算法则，括号的优先级最高，先乘除后加减。
// 3、除号是整数除法，无论正负都向 0 取整（5/2=2，-5/2=-2）。
// 4、可以假定输入的算式一定合法，且计算过程不会出现整型溢出，不会出现除数为 0 的意外情况。
// 比如输入如下字符串，算法会返回 9：
// 3 * (2-6 /(3 -7))
// 可以看到，这就已经非常接近我们实际生活中使用的计算器了，虽然我们以前肯定都用过计算器，
// 但是如果简单思考一下其算法实现，就会大惊失色：
// 1、按照常理处理括号，要先计算最内层的括号，然后向外慢慢化简。这个过程我们手算都容易出错，
// 何况写成算法呢！
// 2、要做到先乘除，后加减，这一点教会小朋友还不算难，但教给计算机恐怕有点困难。
// 3、要处理空格。我们为了美观，习惯性在数字和运算符之间打个空格，但是计算之中得想办法忽略这些空格。
// 我记得很多大学数据结构的教材上，在讲栈这种数据结构的时候，应该都会用计算器举例，但是有一说一，
// 讲的真的垃圾，不知道多少未来的计算机科学家就被这种简单的数据结构劝退了。

// 那么本文就来聊聊怎么实现上述一个功能完备的计算器功能，关键在于层层拆解问题，化整为零，逐个击破，
// 相信这种思维方式能帮大家解决各种复杂问题。

#include <string>
#include <iostream>
#include <stack>
#include <cctype>
#include <list>

using namespace std;

class Calculator
{
public:
    int calc(string s)
    {
        list<char> lst;
        for (auto c : s)
        {
            lst.push_back(c);
        }
        return helper(lst);
    }

private:
    int helper(list<char> &lst) // 注意传引用
    {
        stack<int> stk;
        char sign = '+';
        int num = 0;
        while (lst.size())
        {
            char c = lst.front();
            lst.pop_front();
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            if (c == '(')
            {
                num = helper(lst);
            }
            if ((!isdigit(c) && c != ' ') || lst.size() == 0)
            {
                switch (sign)
                {
                    int prev;
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                case '*':
                    prev = stk.top();
                    stk.pop();
                    stk.push(prev * num);
                    break;
                case '/':
                    prev = stk.top();
                    stk.pop();
                    stk.push(prev / num);
                    break;
                }
                num = 0;
                sign = c;
            }
            if (c == ')')
                break;
        }
        int sum = 0;
        while (!stk.empty())
        {
            sum = sum + stk.top();
            stk.pop();
        }
        return sum;
    }
};

int main()
{
    Calculator calc;
    string s = "8-5+((5-2) + 1)*2 -3";
    cout << calc.calc(s) << endl;
    return 0;
}
